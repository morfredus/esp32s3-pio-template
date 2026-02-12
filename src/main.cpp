#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>

#include "board_config.h"
#include "config.h"
#include "config_constants.h"
#include "config_state.h"
#include "project_info.h"
#include "secrets.h"

// OLED
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);

// Neopixel
Adafruit_NeoPixel pixel(1, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// Web server
WebServer server(WEB_SERVER_PORT);

// --- Helpers couleurs Neopixel ---
enum class StatusColor {
    Idle,
    Scanning,
    Connecting,
    Connected,
    ErrorWifi,
    ErrorApp
};

void setStatusColor(StatusColor status) {
    uint32_t color = 0;

    switch (status) {
        case StatusColor::Idle:        color = pixel.Color(0, 0, 0); break;
        case StatusColor::Scanning:    color = pixel.Color(0, 0, 255); break;   // bleu
        case StatusColor::Connecting:  color = pixel.Color(255, 165, 0); break; // orange
        case StatusColor::Connected:   color = pixel.Color(0, 255, 0); break;   // vert
        case StatusColor::ErrorWifi:   color = pixel.Color(255, 0, 0); break;   // rouge
        case StatusColor::ErrorApp:    color = pixel.Color(255, 0, 255); break; // magenta
    }

    pixel.setPixelColor(0, color);
    pixel.show();
}

// --- OLED helpers ---

void drawSplashScreen() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 10);
    display.println("Template ESP32-S3");

    display.setCursor(0, 26);
    display.println("Demarrage...");

    display.display();
}

void drawWifiProgress(float progress) {
    // progress entre 0.0 et 1.0
    display.clearDisplay();

    // Zone jaune (haut) pour nom + version
    // Sur les OLED bi-color, la zone jaune est souvent en haut (ex: 16 px)
    // On y met juste un texte simple (blanc, mais physiquement jaune)
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.println(ProjectInfo::NAME.data());
    display.setCursor(0, 8);
    display.println(ProjectInfo::VERSION.data());

    // Barre de progression en dessous (zone blanche)
    int barX = 0;
    int barY = 24;
    int barW = OLED_WIDTH;
    int barH = 10;

    display.drawRect(barX, barY, barW, barH, SSD1306_WHITE);
    int fillW = (int)(barW * progress);
    display.fillRect(barX + 1, barY + 1, fillW - 2 > 0 ? fillW - 2 : 0, barH - 2, SSD1306_WHITE);

    display.setCursor(0, 40);
    display.println("Connexion WiFi...");

    display.display();
}

void drawMainScreen() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Zone jaune (haut) : nom + version
    display.setCursor(0, 0);
    display.println(ProjectInfo::NAME.data());
    display.setCursor(0, 8);
    display.println(ProjectInfo::VERSION.data());

    // Zone blanche : SSID + IP
    display.setCursor(0, 24);
    display.print("SSID: ");
    display.println(ConfigState::instance().ssid().c_str());

    display.setCursor(0, 36);
    display.print("IP: ");
    display.println(ConfigState::instance().ip().c_str());

    display.display();
}

// --- Web page handler ---

String getBoardInfoHtml() {
    String html;
    html.reserve(2048);

    html += F("<!DOCTYPE html><html><head><meta charset='utf-8'>");
    html += F("<meta name='viewport' content='width=device-width,initial-scale=1'>");
    html += F("<title>Template ESP32-S3</title>");
    html += F("<style>"
              "body{font-family:system-ui,Arial,sans-serif;background:#111;color:#eee;margin:0;padding:0;}"
              "header{background:#222;padding:1rem;text-align:center;}"
              "h1{margin:0;font-size:1.4rem;}"
              "main{padding:1rem;max-width:800px;margin:0 auto;}"
              ".card{background:#1e1e1e;border-radius:8px;padding:1rem;margin-bottom:1rem;box-shadow:0 2px 4px rgba(0,0,0,0.5);}"
              "table{width:100%;border-collapse:collapse;font-size:0.9rem;}"
              "td{padding:0.3rem 0.5rem;vertical-align:top;}"
              "td.label{color:#aaa;width:35%;}"
              "</style></head><body>");

    html += F("<header><h1>Template ESP32-S3</h1></header><main>");

    html += F("<div class='card'><h2>Projet</h2><table>");
    html += F("<tr><td class='label'>Nom</td><td>");
    html += ProjectInfo::NAME.data();
    html += F("</td></tr><tr><td class='label'>Version</td><td>");
    html += ProjectInfo::VERSION.data();
    html += F("</td></tr></table></div>");

    html += F("<div class='card'><h2>Connexion</h2><table>");
    html += F("<tr><td class='label'>SSID</td><td>");
    html += ConfigState::instance().ssid().c_str();
    html += F("</td></tr><tr><td class='label'>Adresse IP</td><td>");
    html += ConfigState::instance().ip().c_str();
    html += F("</td></tr></table></div>");

    html += F("<div class='card'><h2>Carte ESP32-S3</h2><table>");
    html += F("<tr><td class='label'>Flash</td><td>16 MB</td></tr>");
    html += F("<tr><td class='label'>PSRAM</td><td>");
    html += String(ESP.getPsramSize() / 1024);
    html += F(" KB</td></tr>");
    html += F("<tr><td class='label'>Heap libre</td><td>");
    html += String(ESP.getFreeHeap() / 1024);
    html += F(" KB</td></tr>");
    html += F("<tr><td class='label'>Chip revision</td><td>");
    html += String(ESP.getChipRevision());
    html += F("</td></tr>");
    html += F("</table></div>");

    html += F("</main></body></html>");
    return html;
}

void handleRoot() {
    server.send(200, "text/html; charset=utf-8", getBoardInfoHtml());
}

// --- WiFi connect ---

bool connectWifiWithProgress() {
    setStatusColor(StatusColor::Scanning);

    unsigned long start = millis();
    size_t currentIndex = 0;

    while (millis() - start < Config::WIFI_CONNECT_TIMEOUT_MS) {
        const WifiCredential& cred = WIFI_CREDENTIALS[currentIndex];

        WiFi.begin(cred.ssid, cred.password);
        setStatusColor(StatusColor::Connecting);

        unsigned long attemptStart = millis();
        while (WiFi.status() != WL_CONNECTED &&
               millis() - attemptStart < Config::WIFI_RETRY_DELAY_MS) {

            float globalProgress = float(millis() - start) / float(Config::WIFI_CONNECT_TIMEOUT_MS);
            if (globalProgress > 1.0f) globalProgress = 1.0f;
            drawWifiProgress(globalProgress);

            delay(100);
        }

        if (WiFi.status() == WL_CONNECTED) {
            ConfigState::instance().setSsid(cred.ssid);
            ConfigState::instance().setIp(WiFi.localIP().toString().c_str());
            setStatusColor(StatusColor::Connected);
            return true;
        }

        currentIndex = (currentIndex + 1) % WIFI_CREDENTIALS_COUNT;
    }

    setStatusColor(StatusColor::ErrorWifi);
    return false;
}

// --- setup / loop ---

void setup() {
    // Serial
    Serial.begin(115200);
    delay(100);

    // Neopixel
    pixel.begin();
    pixel.setBrightness(NEOPIXEL_BRIGHTNESS);
    setStatusColor(StatusColor::Idle);

    // I2C + OLED
    Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        setStatusColor(StatusColor::ErrorApp);
        while (true) {
            delay(1000);
        }
    }

    drawSplashScreen();
    delay(Config::SPLASH_SCREEN_MS);

    // WiFi
    WiFi.mode(WIFI_STA);
    bool ok = connectWifiWithProgress();

    if (!ok) {
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.setCursor(0, 0);
        display.println("Erreur WiFi");
        display.display();
        return;
    }

    drawMainScreen();

    // Web server
    server.on("/", handleRoot);
    server.begin();
}

void loop() {
    server.handleClient();
}

# Release v1.0.2 - Educational ESP32-S3 Template

---

## 🎓 Educational ESP32-S3 Template with Complete Beginner Documentation

This release marks the first stable version of our **educational ESP32-S3 template**, specifically designed for beginners who want to learn embedded development with C++ and PlatformIO.

---

## 🌟 What's Special About This Release?

### 📚 **Comprehensive Learning Documentation**

This project includes **over 3,000 lines** of detailed educational documentation, explaining every aspect of the code **line by line** as if you've never programmed in C++ before.

**Available in both English and French** in the `learning/` folder:

- **[00_introduction_cpp](learning/00_introduction_cpp.md)** - Introduction to C++ and ESP32 programming
- **[01_project_structure](learning/01_project_structure.md)** - Complete project architecture explanation
- **[02_modules_and_their_role](learning/02_modules_and_their_role.md)** - Detailed module analysis with code walkthrough
- **[03_concepts_cpp](learning/03_concepts_cpp.md)** - C++ concepts used (classes, references, namespaces, singleton, etc.)
- **[04_main_explained](learning/04_main_explained.md)** - Line-by-line analysis of main.cpp
- **[05_configuration](learning/05_configuration.md)** - Configuration files explained in detail

📖 **Start here**: [`learning/README.md`](learning/README.md) - Complete navigation guide with multiple learning paths

---

## ✨ Features & Capabilities

### 🔧 **Hardware Support**
- ✅ **ESP32-S3 DevKitC-1 N16R8** (16MB Flash, 8MB PSRAM)
- ✅ **Onboard NeoPixel RGB LED** - Visual status feedback
- ✅ **OLED Display (SSD1306 128x64)** - Status screens and information display
- ✅ **PSRAM Support** - Memory information and management

### 🌐 **WiFi Connectivity**
- ✅ **Multi-credential WiFi** - Try multiple networks automatically
- ✅ **Connection status feedback** - Visual (NeoPixel + OLED) and serial monitoring
- ✅ **Automatic reconnection** - Robust connection handling
- ✅ **Configurable via `secrets.h`** - Easy credential management

### 🌍 **Web Server**
- ✅ **Async Web Server** - Non-blocking, high-performance HTTP server
- ✅ **LittleFS File System** - Static file serving (HTML, CSS)
  - Homepage: `data/index.html`
  - Stylesheet: `data/style.css`
- ✅ **REST API Endpoint** - `/api/info` returns JSON with:
  - Project name and version
  - WiFi SSID and signal strength (RSSI)
  - IP address
  - Uptime and free memory
  - PSRAM information

### 📁 **Professional Project Structure**
- ✅ **Modular architecture** - Separate modules for each hardware component
- ✅ **Manager pattern** - WifiManager orchestrates WiFi operations
- ✅ **Utility headers** - Shared configuration and state management
- ✅ **Clean separation** - Hardware config, software config, and secrets

```
src/
├── main.cpp                    # Application entry point
├── modules/                    # Hardware modules
│   ├── neopixel_status/       # RGB LED control
│   ├── oled_display/          # OLED screen management
│   └── psram_info/            # PSRAM information
├── managers/                   # Orchestration managers
│   └── wifi_manager/          # WiFi connection handling
└── utils/                      # Utilities and configuration
    ├── config_constants.h     # Derived constants
    └── config_state.h         # Runtime state
```

### 📝 **Development Features**
- ✅ **Flexible logging system** - LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR macros
- ✅ **Automatic filesystem upload** - Pre-build script for LittleFS
- ✅ **USB CDC enabled** - Direct USB serial communication
- ✅ **C++17 standard** - Modern C++ features

---

## 📖 Documentation Structure

### For Users (Ready to Use)
- **[Getting Started Guide](docs/getting_started.md)** - Quick start for beginners
- **[User Guide](docs/user_guide.md)** - Features and usage
- **[Project Structure](docs/project_structure.md)** - Architecture overview

### For Learners (Deep Understanding)
- **[Learning Documentation](learning/README.md)** - Complete educational content
  - Progressive learning paths
  - Line-by-line code explanations
  - C++ concepts with everyday analogies
  - Technical choices justified
  - Practical examples

---

## 🚀 Quick Start

### Prerequisites
- VS Code with PlatformIO extension
- ESP32-S3 board with USB drivers
- USB cable (data-capable)

### Installation
```bash
# Clone the repository
git clone https://github.com/morfredus/Template-ESP32-S3--N16R8_PIO.git
cd Template-ESP32-S3--N16R8_PIO

# Configure WiFi credentials
cp include/secrets_example.h include/secrets.h
# Edit include/secrets.h with your WiFi credentials

# Build and upload firmware
pio run --target upload

# Build and upload filesystem
pio run --target buildfs
pio run --target uploadfs

# Monitor serial output
pio device monitor -b 115200
```

### First Run
1. Board connects to WiFi (watch NeoPixel color changes)
2. OLED displays connection status and IP address
3. Access web interface at `http://<ESP32_IP>`
4. View system info at `http://<ESP32_IP>/api/info`

---

## 🎯 Who Is This For?

- ✅ **Absolute beginners** who want to learn C++ and embedded development
- ✅ **Students** learning ESP32 and microcontroller programming
- ✅ **Developers** wanting a clean, professional project template
- ✅ **Teachers** looking for educational material with complete explanations
- ✅ **Makers** who want to understand, not just copy-paste code

---

## 🌍 Bilingual Support

All documentation is available in:
- 🇬🇧 **English** - `*.md` files
- 🇫🇷 **French** - `*_fr.md` files

This ensures accessibility for French-speaking learners while maintaining international reach.

---

## 📊 Project Highlights

| Metric | Value |
|--------|-------|
| Educational Documentation | 3,000+ lines |
| Documentation Files | 14 (7 EN + 7 FR) |
| Code Modules | 4 hardware modules + 1 manager |
| Programming Language | C++17 |
| Platform | PlatformIO |
| Framework | Arduino for ESP32 |
| License | MIT |

---

## 🔧 Technical Stack

- **Platform**: ESP32-S3 (Xtensa Dual-Core 240MHz)
- **Framework**: Arduino for ESP32
- **Web Server**: ESPAsyncWebServer
- **File System**: LittleFS
- **Display**: SSD1306 OLED (I2C)
- **LED**: NeoPixel (WS2812)
- **Libraries**:
  - Adafruit SSD1306 & GFX
  - Adafruit NeoPixel
  - ESPAsyncWebServer
  - AsyncTCP

---

## 🎓 Learning Philosophy

This project is built on educational principles:

1. **No assumed knowledge** - Start from zero
2. **Progressive complexity** - Build understanding step by step
3. **Real-world analogies** - Connect code to everyday concepts
4. **Complete explanations** - Never skip "obvious" details
5. **Professional patterns** - Learn industry best practices
6. **Hands-on examples** - Working code you can modify and experiment with

---

## 📦 What's Included in This Release

### Code & Configuration
- ✅ Complete working ESP32-S3 project
- ✅ Professional modular architecture
- ✅ Example web interface (HTML/CSS)
- ✅ Configuration templates

### Documentation
- ✅ 7 learning documents (EN + FR)
- ✅ 3 user guides (EN + FR)
- ✅ README with quick start
- ✅ CHANGELOG with version history

### Development Tools
- ✅ PlatformIO configuration
- ✅ Auto-filesystem script
- ✅ Example secrets file
- ✅ .gitignore for security

---

## 🚀 Getting Started with Learning

**New to C++ and ESP32?**

1. Start with [`learning/README.md`](learning/README.md) for navigation
2. Follow the **Beginner Path** (documents 00 → 05)
3. Open the source files alongside the documentation
4. Experiment by modifying values and observing effects
5. Build your own modules using the existing ones as templates

**Already know C++?**

- Jump directly to [`learning/01_project_structure.md`](learning/01_project_structure.md) for architecture
- Check [`learning/02_modules_and_their_role.md`](learning/02_modules_and_their_role.md) for module details
- Review [`learning/04_main_explained.md`](learning/04_main_explained.md) for the main application flow

---

## 🙏 Acknowledgments

This template uses excellent open-source libraries:
- Espressif ESP32 Arduino Core
- Adafruit sensor libraries
- ESPAsyncWebServer by me-no-dev

Special thanks to the ESP32 and Arduino communities for their documentation and support.

---

## 📄 License

MIT License - Free to use, modify, and distribute. See [LICENSE](LICENSE) for details.

---

## 🔗 Useful Links

- **Repository**: [GitHub - Template-ESP32-S3--N16R8_PIO](https://github.com/morfredus/Template-ESP32-S3--N16R8_PIO)
- **Documentation**: [`learning/README.md`](learning/README.md)
- **Quick Start**: [`docs/getting_started.md`](docs/getting_started.md)
- **User Guide**: [`docs/user_guide.md`](docs/user_guide.md)
- **Issues & Questions**: [GitHub Issues](https://github.com/morfredus/Template-ESP32-S3--N16R8_PIO/issues)

---

## 🎉 Get Started Today!

Download this release, follow the [Quick Start Guide](docs/getting_started.md), and begin your ESP32 learning journey!

Whether you're building your first IoT device or learning professional embedded development, this template provides a solid, well-documented foundation.

**Happy coding and learning! 🚀**

---

**Version**: 1.0.2  
**Release Date**: February 13, 2026  
**Minimum PlatformIO**: 6.0  
**Tested on**: ESP32-S3 DevKitC-1 N16R8

---

## 📋 Release Notes

### v1.0.2 - Initial Stable Release

**New Features**:
- ✅ Complete educational documentation (3,000+ lines, bilingual EN/FR)
- ✅ Professional modular architecture
- ✅ Full WiFi connectivity with multi-credential support
- ✅ Async web server with LittleFS filesystem
- ✅ OLED display status screens
- ✅ NeoPixel visual feedback
- ✅ REST API endpoint for system information
- ✅ PSRAM support and information display
- ✅ Flexible logging system
- ✅ Automatic filesystem upload script

**Documentation**:
- ✅ 7 comprehensive learning documents (EN + FR)
- ✅ 3 user guides (Getting Started, User Guide, Project Structure)
- ✅ Line-by-line code explanations
- ✅ C++ concepts tutorial
- ✅ Configuration guide
- ✅ README with badges and navigation

**Quality & Standards**:
- ✅ C++17 standard
- ✅ Clean separation of concerns
- ✅ Well-commented code
- ✅ Professional naming conventions
- ✅ Security-conscious (secrets separated)
- ✅ MIT License

---

## 📸 Screenshots

### OLED Display Screens
- WiFi connection status
- IP address display
- System information

### Web Interface
- Homepage at `http://<ESP32_IP>`
- System info API at `/api/info`

### NeoPixel Status Codes
- 🔵 **Blue** - Initializing
- 🟡 **Yellow** - Connecting to WiFi
- 🟢 **Green** - Connected successfully
- 🔴 **Red** - Connection failed / Error
- ⚫ **Off** - Idle / Low power

---

**Download this release and start learning embedded development the right way!** 📚🚀

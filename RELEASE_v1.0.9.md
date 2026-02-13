# Release v1.0.9 - Startup Logs Readability Update

Minimum valid version: **1.0.10**

---

## 🎯 Summary

Version **1.0.9** focuses on one practical improvement: keeping the serial monitor readable during startup while preserving the most useful project logs.

---

## ✨ What Changed in v1.0.9

### 🧾 Cleaner Serial Monitor Output
- Reduced default low-level system noise from WiFi/ESP internals.
- Kept project-level startup logs for key milestones:
  - startup
  - WiFi connection attempts and result
  - LittleFS mount status
  - HTTP server readiness

### ⚙️ Logging Configuration
- Build-time debug level adjusted to keep output concise by default.
- Runtime ESP log level aligned to `INFO` for daily development readability.
- Existing logging macros (`LOG_DEBUG`, `LOG_INFO`, `LOG_WARNING`, `LOG_ERROR`) remain unchanged.

---

## 👀 Expected Boot Output

You should still see important lines such as:
- `[main] Démarrage du système`
- `[wifi] Connexion Wi-Fi...`
- `[wifi] Connexion établie au SSID=...`
- `[fs] LittleFS monté avec succès`
- `[http] Serveur HTTP prêt sur http://<IP>:80`

---

## 🔎 Why This Update Matters

- Faster troubleshooting from cleaner logs.
- Less scrolling noise in PlatformIO serial monitor.
- Better beginner experience when following startup flow.

---

## 📦 Included Files in This Release

- Firmware/config update in `platformio.ini`.
- Logging runtime adjustment in `src/utils/logging.cpp`.
- Documentation updates in:
  - `CHANGELOG.md`
  - `CHANGELOG_fr.md`
  - `README.md`
  - `README_fr.md`

---

## 🚀 How to Validate Locally

```bash
pio run --target upload
pio device monitor -b 115200
```

If the serial port is busy, close any tool holding COM access and retry.

---

## 📄 Notes

This release keeps application behavior unchanged and only improves default logging readability.

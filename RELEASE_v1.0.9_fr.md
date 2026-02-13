# Release v1.0.9 - Amélioration de la Lisibilité des Logs de Démarrage

Version minimale valide : **1.0.10**

---

## 🎯 Résumé

La version **1.0.9** se concentre sur une amélioration pratique : garder le moniteur série lisible au démarrage tout en conservant les logs projet les plus utiles.

---

## ✨ Ce qui Change en v1.0.9

### 🧾 Sortie Série Plus Lisible
- Réduction du bruit système bas niveau (WiFi/ESP internes).
- Conservation des logs projet au démarrage pour les étapes clés :
  - démarrage
  - tentatives de connexion WiFi et résultat
  - état du montage LittleFS
  - disponibilité du serveur HTTP

### ⚙️ Configuration des Logs
- Niveau de debug en build ajusté pour une sortie plus concise par défaut.
- Niveau runtime ESP aligné sur `INFO` pour une meilleure lisibilité au quotidien.
- Les macros existantes (`LOG_DEBUG`, `LOG_INFO`, `LOG_WARNING`, `LOG_ERROR`) restent inchangées.

---

## 👀 Sortie de Boot Attendue

Tu dois toujours voir des lignes importantes comme :
- `[main] Démarrage du système`
- `[wifi] Connexion Wi-Fi...`
- `[wifi] Connexion établie au SSID=...`
- `[fs] LittleFS monté avec succès`
- `[http] Serveur HTTP prêt sur http://<IP>:80`

---

## 🔎 Pourquoi Cette Mise à Jour Est Utile

- Diagnostic plus rapide grâce à des logs plus propres.
- Moins de bruit dans le moniteur série PlatformIO.
- Meilleure expérience pour les débutants qui suivent le flux de démarrage.

---

## 📦 Fichiers Inclus dans Cette Release

- Mise à jour firmware/config dans `platformio.ini`.
- Ajustement du logging runtime dans `src/utils/logging.cpp`.
- Mises à jour de documentation dans :
  - `CHANGELOG.md`
  - `CHANGELOG_fr.md`
  - `README.md`
  - `README_fr.md`

---

## 🚀 Validation Locale

```bash
pio run --target upload
pio device monitor -b 115200
```

Si le port série est occupé, ferme l’outil qui tient le port COM puis relance.

---

## 📄 Note

Cette release ne change pas le comportement applicatif et améliore uniquement la lisibilité des logs par défaut.

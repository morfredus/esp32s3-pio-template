# Release v1.0.2 - Template ESP32-S3 Pédagogique

---

## 🎓 Template ESP32-S3 avec Documentation Complète pour Débutants

Cette release marque la première version stable de notre **template ESP32-S3 pédagogique**, spécialement conçu pour les débutants qui souhaitent apprendre le développement embarqué avec C++ et PlatformIO.

---

## 🌟 Qu'est-ce qui Rend Cette Release Spéciale ?

### 📚 **Documentation Didactique Complète**

Ce projet inclut **plus de 3 000 lignes** de documentation pédagogique détaillée, expliquant chaque aspect du code **ligne par ligne** comme si vous n'aviez jamais programmé en C++.

**Disponible en français et en anglais** dans le dossier `learning/` :

- **[00_introduction_cpp](learning/00_introduction_cpp_fr.md)** - Introduction au C++ et à la programmation ESP32
- **[01_structure_du_projet](learning/01_structure_du_projet_fr.md)** - Explication complète de l'architecture du projet
- **[02_modules_et_leur_role](learning/02_modules_et_leur_role_fr.md)** - Analyse détaillée des modules avec parcours du code
- **[03_concepts_cpp](learning/03_concepts_cpp_fr.md)** - Concepts C++ utilisés (classes, références, namespaces, singleton, etc.)
- **[04_main_explique](learning/04_main_explique_fr.md)** - Analyse ligne par ligne de main.cpp
- **[05_configuration](learning/05_configuration_fr.md)** - Fichiers de configuration expliqués en détail

📖 **Commencez ici** : [`learning/README_fr.md`](learning/README_fr.md) - Guide de navigation complet avec plusieurs parcours d'apprentissage

---

## ✨ Fonctionnalités & Capacités

### 🔧 **Support Matériel**
- ✅ **ESP32-S3 DevKitC-1 N16R8** (16MB Flash, 8MB PSRAM)
- ✅ **NeoPixel RGB intégré** - Retour visuel d'état
- ✅ **Écran OLED (SSD1306 128x64)** - Écrans d'état et affichage d'informations
- ✅ **Support PSRAM** - Informations et gestion de la mémoire

### 🌐 **Connectivité WiFi**
- ✅ **WiFi multi-identifiants** - Essaie automatiquement plusieurs réseaux
- ✅ **Retour d'état de connexion** - Visuel (NeoPixel + OLED) et moniteur série
- ✅ **Reconnexion automatique** - Gestion robuste de la connexion
- ✅ **Configurable via `secrets.h`** - Gestion facile des identifiants

### 🌍 **Serveur Web**
- ✅ **Serveur Web Asynchrone** - Serveur HTTP non-bloquant, haute performance
- ✅ **Système de Fichiers LittleFS** - Servir des fichiers statiques (HTML, CSS)
  - Page d'accueil : `data/index.html`
  - Feuille de style : `data/style.css`
- ✅ **Point d'API REST** - `/api/info` retourne un JSON avec :
  - Nom et version du projet
  - SSID WiFi et force du signal (RSSI)
  - Adresse IP
  - Temps de fonctionnement et mémoire libre
  - Informations PSRAM

### 📁 **Structure de Projet Professionnelle**
- ✅ **Architecture modulaire** - Modules séparés pour chaque composant matériel
- ✅ **Pattern Manager** - WifiManager orchestre les opérations WiFi
- ✅ **Headers utilitaires** - Configuration et gestion d'état partagées
- ✅ **Séparation claire** - Config matérielle, config logicielle et secrets

```
src/
├── main.cpp                    # Point d'entrée de l'application
├── modules/                    # Modules matériels
│   ├── neopixel_status/       # Contrôle LED RGB
│   ├── oled_display/          # Gestion écran OLED
│   └── psram_info/            # Informations PSRAM
├── managers/                   # Gestionnaires d'orchestration
│   └── wifi_manager/          # Gestion connexion WiFi
└── utils/                      # Utilitaires et configuration
    ├── config_constants.h     # Constantes dérivées
    └── config_state.h         # État d'exécution
```

### 📝 **Fonctionnalités de Développement**
- ✅ **Système de logging flexible** - Macros LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR
- ✅ **Upload automatique du système de fichiers** - Script pré-build pour LittleFS
- ✅ **USB CDC activé** - Communication série USB directe
- ✅ **Standard C++17** - Fonctionnalités C++ modernes

---

## 📖 Structure de la Documentation

### Pour les Utilisateurs (Prêt à l'Emploi)
- **[Guide de Démarrage](docs/getting_started_fr.md)** - Démarrage rapide pour débutants
- **[Guide Utilisateur](docs/user_guide_fr.md)** - Fonctionnalités et utilisation
- **[Structure du Projet](docs/project_structure_fr.md)** - Vue d'ensemble de l'architecture

### Pour les Apprenants (Compréhension Approfondie)
- **[Documentation Didactique](learning/README_fr.md)** - Contenu éducatif complet
  - Parcours d'apprentissage progressifs
  - Explications du code ligne par ligne
  - Concepts C++ avec analogies du quotidien
  - Choix techniques justifiés
  - Exemples pratiques

---

## 🚀 Démarrage Rapide

### Prérequis
- VS Code avec l'extension PlatformIO
- Carte ESP32-S3 avec pilotes USB
- Câble USB (compatible données)

### Installation
```bash
# Cloner le dépôt
git clone https://github.com/morfredus/Template-ESP32-S3--N16R8_PIO.git
cd Template-ESP32-S3--N16R8_PIO

# Configurer les identifiants WiFi
cp include/secrets_example.h include/secrets.h
# Éditer include/secrets.h avec vos identifiants WiFi

# Compiler et téléverser le firmware
pio run --target upload

# Compiler et téléverser le système de fichiers
pio run --target buildfs
pio run --target uploadfs

# Monitorer la sortie série
pio device monitor -b 115200
```

### Premier Lancement
1. La carte se connecte au WiFi (observez les changements de couleur du NeoPixel)
2. L'OLED affiche l'état de connexion et l'adresse IP
3. Accédez à l'interface web à `http://<IP_ESP32>`
4. Consultez les infos système à `http://<IP_ESP32>/api/info`

---

## 🎯 Pour Qui Est Ce Projet ?

- ✅ **Débutants complets** qui veulent apprendre le C++ et le développement embarqué
- ✅ **Étudiants** apprenant l'ESP32 et la programmation de microcontrôleurs
- ✅ **Développeurs** voulant un template de projet propre et professionnel
- ✅ **Enseignants** cherchant du matériel pédagogique avec explications complètes
- ✅ **Makers** qui veulent comprendre, pas seulement copier-coller du code

---

## 🌍 Support Bilingue

Toute la documentation est disponible en :
- 🇬🇧 **Anglais** - fichiers `*.md`
- 🇫🇷 **Français** - fichiers `*_fr.md`

Cela garantit l'accessibilité pour les apprenants francophones tout en maintenant une portée internationale.

---

## 📊 Points Forts du Projet

| Métrique | Valeur |
|----------|--------|
| Documentation Éducative | 3 000+ lignes |
| Fichiers de Documentation | 14 (7 EN + 7 FR) |
| Modules de Code | 4 modules matériels + 1 gestionnaire |
| Langage de Programmation | C++17 |
| Plateforme | PlatformIO |
| Framework | Arduino pour ESP32 |
| Licence | MIT |

---

## 🔧 Stack Technique

- **Plateforme** : ESP32-S3 (Xtensa Dual-Core 240MHz)
- **Framework** : Arduino pour ESP32
- **Serveur Web** : ESPAsyncWebServer
- **Système de Fichiers** : LittleFS
- **Écran** : OLED SSD1306 (I2C)
- **LED** : NeoPixel (WS2812)
- **Bibliothèques** :
  - Adafruit SSD1306 & GFX
  - Adafruit NeoPixel
  - ESPAsyncWebServer
  - AsyncTCP

---

## 🎓 Philosophie d'Apprentissage

Ce projet est construit sur des principes pédagogiques :

1. **Aucune connaissance présupposée** - Partir de zéro
2. **Complexité progressive** - Construire la compréhension étape par étape
3. **Analogies réelles** - Relier le code à des concepts quotidiens
4. **Explications complètes** - Ne jamais sauter les détails "évidents"
5. **Patterns professionnels** - Apprendre les meilleures pratiques de l'industrie
6. **Exemples pratiques** - Code fonctionnel que vous pouvez modifier et expérimenter

---

## 📦 Contenu de Cette Release

### Code & Configuration
- ✅ Projet ESP32-S3 complet et fonctionnel
- ✅ Architecture modulaire professionnelle
- ✅ Interface web d'exemple (HTML/CSS)
- ✅ Templates de configuration

### Documentation
- ✅ 7 documents d'apprentissage (EN + FR)
- ✅ 3 guides utilisateur (EN + FR)
- ✅ README avec démarrage rapide
- ✅ CHANGELOG avec historique des versions

### Outils de Développement
- ✅ Configuration PlatformIO
- ✅ Script auto-filesystem
- ✅ Fichier secrets d'exemple
- ✅ .gitignore pour la sécurité

---

## 🚀 Commencer l'Apprentissage

**Nouveau en C++ et ESP32 ?**

1. Commencez par [`learning/README_fr.md`](learning/README_fr.md) pour la navigation
2. Suivez le **Parcours Débutant** (documents 00 → 05)
3. Ouvrez les fichiers sources à côté de la documentation
4. Expérimentez en modifiant les valeurs et observant les effets
5. Créez vos propres modules en utilisant les existants comme templates

**Vous connaissez déjà le C++ ?**

- Allez directement à [`learning/01_structure_du_projet_fr.md`](learning/01_structure_du_projet_fr.md) pour l'architecture
- Consultez [`learning/02_modules_et_leur_role_fr.md`](learning/02_modules_et_leur_role_fr.md) pour les détails des modules
- Revoyez [`learning/04_main_explique_fr.md`](learning/04_main_explique_fr.md) pour le flux de l'application principale

---

## 🙏 Remerciements

Ce template utilise d'excellentes bibliothèques open-source :
- Espressif ESP32 Arduino Core
- Bibliothèques de capteurs Adafruit
- ESPAsyncWebServer par me-no-dev

Merci particulier aux communautés ESP32 et Arduino pour leur documentation et leur support.

---

## 📄 Licence

Licence MIT - Libre d'utilisation, de modification et de distribution. Voir [LICENSE](LICENSE) pour les détails.

---

## 🔗 Liens Utiles

- **Dépôt** : [GitHub - Template-ESP32-S3--N16R8_PIO](https://github.com/morfredus/Template-ESP32-S3--N16R8_PIO)
- **Documentation** : [`learning/README_fr.md`](learning/README_fr.md)
- **Démarrage Rapide** : [`docs/getting_started_fr.md`](docs/getting_started_fr.md)
- **Guide Utilisateur** : [`docs/user_guide_fr.md`](docs/user_guide_fr.md)
- **Problèmes & Questions** : [GitHub Issues](https://github.com/morfredus/Template-ESP32-S3--N16R8_PIO/issues)

---

## 🎉 Commencez Aujourd'hui !

Téléchargez cette release, suivez le [Guide de Démarrage](docs/getting_started_fr.md), et commencez votre voyage d'apprentissage ESP32 !

Que vous construisiez votre premier appareil IoT ou que vous appreniez le développement embarqué professionnel, ce template fournit une base solide et bien documentée.

**Bon codage et bon apprentissage ! 🚀**

---

**Version** : 1.0.2  
**Date de Release** : 13 février 2026  
**PlatformIO Minimum** : 6.0  
**Testé sur** : ESP32-S3 DevKitC-1 N16R8

---

## 📋 Notes de Release

### v1.0.2 - Release Stable Initiale

**Nouvelles Fonctionnalités** :
- ✅ Documentation éducative complète (3 000+ lignes, bilingue EN/FR)
- ✅ Architecture modulaire professionnelle
- ✅ Connectivité WiFi complète avec support multi-identifiants
- ✅ Serveur web asynchrone avec système de fichiers LittleFS
- ✅ Écrans d'état sur OLED
- ✅ Retour visuel NeoPixel
- ✅ Point d'API REST pour informations système
- ✅ Support et affichage des informations PSRAM
- ✅ Système de logging flexible
- ✅ Script d'upload automatique du système de fichiers

**Documentation** :
- ✅ 7 documents d'apprentissage complets (EN + FR)
- ✅ 3 guides utilisateur (Démarrage, Guide Utilisateur, Structure du Projet)
- ✅ Explications du code ligne par ligne
- ✅ Tutoriel sur les concepts C++
- ✅ Guide de configuration
- ✅ README avec badges et navigation

**Qualité & Standards** :
- ✅ Standard C++17
- ✅ Séparation claire des préoccupations
- ✅ Code bien commenté
- ✅ Conventions de nommage professionnelles
- ✅ Soucieux de la sécurité (secrets séparés)
- ✅ Licence MIT

---

## 📸 Captures d'Écran

### Écrans OLED
- État de connexion WiFi
- Affichage de l'adresse IP
- Informations système

### Interface Web
- Page d'accueil à `http://<IP_ESP32>`
- API d'infos système à `/api/info`

### Codes d'État NeoPixel
- 🔵 **Bleu** - Initialisation
- 🟡 **Jaune** - Connexion au WiFi
- 🟢 **Vert** - Connecté avec succès
- 🔴 **Rouge** - Échec de connexion / Erreur
- ⚫ **Éteint** - Inactif / Basse consommation

---

**Téléchargez cette release et commencez à apprendre le développement embarqué de la bonne façon !** 📚🚀

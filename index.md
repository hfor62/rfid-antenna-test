# 🐾 Catdoor Project Overview - Smart RFID Cat Access System

Welcome to the **Open Source RFID Catdoor Project**!  
This project helps you build a complete RFID-controlled cat door with cloud logging, user access control, and DIY 3D-printed parts.

---

## ✨ Project Highlights

- ✅ Fully Open Source (hardware + software)
- ✅ Works with animal FDX-B RFID tags (like vet chips)
- ✅ Uses ESP32 microcontroller (others possible)
- ✅ Optional OLED display and servo lock
- ✅ Sends tag events to Firebase Cloud
- ✅ Modular, step-by-step learning for DIY makers

---

## 🔄 How to Get Started

Explore the sections below to get up and running!

### 1. ✨ [Get your RFID and controller up and running](./RFID_Test.ino)
A minimal test sketch for checking your RFID reader, using a pre-built antenna and raw serial output.

### 2. ⚙️ [Print, Wind and Test your Catdoor Coil-Antenna](./ANTENNA.md)
How to 3D print the antenna base and wind a functional cat-sized antenna coil.

### 3. ☁️ [Connect your RFID to Firebase Cloud](./README.md)
Once your reader works, learn how to send events to a cloud backend using your unique device token.

---

## 🌍 Documentation & Files

- **[RFID_Test.ino](./RFID_Test.ino)** — Minimal sketch to test tag reading  
- **[hardware_config.h](./hardware_config.h)** — Pin and baud rate settings  
- **[ANTENNA.md](./ANTENNA.md)** — Guide for winding custom antenna  
- **[README.md](./README.md)** — Main documentation with examples and links

---

## 🎉 Coming Soon

- 🕹️ Servo locking code  
- 🗃️ Cloud configuration guide  
- 🎨 3D files for complete catdoor  
- 🎥 Assembly video + walkthrough  
- 📲 Optional mobile interface

Stay tuned!

---

## 🚀 Want to Join or Test?

We will soon invite testers to try the cloud-connected version of the cat door. You can:

- Build from scratch using your own hardware  
- Use just the antenna and RFID parts  
- Or follow step-by-step from the beginning

---

Made with ❤️ by [@hfor62](https://github.com/hfor62)

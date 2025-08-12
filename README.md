# 🐾 RFID Antenna Test - FDX-B Animal Tag Reader

This Arduino sketch is a **minimal test program** to verify correct wiring and functionality of your **FDX-B RFID reader** (e.g., animal tag reader used for cats, dogs, livestock, etc.).

## 📦 What This Project Includes

- **RFID\_Test.ino** – A minimal test sketch to read and display raw RFID data via serial.
- **hardware\_config.h** – Definitions for RX pin and baud rate (configurable).
- 📝 This README.md to guide you.

## 📡 Supported Hardware

This test has been verified with the following reader module:

> **FDX-B Animal Tag Reader Module** (e.g., "134.2kHz RFID Reader EM4305/TK4100 FDX-B ISO11784/85")

- Reads FDX-B tags (ear tags, implants, pet microchips)
- Output: **ASCII serial via 9600 baud**
- Logic level: 5V TTL (usually works with ESP32 3.3V RX)
- **Comes with matching antenna coil** (100x100 mm tuned loop)

📎 *Product link examples (as used in this project):*

1. [https://www.aliexpress.com/item/1005004799827387.html](https://www.aliexpress.com/item/1005004799827387.html)
2. [https://www.aliexpress.com/item/1005006121734097.html](https://www.aliexpress.com/item/1005006121734097.html)

⚠️ *Always start by testing with the included antenna before moving on to custom coils.*

👉 A separate document will be provided that explains how to wind your own coil, using the 3D-printed antenna form included in the cat-door project.

## ⚡ Power Considerations

- The reader operates best at **9V DC**, giving maximum read range.
- However, it can successfully read animal tags at **5V**, which makes it easier to power directly from an ESP32 board for initial testing.
- If you're using a microcontroller with **3.3V logic** (like ESP32 or ESP8266), connect the **RFID TX (yellow marked pin)** to the controller’s RX input. This TX is already 3.3V-compatible on many modules.

## 🧪 What the Sketch Does

The sketch reads raw ASCII data from the reader and:

- Detects a complete tag frame (starts with `0x02`, ends with `0x03`)
- Prints ASCII tag data
- Prints each byte as hexadecimal with position index

Output looks like this:

```
🔷 New tag detected:
RAW RFID ASCII: A2A57A9C424830110000000000
RAW RFID HEX:
0:41 1:32 2:41 3:35 4:37 5:41 ...
⏳ Waiting for next tag...
```

## ✅ Quick Start

1. Wire the RFID reader's TX pin to **GPIO 16** on your ESP32
2. Load `RFID_Test.ino` in Arduino IDE
3. Open Serial Monitor at **115200 baud**
4. Bring an animal tag close to the antenna
5. Observe output – no additional hardware needed

## 🔧 Configuration

Edit `hardware_config.h` if needed:

```cpp
#define RFID_RX 16         // GPIO connected to RFID TX
#define RFID_BAUD 9600     // Default baud rate for reader
```

Works on most **ESP32** boards. Can be adapted for **ESP8266** or **Arduino Uno** using `SoftwareSerial`.

## 🛠️ Next Steps

This sketch is designed as the **first step** in a modular DIY smart cat door project. Once verified, users can continue to:

- Add decoding logic (FDX-B country code, animal ID)
- Control servos to lock/unlock a cat door
- Display info on OLED or LCD
- Send tag data to Firebase Cloud (see other repositories)

👉 Start here. Confirm your reader works. Then build your cat's smart entrance! 🐱🚪


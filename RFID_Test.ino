// RFID_Test.ino
// Minimal RFID test sketch for FDX-B readers (e.g. animal tag readers)

#define RFID_RX 26     // Adjust as needed
#define RFID_BAUD 9600

HardwareSerial RFIDSerial(1);  // Use UART1 (for ESP32)

void setup() {
  Serial.begin(115200);
  RFIDSerial.begin(RFID_BAUD, SERIAL_8N1, RFID_RX, -1);  // RX only
  Serial.println("🧪 RFID Test Mode: Listening for tags...");
}

void loop() {
  static char buffer[64];
  static int pos = 0;
  static bool inFrame = false;

  while (RFIDSerial.available()) {
    char c = RFIDSerial.read();

    if (c == 0x02) { // STX
      pos = 0;
      inFrame = true;
      Serial.println("\n🔷 New tag detected:");
      continue;
    }

    if (c == 0x03 && inFrame) { // ETX
      buffer[pos] = '\0';
      inFrame = false;

      Serial.print("RAW RFID ASCII: ");
      Serial.println(buffer);

      Serial.println("RAW RFID HEX:");
      for (int i = 0; i < pos; i++) {
        Serial.printf("%d:%02X ", i, buffer[i]);
      }
      Serial.println();
      Serial.println("⏳ Waiting for next tag...");
      continue;
    }

    if (inFrame && pos < sizeof(buffer) - 1) {
      buffer[pos++] = c;
    }
  }
}

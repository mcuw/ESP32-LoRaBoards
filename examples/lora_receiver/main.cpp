#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <SPI.h>
#include <SD.h>

#include "LgLoraBoard.h"

static const char *TAG = "LgLoraReceiver";
LgLoraBoard board;

void setup() {
  Serial.begin(115200);
  Serial.println("LoRa Receiver");

  board.setupRadioBoard();
}

void loop() {
  int packetSize = board.hasRadio();
  if (packetSize) {
    byte data[packetSize];
    board.readRadioBytes(packetSize, data);

    Serial.print(F("Data:\t\t["));
    for (int i = 0; i < packetSize; i++) {
      Serial.printf("0x%02X", data[i]);
      if (i < packetSize - 1) Serial.print(", ");
    }
    Serial.println(F("]"));
  }
  
// #if defined(USE_SX1262) || defined(USE_SX1276)
//   if (receivedFlag) {
//     // reset flag
//     receivedFlag = false;
//     // you can read received data as an Arduino String
//     // str = "";
//     // int state = radio.readData(str);

//     // you can also read received data as byte array
//     byte byteArr[256];

//     int numBytes = radio.getPacketLength();
//     int state = radio.readData(byteArr, numBytes);

//     if (state == RADIOLIB_ERR_NONE) {
//       // packet was successfully received
//       Serial.println(F("Received packet!"));

//       // print data of the packet
//       Serial.print(F("Data:\t\t["));
//       // for (int i = 0; i < numBytes; i++) {
//       //   Serial.print((char)byteArr[i]);
//       // }
//       for (int i = 0; i < numBytes; i++) {
//         Serial.printf("0x%02X", byteArr[i]);
//         if (i < numBytes - 1) Serial.print(", ");
//       }
//       // Serial.print(str);
//       Serial.println(F("]"));

//       // print RSSI (Received Signal Strength Indicator)
//       Serial.print(F("RSSI:\t\t"));
//       Serial.print(radio.getRSSI());
//       Serial.println(F(" dBm"));

//       // print SNR (Signal-to-Noise Ratio)
//       Serial.print(F("SNR:\t\t"));
//       Serial.print(radio.getSNR());
//       Serial.println(F(" dB"));

//       // print frequency error
//       Serial.print(F("Frequency error:\t"));
//       Serial.print(radio.getFrequencyError());
//       Serial.println(F(" Hz"));

//     } else if (state == RADIOLIB_ERR_CRC_MISMATCH) {
//       // packet was received, but is malformed
//       Serial.println(F("CRC error!"));

//     } else {
//       // some other error occurred
//       Serial.print(F("Failed to receive data, code "));
//       Serial.println(state);
//     }
//   }
// #endif // USE_SX1262 || USE_SX1276


  delay(2);
}

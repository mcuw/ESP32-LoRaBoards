#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <SPI.h>
#include <SD.h>
#include <RadioLib.h> // https://jgromes.github.io/RadioLib/class_s_x1262.html
// https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series/blob/master/examples/TBeamFactory/TBeamFactory.ino
#include "LgLoraBoards.h"

// SX1262 radio = new Module(LORA_CS, LORA_IRQ, LORA_RST, LORA_IO2); // NSS, RST, DIO0
// counter to keep track of transmitted packets
int count = 0;

void setup() {
  Serial.begin(115200);

  Serial.println("LoRa Sender");

  setupRadioBoard();
}

void loop() {
  byte byteArr[] = {0x01, 0x23, 0x45, 0x56, 0x78, 0xAB, 0xCD, 0xEF};
  int state = transmitRadioBytes(8, byteArr);

  if (state == RADIOLIB_ERR_UNKNOWN) {
    Serial.println(F("Unknown error occurred!"));
  } else if (state == RADIOLIB_ERR_CHIP_NOT_FOUND) {
    Serial.println(F("LoRa radio not found!"));
  } else if (state == RADIOLIB_ERR_NONE) {
    // the packet was successfully transmitted
    Serial.println(F("success!"));

  } else if (state == RADIOLIB_ERR_PACKET_TOO_LONG) {
    // the supplied packet was longer than 256 bytes
    Serial.println(F("too long!"));

  } else if (state == RADIOLIB_ERR_TX_TIMEOUT) {
    // timeout occured while transmitting packet
    Serial.println(F("timeout!"));

  } else {
    // some other error occurred
    Serial.print(F("failed, code "));
    Serial.println(state);
  }

  // // you can transmit C-string or Arduino string up to
  // // 256 characters long
  // String str = "Hello World! #" + String(count++);
  // Serial.print(F("[SX1262] Transmitting packet ... "));
  // int state = radio.transmit(str);

  // // you can also transmit byte array up to 256 bytes long
  // /*
  //   byte byteArr[] = {0x01, 0x23, 0x45, 0x56, 0x78, 0xAB, 0xCD, 0xEF};
  //   int state = radio.transmit(byteArr, 8);
  // */

  // if (state == RADIOLIB_ERR_NONE) {
  //   // the packet was successfully transmitted
  //   Serial.println(F("success!"));

  // } else if (state == RADIOLIB_ERR_PACKET_TOO_LONG) {
  //   // the supplied packet was longer than 256 bytes
  //   Serial.println(F("too long!"));

  // } else if (state == RADIOLIB_ERR_TX_TIMEOUT) {
  //   // timeout occured while transmitting packet
  //   Serial.println(F("timeout!"));

  // } else {
  //   // some other error occurred
  //   Serial.print(F("failed, code "));
  //   Serial.println(state);

  // }

  delay(2000);
}

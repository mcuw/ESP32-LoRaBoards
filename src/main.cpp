#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <SPI.h>
#include <SD.h>
#include "LgLoraBoards.h"

void setup() {
  Serial.begin(115200);
  Serial.println("LoRa App");
  setupRadioBoard();
}

void loop() {
  delay(10000);
}

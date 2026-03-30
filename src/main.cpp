#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <SPI.h>
#include <SD.h>
#include "LgLoraBoard.h"

LgLoraBoard board;

void setup() {
  Serial.begin(115200);
  Serial.println("LoRa Application");
  board.setupRadioBoard();
}

void loop() {
  delay(10000);
}

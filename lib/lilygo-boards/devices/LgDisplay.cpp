#ifdef HAS_DISPLAY_SSD1306
#include <Arduino.h>
#include <Wire.h>
#include "config.h"
#include "LgDisplay.h"

#ifndef DISPLAY_MODEL
#include "SSD1306Wire.h"
#define DISPLAY_MODEL SSD1306Wire
#endif // DISPLAY_MODEL

static const char *TAG = "LgDisplay";

DISPLAY_MODEL display(DISPLAY_ADDR, OLED_SDA, OLED_SCL);

bool beginDisplay()
{
  ESP_LOGD(TAG, "beginDisplay");

  bool success = display.init();
  if (!success)
  {
    ESP_LOGE(TAG, "Failed to initialize display");
    return false;
  }

  display.flipScreenVertically();
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(display.getWidth() / 2, (display.getHeight() / 2) - 16, F("ESP32 LoRa"));
  display.display();

  return true;
}
#endif // HAS_DISPLAY_SSD1306

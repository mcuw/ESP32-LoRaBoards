#include <Arduino.h>

#ifdef HAS_DISPLAY
U8G2 *disp = NULL;

bool beginDisplay()
{
    Wire.beginTransmission(display_address);
    if (Wire.endTransmission() == 0) {
        disp = new DISPLAY_MODEL(U8G2_R0, U8X8_PIN_NONE);
        Serial.printf("Find Display model at 0x%X address\n", display_address);
        disp->begin();
        disp->clearBuffer();
        disp->setFont(u8g2_font_inb19_mr);
        disp->drawStr(0, 30, "LilyGo");
        disp->drawHLine(2, 35, 47);
        disp->drawHLine(3, 36, 47);
        disp->drawVLine(45, 32, 12);
        disp->drawVLine(46, 33, 12);
        disp->setFont(u8g2_font_inb19_mf);
        disp->drawStr(58, 60, "LoRa");
        disp->sendBuffer();
        disp->setFont(u8g2_font_fur11_tf);
        delay(3000);
        return true;
    }

    ESP_LOGE(TAG, "Warning: Failed to find Display at 0x%0X address\n", display_address);
    return false;
}
#endif // HAS_DISPLAY

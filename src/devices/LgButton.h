#ifndef LG_BUTTON_H
#define LG_BUTTON_H

#ifdef HAS_BUTTON
#include <OneButton.h>
#include "../types/LgButtonTypes.h"

class LgButton {
public:
    // initialization with config.h (BUTTON_PIN, BUTTON_ACTIVEHIGH and BUTTON_PULLUP)
    LgButton();
    virtual ~LgButton();

    // set up button with interrupt handlers for click, double click and long press
    // issue for T-Beam v0.7: if the button is configured to use GPIO38, it can't be used as an interrupt pin, so only click and double click interrupt will work, long press won't work. This is a hardware limitation of ESP32, not a software issue. To use long press, you need to change the button pin to a different GPIO that supports interrupts.
    void setupButton(callbackFunction onClickInterrupt, callbackFunction onDoubleClickInterrupt = nullptr, callbackFunction onLongPressInterrupt = nullptr);
    
    // optional: reconfigure the button with a new settings
    // mode: can be INPUT, INPUT_PULLUP
    void reconfigureButton(uint8_t pin, uint8_t mode = INPUT_PULLUP, bool activeLow = true);

private:
    static void buttonTick(void *pvParameters);

    OneButton* button;
    TaskHandle_t taskButtonHandle;
};
#endif // HAS_BUTTON
#endif // LG_BUTTON_H
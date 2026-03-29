#ifdef HAS_LED
static uint8_t ledState = LOW;
static const uint32_t debounceDelay = 50;
static uint32_t lastDebounceTime = 0;

void flashLed()
{
    if ((millis() - lastDebounceTime) > debounceDelay) {
        ledState = !ledState;
        if (ledState) {
            digitalWrite(BOARD_LED, LED_ON);
        } else {
            digitalWrite(BOARD_LED, !LED_ON);
        }
        lastDebounceTime = millis();
    }
}

#endif /* HAS_LED */
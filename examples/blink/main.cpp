#include <Arduino.h>

unsigned long previousMillis = 0;
const long interval = 100; // Blink-interval in milliseconds
bool ledState = LOW;

void setup() {
  Serial.begin(115200);
  Serial.println(F("Blink example"));

#ifdef T_BEAM_V0_7
  // initialize digital pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);
#else
  Serial.println(F("For newer versions, please use the PMU instead"));
#endif
}

void loop() {
#ifdef T_BEAM_V0_7
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState);
  }
#endif // T_BEAM_V0_7
}

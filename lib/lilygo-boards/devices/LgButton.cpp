#ifdef HAS_BUTTON
#include <Arduino.h>
#include "LgButton.h"

OneButton button(BUTTON_PIN,!BUTTON_ACTIVEHIGH, !!BUTTON_PULLUP); // pin, active low, use internal pullup

void setupButton(callbackFunction onClick, callbackFunction onDoubleClick, callbackFunction onLongPress)
{
  button.setup(BUTTON_PIN, INPUT_PULLUP);

  button.attachClick(onClick);
  button.attachDoubleClick(onDoubleClick);
  button.attachLongPressStart(onLongPress);
}

void buttonLoop()
{
  button.tick();
}
#endif // HAS_BUTTON
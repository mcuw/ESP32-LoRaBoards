#ifndef LG_LED_H
#define LG_LED_H

#ifdef HAS_LED
void flashLed();
#else
#define flashLed()
#endif

#endif /* LG_LED_H */
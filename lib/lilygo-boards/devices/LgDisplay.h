#ifndef LG_DISPLAY_H
#define LG_DISPLAY_H

#ifdef HAS_DISPLAY
#include <U8g2lib.h>

#ifndef DISPLAY_ADDR
#define DISPLAY_ADDR 0x3C
#endif

extern U8G2 *disp;
#define U8G2_HOR_ALIGN_CENTER(t)    ((disp->getDisplayWidth() -  (disp->getUTF8Width(t))) / 2)
#define U8G2_HOR_ALIGN_RIGHT(t)     ( disp->getDisplayWidth()  -  disp->getUTF8Width(t))

bool beginDisplay();
#endif // HAS_DISPLAY

#endif /* LG_DISPLAY_H */
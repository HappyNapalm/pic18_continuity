#include "leds.h"

//TODO make a proper made of the LEDs

inline void clr_LEDs (void)
{
  LED7 = LED8 = LED9 = LATC = 0x00;
}

inline void all_LEDs (void)
{
  LED7 = LED8 = LED9 = LATC = 0xFF;
}

void get_LEDs (void)
{
    //returns the uw containing LED states
}
#include <stdio.h>
//#include <stdlib.h>
#include <xc.h>
#include <htc.h>
#include "setup.h"
#include "leds.h"

//Make a global IO structure that sums IO and LEDs

struct gstGPIO astLEDs[MAX_IO] = {
    { &LATC, 0 },  /*LED1*/
    { &LATC, 2 },  /*LED2*/
    { &LATC, 1 },  /*LED3*/
    { &LATC, 5 },  /*LED4*/
    { &LATC, 6 },  /*LED5*/
    { &LATC, 7 },  /*LED6*/
    { &LATB, 3 },  /*LED7*/
    { &LATB, 4 },  /*LED8*/
    { &LATE, 0 },  /*LED9*/
};  //TODO: Review addressing on the PIC


void clr_LEDs (void)
{
    for (unsigned char uc = 0; uc < MAX_IO; uc++)
    {
        set_IO(astLEDs, uc, 0);
    }
}

void all_LEDs (void)
{
  //LED7 = LED8 = LED9 = LATC = 0xFF;
    for (unsigned char uc = 0; uc < MAX_IO; uc++)
    {
        set_IO(astLEDs, uc, 1);
    }
}

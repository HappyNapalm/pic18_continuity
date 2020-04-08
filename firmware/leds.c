#include <stdio.h>
//#include <stdlib.h>
#include <xc.h>
#include <htc.h>
#include "setup.h"
#include "leds.h"

//Make a global IO structure that sums IO and LEDs

const struct{
    volatile unsigned char *port;
    unsigned char pin;
} gstLEDs[] = {
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
        unsigned char ucLocal;              //
        ucLocal = *gstLEDs[uc].port;        //Get value of address
        ucLocal &= ~(1 << gstLEDs[uc].pin); //Clear the correct bit
        *gstLEDs[uc].port = ucLocal;        //Overwrite the old value
        
    }
}

void all_LEDs (void)
{
  //LED7 = LED8 = LED9 = LATC = 0xFF;
    for (unsigned char uc = 0; uc < MAX_IO; uc++)
    {
        unsigned char ucLocal;              //
        ucLocal = *gstLEDs[uc].port;        //Get value of address
        ucLocal |= (1 << gstLEDs[uc].pin);  //Set the correct bit
        *gstLEDs[uc].port = ucLocal;        //Overwrite the old value

    }
}

unsigned short get_LEDs (void)
{
    //returns the uw containing LED states
    unsigned short uw = 0;
    return uw;
}

void set_LED (unsigned char ucLED, unsigned char bValue)
{
    unsigned char ucLocal;
    ucLocal = *gstLEDs[ucLED].port;
    if (bValue)
    {
        ucLocal |= (1 << gstLEDs[ucLED].pin);
    }
    else
    {
        ucLocal &= ~(1 << gstLEDs[ucLED].pin);
    }
    *gstLEDs[ucLED].port = ucLocal;
}

#include <stdio.h>
//#include <stdlib.h>
#include <xc.h>
#include <htc.h>
#include "setup.h"
#include "leds.h"




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

#define WALK_PERIOD 10000
void walk_LEDs(void)
{
//    static unsigned short uwStartTime;
//    static unsigned char uc;
//    static unsigned char nbFirst;
//    static unsigned char ucOverFlow;
//    if(!nbFirst)
//    {
//        //clr_LEDs();
//        uwStartTime = get_Time();
//        ucOverFlow = gbTick;
//        nbFirst = 1;
//        
//    }
//    
//    if(bTimeUp(uwStartTime,/*ucOverFlow,*/WALK_PERIOD))
//    {
//        //clr_LEDs();
//        set_IO(astLEDs, 8, HB);
//        nbFirst = 0;
//        uc++;
//    }
//    if(uc == MAX_IO)
//    {
//        uc = 0;
//    }
    set_IO(astLEDs, 8, HB);
}
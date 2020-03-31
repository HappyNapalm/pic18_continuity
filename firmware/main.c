
/*
 * File:   main.c
 * Author: Church
 *
 * Created on February 22, 2019, 5:04 AM
 */
#include <stdio.h>
//#include <stdlib.h>
#include <xc.h>
#include <htc.h>

#include "setup.h"

/** C O N F I G U R A T I O N   B I T S ******************************/
#pragma config FOSC = INTIO67
//#pragma config WDTEN = OFF, LVP = OFF, MCLRE = OFF
#pragma config WDTEN = OFF, LVP = OFF

/** I N C L U D E S **************************************************/
//#include "p18f45k20.h"
/********************************************************************/

void testing (unsigned char bModeSwitch)
{
	if(bModeSwitch)
	{
		//wiggle 9th bit
	}
	
}

void dis_Results()
{

}


void main (void)
{
    setup();
    flash();
    clr_LEDs();
    //start_up();
    while(1)
    {
        //gucAnimationState = 5;
        //Animation_Loop_Timer();
        LED_Pattern_Master(gucAnimationState);
    }
}
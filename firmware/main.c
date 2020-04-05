
/*
 * File:   main.c
 * Author: Church
 *
 * Created on April 2020
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
//@about: Compares inputs and outputs, returns 0 False, 1 True, 2 err
//@takes: unsigned char of the target bit to compare. Err iff > MAX_IO
unsigned char b2_Compare (unsigned char ucTargetBit)
{
	unsigned char b = 2;
//	{
	//	if(ucTargetBit == MAX_IO)
	//	{
	//		//Ninth bit comparison on input and output
	//	}
	//	else
	//	{
	//		if(OUTPUTS == INPUTS)
	//		{
	//			//Verify Output is correct
	//			b = ((OUTPUTS >> ucTargetBit) & 0x01);
	//		}
	//	}
//	}
	return b;
}

//Returns state of mode switch as 2 bits.
//ETHernet -> 0b01
//DB9      -> 0b10
unsigned char GetModeSwitch (void)
{
    return ETH | (DB9 << 1);
}

void testing (unsigned char ModeSwitch, unsigned char ucTargetBit)
{
	if(ModeSwitch)
	{
		//wiggle 9th bit
	}
    if (ModeSwitch)
	b2_Compare(ucTargetBit);
	
}

void dis_Results()
{

}


void main (void)
{
    setup();
//    flash();
    clr_LEDs();
    //start_up();
    while(1)
   {
        testing(GetModeSwitch,0);
   }
}
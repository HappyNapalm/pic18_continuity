/* 
 * File:   setup.h
 * Author: church
 *
 * Created on April 5, 2020, 5:24 PM
 */

#ifndef SETUP_H
#define	SETUP_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
//global variables

//@About: Allows for IO tables to be made
struct gstGPIO{
    volatile unsigned char *port;
    unsigned char pin;
};

void set_IO (struct gstGPIO *IO, unsigned char item,unsigned char bValue);


//#define In9   LATBbits.LB0
//#define Out9  LATBbits.LB1

#define HB    LATBbits.LB2


#define ETH   LATEbits.LE1
#define DB9   LATEbits.LE2

#define MAX_IO 9            //Defines IO to test. 1 LED per IO pair.

//functions
void IO_setup (void);

void Timer_and_Interrupt_setup (void);
void setup (void);

void Set_Output (unsigned char ucPinMinus1, 
                        unsigned char bOut);

void clr_Outputs (void);
unsigned char Get_Output (unsigned char ucPinMinus1);
unsigned char Get_Input (unsigned char ucPinMinus1);

//void start_up(void);


#endif	/* SETUP_H */


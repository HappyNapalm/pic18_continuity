/* 
 * File:   setup.h
 * Author: church
 *
 * Created on April 5, 2019, 5:24 PM
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
#define In9   LATBbits.LB0
#define Out9  LATBbits.LB1
#define HB    LATBbits.LB2
#define LED7  LATBbits.LB3
#define LED8  LATBbits.LB4

#define MAX_IO 8

//functions
void IO_setup (void);
void clr_LEDs (void);
void Timer_and_Interrupt_setup (void);
void setup (void);

//void start_up(void);


#endif	/* SETUP_H */


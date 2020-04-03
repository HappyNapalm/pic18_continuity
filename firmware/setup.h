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
#define In9   LATB & 0b00000001
#define Out9  LATB & 0b00000010
#define HB    LATB & 0b00000100
#define LED7  LATB & 0b00001000
#define LED8  LATB & 0b00010000

#define MAX_IO 8

//functions
void IO_setup (void);
void clr_LEDs (void);
void Timer_and_Interrupt_setup (void);
void setup (void);

//void start_up(void);


#endif	/* SETUP_H */


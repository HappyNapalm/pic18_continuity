/* 
 * File:   leds.h
 * Author: church
 *
 * Created on April 5, 2020, 5:24 PM
 */

#ifndef LEDS_H
#define	LEDS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

//Macros
#define LED7  LATBbits.LB3
#define LED8  LATBbits.LB4
#define LED9  LATEbits.LE0

//Global Vars

//Functions
void clr_LEDs (void);
void all_LEDs (void);
void get_LEDs (void);

#endif	/* SETUP_H */
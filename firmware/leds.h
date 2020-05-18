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
#define LED1  LATCbits.LC0
#define LED2  LATCbits.LC2
#define LED3  LATCbits.LC1
#define LED4  LATCbits.LC5
#define LED5  LATCbits.LC6
#define LED6  LATCbits.LC7
#define LED7  LATBbits.LB3
#define LED8  LATBbits.LB4
#define LED9  LATEbits.LE0


//Global Vars
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
};
//extern const struct gstLEDs;

//Functions
extern void clr_LEDs (void);
extern void all_LEDs (void);
extern unsigned short get_LEDs (void);
extern void walk_LEDs (void);

#endif	/* SETUP_H */
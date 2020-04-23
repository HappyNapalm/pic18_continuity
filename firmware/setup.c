#include <stdio.h>
//#include <stdlib.h>
#include <xc.h>
#include <htc.h>
#include "setup.h"
#include "leds.h"

//@About set GPIO table item to boolean
void set_IO (struct gstGPIO *IO, unsigned char item,unsigned char bValue)
{
    volatile unsigned char *ucLocal;
    ucLocal = IO[item].port;
    if (bValue)
    {
        *ucLocal |= (1 << IO[item].pin);
    }
    else
    {
        *ucLocal &= ~(1 << IO[item].pin);
    }
}

//@About get the state of an item from a GPIO table
unsigned char get_IO (struct gstGPIO *IO, unsigned char item)
{
    return (unsigned char)((*IO[item].port >> IO[item].pin) & 0x01);
}

struct gstGPIO astInputs[] = {
    {&PORTD, 0},
    {&PORTD, 1},
    {&PORTD, 2},
    {&PORTD, 3},
    {&PORTD, 4},
    {&PORTD, 5},
    {&PORTD, 6},
    {&PORTD, 7},
    {&PORTB, 0},
};

struct gstGPIO astOutputs[] = {
    {&LATA, 0},
    {&LATA, 1},
    {&LATA, 2},
    {&LATA, 3},
    {&LATA, 4},
    {&LATA, 5},
    {&LATA, 6},
    {&LATA, 7},
    {&LATB, 1},
};

void IO_setup (void)
{
  TRISA = 0x00;           //Outputs
  TRISC = 0x00;           //LEDS
  TRISBbits.RB0 = 1;      //In9
  TRISBbits.RB1 = 0;      //Out9
  TRISBbits.RB2 = 0;      //HB
  TRISBbits.RB3 = 0;      //LED7
  TRISBbits.RB4 = 0;      //LED8
  TRISD = 0xFF;           //Inputs
  TRISEbits.RE0 = 0;      //LED9
  TRISEbits.RE1 = 1;      //Switch 1A
  TRISEbits.RE2 = 1;      //Switch 1B
}


void Timer_and_Interrupt_setup (void)
{
    //Let this timer run as a free running timer
    
    //16 bits. 1:64 prescaler. Internal. 1 tick is 8us
    T0CON = 0b10010101;
    //INTCONbits.TMR0IE = 1;
    
    //8Mhz timer. Internal
    OSCCON = 0b01100111;
    
    
    T3CON = 0b00110101;
}

void clr_Timer (void)
{
    TMR0H = 0;
    TMR0L = 0;
}

void clr_Timer3 (void)
{
    TMR3H = 0;
    TMR3L = 0;
}

void __interrupt() ISR()
{
    if(TMR0IF)
    {
        TMR0IF = 0;
        clr_Timer();
        HB = !HB;
        gbTick++;
    }
    if(TMR3IF)
    {
        TMR3IF = 0;
        clr_Timer3();
        guc_3_Tick++;
        gucTestBit++;
    }
}

inline volatile unsigned short get_Time(void)
{
    return ((unsigned short)(TMR0H << 8) | TMR0L);
}

//@About: Checks with the free running timer
unsigned char bTimeUp(
                        unsigned short StartTime,
                        /*unsigned char StartOverFlowCount,*/
                        unsigned short Period
                     )
{
    unsigned char b = 0;
    unsigned short CurrentTime = get_Time();
    
    if (CurrentTime < StartTime)
    {
//        if(StartOverFlowCount > gbTick)
//        {
            if(((0xFFFF - StartTime) + CurrentTime) >= Period)
                {
                    b = 1;
                }
//        }
    }
    else if (CurrentTime - StartTime >= Period)
    {
        b = 1;
    }
    return b;
}

void setup(void)
{
    INTCONbits.GIE = 0;
    IO_setup();
    //clr_Timer();
    HB = 0;
    Timer_and_Interrupt_setup();
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    T0CONbits.TMR0ON = 1;
    T3CONbits.TMR3ON = 0;
    all_LEDs();
    
    
}

#define HB_PERIOD 10000
void heartbeat(void)
{
    static unsigned char nbFirst;
    static unsigned short uwStartTime;
    static unsigned char ucOverFlow;
    //unsigned short uwCurrentTime = get_Time();
    if(!nbFirst)
    {
        uwStartTime = get_Time();
        ucOverFlow = gbTick;
        nbFirst = 1;
    }
    else
    {
        if(bTimeUp(uwStartTime,/*ucOverFlow,*/HB_PERIOD))
        {
            HB = !HB;
        }
    }
}

void compare_IO(unsigned char TargetBit)
{
    unsigned char bOutput = get_IO(astOutputs,TargetBit);
    unsigned char bInput  = get_IO(astInputs ,TargetBit);
    set_IO(astLEDs,TargetBit,(bOutput == bInput==1));
    
}

void testing(unsigned char TargetBit)
{
    static unsigned char b;
    static unsigned char ucLocalTicks;
    static unsigned char nbFirst;
    if(!nbFirst)
    {
        b = 1;
        nbFirst = 1;
        ucLocalTicks = guc_3_Tick;
        T3CONbits.TMR3ON = 1;   //Start the timer
    }
    if(ucLocalTicks != guc_3_Tick)
    {
        T3CONbits.TMR3ON = 0;
        b = 0;
        nbFirst = 0;
    }
    set_IO(astOutputs,TargetBit,b);
    compare_IO(TargetBit);
}

//# Potential EEPROM code below #//

// unsigned char read_eeprom(unsigned char ucAddress)
// {
//   unsigned char Data;
//   EEADR = ucAddress;       // Write The Address From Which We Wonna Get Data
//   EECON1bits.EEPGD = 0;  // Cleared To Point To EEPROM Not The Program Memory
//   EECON1bits.RD = 1;     // Start The Read Operation
//   Data = EEDATA;         // Read The Data
//   return (Data);

// }

// void write_eeprom(unsigned char ucAddress, unsigned char ucData)
// {
//   while(EECON1bits.WR);  // Waits Until Last Attempt To Write Is Finished
//   EEADR = ucAddress;       // Writes The Addres To Which We'll Wite Our Data
//   EEDATA = ucData;         // Write The Data To Be Saved
//   EECON1bits.EEPGD = 0;  // Cleared To Point To EEPROM Not The Program Memory
//   EECON1bits.WREN = 1;   // Enable The Operation !
//   INTCONbits.GIE = 0;    // Disable All Interrupts Untill Writting Data Is Done
//   EECON2 = 0x55;         // Part Of Writing Mechanism..
//   EECON2 = 0xAA;         // Part Of Writing Mechanism..
//   EECON1bits.WR = 1;     // Part Of Writing Mechanism..
//   INTCONbits.GIE = 1;    // Re-Enable Interrupts
//   EECON1bits.WREN = 0;   // Disable The Operation
//   EECON1bits.WR = 0;     // Ready For Next Writting Operation             
// }

// void reset_eeprom(void)
// {
//     unsigned char byte_count;
//     for(byte_count = 0; byte_count < 100; byte_count++)
//     {
//         write_eeprom(byte_count,0xff);
//     }
// }

// void HEX_2_LED(unsigned char EEPROM_MEM_ADDRESS)
// {
//     unsigned char LED_1;
//     unsigned char LED_2;
//     LED_1 = EEPROM_MEM_ADDRESS & 0x0F;
//     LED_2 = (EEPROM_MEM_ADDRESS & 0xF0 >> 4);
//     LED_Output_Single(LED_1,1);
//     LED_Output_Single(LED_2,1);
// }

// //On power up make it so you cycle through the EEPROM from 0-95 (six passes)
// //Read until you find one that mets the following criteria:
// //  (1) Not 0xFF
// //  (2) Highest value found
// //  (3) Then increment the value
// //  (4) Read the value and modulate by 16 to get the animation timer.
// //  (5) Assume that 0xFF at address 0 means we have restarted
// //  (6) If at address 95, then we can reset.


// void start_up(void)
// {
//     unsigned char ucDataOut = 0;
//     unsigned char ucValid = 0;
    
//     ucDataOut = read_eeprom(0x0A);
//     if(ucDataOut > 7)
//     {
//         ucDataOut = 0;
//     }
//     gucAnimationState = ucDataOut;
//     write_eeprom(0x0A,(ucDataOut+1));
// }

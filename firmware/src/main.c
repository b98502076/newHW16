
#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "system/common/sys_module.h"   // SYS function prototypes
#include<xc.h> // processor SFR definitions
#include<sys/attribs.h> // __ISR macro

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all MPLAB Harmony modules, including application(s). */
    SYS_Initialize ( NULL );
    _CP0_SET_COUNT(0);
           // set up USER pin as input
        ANSELBbits.ANSB13=0;
	TRISBbits.TRISB13=1;
    // set up LED1 pin as a digital output
    //    TRISBbits.TRISB7=0;
    //   	LATBbits.LATB7=1;

    // set up LED2 as OC1 using Timer2 at 1kHz   PWM: B15   DIO: B9   left
        TRISBbits.TRISB9=0;
        LATBbits.LATB9=1;
        ANSELBbits.ANSB15=0;
	RPB15Rbits.RPB15R=0b0101;
	T2CONbits.TCKPS = 0;
	PR2=1999;
	TMR2=0;
	T2CONbits.ON=1;
        T2CONbits.TCS=0;
	OC1CONbits.OCTSEL=0;
	OC1CONbits.OCM = 0b110;  // PWM mode without fault pin; other OC1CON bits are defaults
	OC1CONbits.ON = 1;
	OC1RS=0;
	OC1R=0;
    //  OC2  PWM: B5    DIO: B3    right
        ANSELBbits.ANSB3=0;
        TRISBbits.TRISB3=0;
        LATBbits.LATB3=0;

        RPB5Rbits.RPB5R=0b0101;
        T3CONbits.TCKPS = 0;
	PR3=1999;
	TMR3=0;
	T3CONbits.ON=1;
        T3CONbits.TCS=0;
	OC2CONbits.OCTSEL=1;
	OC2CONbits.OCM = 0b110;  // PWM mode without fault pin; other OC1CON bits are defaults
	OC2CONbits.ON = 1;
	OC2RS=0;
	OC2R=0;
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );

    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/


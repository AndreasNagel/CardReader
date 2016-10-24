/*
 * newClock.c
 *
 *  Created on: Oct 23, 2016
 *      Author: Ultrasonicu töötava clocki peale tehtud.
 *
 */

//***** Header Files **********************************************************
#include <driverlib.h>
#include "newClock.h"

#define LF_CRYSTAL_FREQUENCY_IN_HZ     32768                                    // 32KHz, KÜSIMUS: KAS TOHIKS KA 0 PANNA?
#define HF_CRYSTAL_FREQUENCY_IN_HZ     32000000                                  // 32MHz

void newClockInit(){

	/*
	 * PxSEL - select pin function: 0: I/O Function is selected for the pin; 1: Peripheral module function is selected for the pin
	 * P5SEL |= BIT2 + BIT3 means port5 pins 2 and 3 (1100) are selected as peripheral module functions.
	 * KÜSIMUS: MILLE JÄRGI ON VALITUD PORT 5, MILLE JÄRGI BITID 2 JA 3?
	 */
    P5SEL |= BIT2 + BIT3; //XT2CLK select

    //**************************************************************************
        // Configure core voltage level
        //**************************************************************************

    	// Set core voltage level to handle 32MHz clock rate; levels 0-3 range 1.8-3.6V
    	PMM_setVCore(PMM_CORE_LEVEL_3);

    	 UCS_setExternalClockSource(
    	            LF_CRYSTAL_FREQUENCY_IN_HZ,                                         // XT1CLK input
    	            HF_CRYSTAL_FREQUENCY_IN_HZ                                          // XT2CLK input
    	    );

    	 UCS_turnOnXT2( UCS_XT2_DRIVE_24MHZ_32MHZ ); //enable XT2CLK

    	// Clock init using DCO/FLL
        // Set REFO as the oscillator reference clock for the FLL
        UCS_initClockSignal(
                UCS_FLLREF,                                  // Clock you're configuring
    			UCS_XT2CLK_SELECT,                           // Clock source
                UCS_CLOCK_DIVIDER_1                          // Divide down clock source by this much
        );

        // Set MCLK and SMCLK to use the DCO/FLL as their oscillator source (32MHz)
       	// Calculates required FLL settings; Configures FLL and DCO,
       	// and then sets MCLK and SMCLK to use the DCO (with FLL runtime calibration)
           UCS_initFLLSettle(
                   MCLK_DESIRED_FREQUENCY,               // MCLK frequency
                   MCLK_FLLREF_RATIO                            // Ratio between MCLK and FLL's reference clock source
           );

    }


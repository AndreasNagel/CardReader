/*
 * initClock.c
 *
 *  Created on: 3. okt 2016
 *      Author: karls_000
 */

#include "MSP430F5xx_6xx/driverlib.h"

int set_clock(int clock_speed){
	if(clock_speed == 0){
		UCSCTL2 |= 0x0000; // Phase lock loop frequency divider, bits 12-14 set divider, 5 = clk/32, 0 = clk/1
		//UCSCTL5 |= 0x0005; // uncomment this line to make master clock 32 times slower

		UCSCTL4 |= 0x0004; // Select master clock source currenctly DCOCLKDIV

	}
	return 0;
}

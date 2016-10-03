#include <msp430.h> 
#include "UARTmodule.h"

/*
 * main.c
 */
int set_clock(int);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    set_clock(0);
	P1DIR |= 0x01;					// Set P1.0 to output direction, controls red LED
	P4DIR |= 0x80;					// Set P4.7 to output, controls green LED


	for(;;) {
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= 0x01;				// Toggle P1.0 using exclusive-OR

		i = 10000;					// SW Delay
		do i--;
		while(i != 0);
		init_UART();
		i = 10000;					// SW Delay
		do i--;
		while(i != 0);
	}
	return 0;
}

// Sets master clock to a designated frequency,
// viable settings are yet to be determined
// more information in datasheet under unified clock system (UCS)
int set_clock(int clock_speed){
	if(clock_speed == 0){
		UCSCTL2 |= 0x5000; // Phase lock loop frequency divider, bits 12-14 set divider, 5 = clk/32, 0 = clk/1
		//UCSCTL5 |= 0x0005; // uncomment this line to make master clock 32 times slower

		UCSCTL4 |= 0x0004; // Select master clock source currenctly DCOCLKDIV

	}
	return 0;
}

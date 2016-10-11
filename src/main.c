#include <msp430.h> 
#include "UARTmodule.h"
#include "initClock.h"
#include "timer.h"
#include "initGpio.h"
#include "MSP430F5xx_6xx/driverlib.h"

/*
 * main.c
 */

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
    set_clock(0);
	//P1DIR |= 0x01;					// Set P1.0 to output direction, controls red LED
	//P4DIR |= 0x80;					// Set P4.7 to output, controls green LED

	set_gpio(GPIO_PORT_P1, GPIO_PIN0, OUTPUT, HIGH); //Hetkel kontrollib punast LED-i (P1.0)
	set_gpio(GPIO_PORT_P4, GPIO_PIN7, OUTPUT, LOW); //Hetkel kontrollib rohelist LED-i (P4.7)
/*
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
	}*/
	return 0;
}

// Sets master clock to a designated frequency,
// viable settings are yet to be determined
// more information in datasheet under unified clock system (UCS)



#include <stdlib.h>

#include "initClock.h"
#include "application.h"
/*
 * main.c
 */



void main(void) {

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    volatile uint32_t mclk = 0;
    volatile uint32_t smclk = 0;

    int accessGranted = 0;


    set_clock();
    init_UART();
    //UART_init();
    set_rawCodePtr();
    timer_init();

	for(;;) {
		write_UART('F');
		write_UART('G');
		write_UART('R');
		accessGranted = checkCode();
		blinkLED(accessGranted);
	}
}

// Sets master clock to a designated frequency,
// viable settings are yet to be determined
// more information in datasheet under unified clock system (UCS)





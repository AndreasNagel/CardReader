#include <msp430.h>
#include <stdlib.h>
#include "UARTmodule.h"
#include "initClock.h"
#include "timer.h"
#include "initGpio.h"
#include "MSP430F5xx_6xx/driverlib.h"
#include "fifo.h"


#define FIFO_SIZE 16

/*
 * main.c
 */

fifo_t cardBytes;

void main(void) {

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    volatile uint32_t mclk = 0;
    volatile uint32_t smclk = 0;

    set_clock();
    timer_init();
    init_UART();
    fifo_init(&cardBytes, 16);



	for(;;) {
		UART_cyclic();
		GPIO_cyclic();
	}
}

// Sets master clock to a designated frequency,
// viable settings are yet to be determined
// more information in datasheet under unified clock system (UCS)





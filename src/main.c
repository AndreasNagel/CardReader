#include <msp430.h> 
#include "UARTmodule.h"
#include "initClock.h"
#include "timer.h"
#include "initGpio.h"
#include "MSP430F5xx_6xx/driverlib.h"

/*
 * main.c
 */

void main(void) {

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    volatile uint32_t mclk = 0;
    volatile uint32_t smclk = 0;


    set_clock();
    timer_init();
    init_UART();

    RED_LED_ON;
    GREEN_LED_ON;

	//set_gpio(GPIO_PORT_P1, GPIO_PIN0, OUTPUT, HIGH); //Hetkel kontrollib punast LED-i (P1.0)
	//set_gpio(GPIO_PORT_P4, GPIO_PIN7, OUTPUT, LOW); //Hetkel kontrollib rohelist LED-i (P4.7)



	for(;;) {
		UART_cyclic();
	}
}

// Sets master clock to a designated frequency,
// viable settings are yet to be determined
// more information in datasheet under unified clock system (UCS)





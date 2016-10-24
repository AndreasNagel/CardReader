/*
 * UARTmodule.c
 *
 *  Created on: 19. sept 2016
 *      Author: Andreas Nagel
 */
// UCAxCTL0 UART-Mode Control Bits
//#define UCPEN                  (0x80)         /* Async. Mode: Parity enable */
//#define UCPAR                  (0x40)         /* Async. Mode: Parity     0:odd / 1:even */
//#define UCMSB                  (0x20)         /* Async. Mode: MSB first  0:LSB / 1:MSB */
//#define UC7BIT                 (0x10)         /* Async. Mode: Data Bits  0:8-bits / 1:7-bits */
//#define UCSPB                  (0x08)         /* Async. Mode: Stop Bits  0:one / 1: two */
//#define UCMODE1                (0x04)         /* Async. Mode: USCI Mode 1 */
//#define UCMODE0                (0x02)         /* Async. Mode: USCI Mode 0 */
//#define UCSYNC                 (0x01)         /* Sync-Mode  0:UART-Mode / 1:SPI-Mode */

//#include <msp430.h>
//#include "MSP430F5xx_6xx/driverlib.h"


void init_UART(){
	//P4OUT |= 0x80;
	// set all config registers
	//then clear USCSWRST bit to 0
	EUSCI_A_UART_initParam initParam;
	EUSCI_A_UART_initParam *pInitParam;
	pInitParam->selectClockSource = EUSCI_A_UART_CLOCKSOURCE_SMCLK;
	pInitParam->clockPrescalar = UART_PRESCLE;
	pInitParam->firstModReg = UART_FIRST_MOD_REG; //0x0F;
	pInitParam->secondModReg = UART_SECOND_MOD_REG;
	pInitParam->parity = USCI_A_UART_NO_PARITY;
	pInitParam->secondModReg = UART_SECOND_MOD_REG

	EUSCI_A_UART_enable(USCI_A0_BASE, pInitParam);
	EUSCI_A_UART_init(USCI_A0_BASE, pInitParam);



}

void write_UART(int out){

}

int read_UART(){

	return 0;
}

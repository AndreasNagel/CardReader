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

#include <msp430.h>


void init_UART(){
	P4OUT |= 0x80;
	// set all config registers
	//then clear USCSWRST bit to 0
}

void write_UART(int out){

}

int read_UART(){

	return 0;
}

/*
 * UARTmodule.h
 *
 *  Created on: 3. okt 2016
 *      Author: LokBok
 */

#ifndef UARTMODULE_H_
	#define UARTMODULE_H_
	#include "fifo.h"
	#include "MSP430F5xx_6xx/driverlib.h"
	//#define UART_PRESCALE 0x0068
#define UART_PRESCALE 0x00682
	//#define UART_FIRST_MOD_REG 0x03
#define UART_FIRST_MOD_REG 0x00
	//#define UART_SECOND_MOD_REG 0x00
#define UART_SECOND_MOD_REG 0x06
	#define SUCCESS 0
	#define FAILURE 1
	//#define UART_OVERSAMPLING 0x01
	#define TXD BIT3
	#define RXD BIT4
	#define FIFO_SIZE 16
	#define FIFO_READ_LEN 4

	void init_UART();
	int write_UART(unsigned char);
	unsigned char read_UART();
	unsigned char UART_cyclic();
	fifo_t* getFifoAddress();



#endif /* UARTMODULE_H_ */

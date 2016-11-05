/*
 * UARTmodule.h
 *
 *  Created on: 3. okt 2016
 *      Author: LokBok
 */

#ifndef UARTMODULE_H_
	#define UARTMODULE_H_

	#include "MSP430F5xx_6xx/driverlib.h"
	#define UART_PRESCALE 0x00D0
	#define UART_FIRST_MOD_REG 0x05
	#define UART_SECOND_MOD_REG 0x00
	#define SUCCESS 0
	#define FAILURE 1
	#define UART_OVERSAMPLING 0x00
	void init_UART();
	int write_UART(unsigned char);
	unsigned char read_UART();



#endif /* UARTMODULE_H_ */

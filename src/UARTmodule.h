/*
 * UARTmodule.h
 *
 *  Created on: 3. okt 2016
 *      Author: LokBok
 */

#ifndef UARTMODULE_H_
	#define UARTMODULE_H_

	#include "MSP430F5xx_6xx/driverlib.h"
	void init_UART();
	void write_UART(int);
	int read_UART();



#endif /* UARTMODULE_H_ */

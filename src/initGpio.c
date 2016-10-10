/*
 * initGpio.c
 *
 *  Created on: 3. okt 2016
 *      Author: karls_000
 */
#include "MSP430F5xx_6xx/driverlib.h"
#include <string.h>

void set_gpio(int port, int pins, int IO, int highlow){
	if(IO == 0){ 									//for input IO needs to be 0
		GPIO_setAsInputPin(port, pins);				//configures the selected Pin as input pin

		if(highlow == 0){							//for Pull Down resistor on selected pin highlow needs to be 0
			GPIO_setAsInputPinWithPullDownResistor(port, pins);		//This function sets the selected Pin in input Mode with Pull Down resistor
		}
		else if(highlow == 1){						//for Pull Up resistor on selected pin highlow needs to be 1
			GPIO_setAsInputPinWithPullUpResistor(port, pins);	//This function sets the selected Pin in input Mode with Pull Up resistor
		}
	}
	else if(IO == 1){								//for output IO needs to be 1
		GPIO_setAsOutputPin(port, pins);			//configures the selected Pin as output pin

		if(highlow == 0){							//for output LOW on selected pin highlow needs to be 0
			GPIO_setOutputLowOnPin(port, pins);		//This function sets output LOW on the selected Pin
		}
		else if(highlow == 1){						//for output HIGH on selected pin highlow needs to be 1
			GPIO_setOutputHighOnPin(port, pins);	//This function sets output HIGH on the selected Pin
		}
	}
}


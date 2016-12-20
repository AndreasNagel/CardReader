/*
 * application.c
 *
 *  Created on: 20. dets 2016
 *      Author: Kadri
 */

#include "application.h"

char accessCode[1][16]={{"1234567890123456"}};
fifo_t *rawCode;
void set_rawCode(){
	rawCode = getCardFifo();
}


/*
 *
 *
 * Kontrollib, kas rawCode == accessCode.
 * char string[8];
 * fifo_read(&rawCode, string, 8);
 */


int checkCode(){
	int accessGranted = 0;
	return accessGranted;
}

void blinkLED(int accessGranted){
	if(accessGranted == 1){
		GREEN_LED_ON;
		RED_LED_OFF;
	}
	else if(accessGranted == 2){
		RED_LED_ON;
		GREEN_LED_OFF;
	}
	int ms = getMs();
	if(ms>=5000)
	{
		RED_LED_OFF;
		GREEN_LED_OFF;
		resetMs();
	}
}


/*
 * application.c
 *
 *  Created on: 20. dets 2016
 *      Author: Kadri
 */

#include "application.h"
#include "string.h"

char accessCode[1][CODE_LEN]={{"1234567890123456"}};
fifo_t *rawCode;
void set_rawCodePtr(){
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
	volatile int accessGranted = 0;
	volatile unsigned int bytes;
	char readCode[CODE_LEN];
	bytes = fifo_read(rawCode, readCode, CODE_LEN);

	strncpy(readCode, "1234567890123456", 16);

	volatile char codeCorrect = strncmp(readCode, accessCode[0], 16);
	if(bytes == 0) {
		accessGranted = 0;
	}

	else if(codeCorrect == 0){
		accessGranted = 1;
	}
	else{
		accessGranted = 2;
	}

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


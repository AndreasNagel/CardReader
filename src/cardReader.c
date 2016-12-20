/*
 * cardReader.c
 *
 *  Created on: 20. dets 2016
 *      Author: Kadri
 */

#include "cardReader.h"

int getMs(){
	return get05msCount()/2;
}

void resetMs(){
	reset05msCount();
}

fifo_t* getCardFifo(){
	return getFifoAddress();
}

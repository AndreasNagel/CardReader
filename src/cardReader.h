/*
 * cardReader.h
 *
 *  Created on: 20. dets 2016
 *      Author: Kadri
 */

#ifndef CARDREADER_H_
#define CARDREADER_H_
#define CODELENGTH 16
#include "UARTmodule.h"
#include "fifo.h"
#include "timer.h"
fifo_t* getCardFifo();
int getMs();
void resetMs();

#endif /* CARDREADER_H_ */

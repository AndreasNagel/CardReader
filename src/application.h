/*
 * application.h
 *
 *  Created on: 20. dets 2016
 *      Author: Kadri
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "cardReader.h"
#include "initGpio.h"

int checkCode();

void blinkLED(int accessGranted);

#endif /* APPLICATION_H_ */

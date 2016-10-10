/*
 * initGpio.h
 *
 *  Created on: 3. okt 2016
 *      Author: karls_000
 */

#ifndef INITGPIO_H_
#define INITGPIO_H_
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define PULL_DOWN 0
#define PULL_UP 1

void set_gpio(int port, int pins, char IO, int highlow);

#endif /* INITGPIO_H_ */

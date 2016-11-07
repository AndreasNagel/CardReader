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
#define RED_LED_ON set_gpio(GPIO_PORT_P1, GPIO_PIN0, OUTPUT, HIGH) //Hetkel kontrollib plaadil olevat punast LED-i (P1.0)
#define RED_LED_OFF set_gpio(GPIO_PORT_P1, GPIO_PIN0, OUTPUT, LOW) //Hetkel kontrollib plaadil olevat punast LED-i (P1.0)
#define GREEN_LED_ON set_gpio(GPIO_PORT_P4, GPIO_PIN7, OUTPUT, HIGH) //Hetkel kontrollib plaadil olevat rohelist LED-i (P4.7)
#define GREEN_LED_OFF set_gpio(GPIO_PORT_P4, GPIO_PIN7, OUTPUT, LOW) //Hetkel kontrollib plaadil olevat rohelist LED-i (P4.7)


void set_gpio(int port, int pins, char IO, int highlow);

#endif /* INITGPIO_H_ */

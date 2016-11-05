/*
 * timer.h
 *
 *  Created on: 3. okt 2016
 *      Author: Madis
 */

#ifndef TIMER_H_
#define TIMER_H_
#define ClockCyclesCount 32000 /*see on uint16, mis l‰heb compare registrisse CCR0 ning timer_A countib selle arvuni, olenevalt clock kiirusest saab selle arvuga m‰‰rata, nt interrupt intervalle*/

/* ainult enda kirjutatud funcid ning mida saab v‰ljast kutsuda; muud timer.c failis olevad funcid on olemas "MSP430F5xx_6xx/driverlib.h"*/
void timer_init();


#endif /* TIMER_H_ */

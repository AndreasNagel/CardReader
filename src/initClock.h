/*
 * initClock.h
 *
 *  Created on: 3. okt 2016
 *      Author: karls_000
 */

#ifndef INITCLOCK_H_
	#define INITCLOCK_H_
	int set_clock();
	#define XT1_FREQ 32768  //
	#define XT2_FREQ 4000000  //4 MHZ
	#define MCLK_FREQ_KHZ 32000  // 32 MHZ
	#define MCLK_FLLREFERENCE_RATIO MCLK_FREQ_KHZ / (XT2_FREQ/1000/4)  // Target frequency / FLL loop frequency

#endif /* INITCLOCK_H_ */

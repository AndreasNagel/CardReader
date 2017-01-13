/*
 * timer.c
 *
 *  Created on: 3. okt 2016
 *      Author: Madis
 */

#include "MSP430F5xx_6xx/driverlib.h"
#include "timer.h"
#include "initClock.h"
#include "UARTmodule.h"

unsigned int halfmsCount;

int get05msCount(){
	return halfmsCount;
}

void reset05msCount(){
	halfmsCount = 0;
}


void timer_init()
{
	//WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
	  //P1DIR |= 0x01;                            // P1.0 output
	  //TA0CCTL0 = CCIE;                          // CCR0 interrupt enabled
	  //TA0CCR0 = MCLK_FREQ_KHZ / 2;
	  //TA0CTL = TASSEL_2 + MC_1 + TACLR;         // SMCLK, upmode, clear TAR

	  __bis_SR_register(GIE);       // Enter LPM0, enable interrupts

	  Timer_A_initUpModeParam initUpParam;
	  initUpParam.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;                      /* Use SMCLK (faster clock) */
	  initUpParam.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;           /* Input clock = SMCLK / 1 = 16MHz */
	  initUpParam.timerPeriod = MCLK_FREQ_KHZ/2;                                    	  /* 0.5ms */
	  initUpParam.timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_ENABLE;    /* Enable TAR -> 0 interrupt */
	  initUpParam.captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE;                               /* Enable CCR0 compare interrupt */
	  initUpParam.timerClear = TIMER_A_DO_CLEAR;                                /* Clear TAR & clock divider */
	  initUpParam.startTimer = false;                                           /* Don't start the timer, yet */

	  Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam ); /* Set up Timer A0 */
	  Timer_A_clearTimerInterrupt(TIMER_A0_BASE);                               /* Clear TA0IFG */
	  Timer_A_clearCaptureCompareInterrupt(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_0);                                         /* Clear CCR0IFG interrupt pending flag bit */

	  Timer_A_startCounter(TIMER_A0_BASE, TIMER_A_UP_MODE);
}

// Timer0 A0 interrupt service routine
//#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
//#elif defined(__GNUC__)
//void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) TIMER0_A0_ISR (void)
//#else
//#error Compiler not supported!
//#endif
{
	read_UART();                            // Toggle P1.0
	halfmsCount++;
	Timer_A_clearTimerInterrupt(TIMER_A0_BASE);
}

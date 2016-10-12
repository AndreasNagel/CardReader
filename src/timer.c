/*
 * timer.c
 *
 *  Created on: 3. okt 2016
 *      Author: Madis
 */
	//KÜSIMUSED
	//1.vaja välja uurida, mis clk nagel valis V smclk - select master clock
	//2.mis on TAIDEX TAxCTL juures V: vt TAxEX0 Register
	//3.selgita välja, mida TAxR see x tähendab, midagi, et mitu timerit saab korraga tööle panna vms, aga kuskil user
	// guides oli seda veits seletatud ka
	//4.TAxCCTLn input select jääb segaseks.
	//5. TAxCCTLn bit 10 CCI input signal is latched with the EQUx signal (also wtf is EQU)
	//6. TAxCCTLn mida n tähendab? kas see on nt 0-7 compare/capture registritest?

	//TAxCTL		//16-bit Timer_Ax Control Register, bits described below:
	/*
	 * BIT 15-10 RESERVED, BIG NO NO
	 ------------------------------------------------------------------------------------------
	 * BIT 9-8 TASSEL (Timer_A s select?) 00-11 valikud võimaldavad järgnevat clock valikut ehk clock source:
	 * 00 TAxCLK
	 * 01 ACLK
	 * 10 SMCLK
	 * 11 INCLK
	 ------------------------------------------------------------------------------------------
	 * BIT 7-6 ID "input divider" 00-11 valikud võimaldavad sissetulevat clocki signaali kiirust jagada:
	 * NB!lisaks saab ka TAIDEX bittidega jagada
	 * 00 /1
	 * 01 /2
	 * 10 /4
	 * 11 /8
	 ------------------------------------------------------------------------------------------
	 * BIT 5-4 MC (mode control) võimaldab valikutega 00-11:
	 * 00 stop mode, taimer ei tööta, säästab voolu
	 * 01 up mode, taimer counts up to TAxCCR0(CCR0:see on register, millega saab TAxR võrrelda)
	 * 10 continous mode, counts up to 0FFFFh ehk 65 535-ni
	 * 11 up/down mode counts up to TAxCCR0 then down to 0000h
	 ------------------------------------------------------------------------------------------
	 *Bit 3 RESERVED
	 ------------------------------------------------------------------------------------------
	 *BIT 2 TACLR (Timer_A clear) //setting this bit clears TAxR(timer A register), but keeps divider settings
	 *		and count direction.
	 ------------------------------------------------------------------------------------------
	 * BIT 1 TAIE(Timer_A interrupt enable)
	 * 0 interrupt disabled
	 * 1 interrupt enabled
	 ------------------------------------------------------------------------------------------
	 * TAIFG(Timer_A interrupt flag)
	 * 0 no interrupt pending
	 * 1 interrupt pending
	 */
	//TAxR		//Timer_Ax Counter Register. The TAxR register is the count of Timer_A.
	//TAxCCTLn		//Timer_Ax Capture/Compare Control n Register
	/*
	 * BIT 15-14 CM (capture mode)
	 * 00 no capture
	 * 01 capture on rising edge
	 * 10 capture on falling edge
	 * 11 capture both rising and falling edges
	 ------------------------------------------------------------------------------------------
	 * BIT 13-12 CCIS capture/compare input select. These bits select the TAxCCR0 input signal. See
	 * the device-specific data sheet for specific signal connections.
	 ------------------------------------------------------------------------------------------
	 * BIT 11 (Synchronize capture source) This bit is used to synchronize the capture input
     * signal with the timer clock.
     * 0 async
     * 1 synchronouz
     ------------------------------------------------------------------------------------------
     * BIT 10 SCCI (Synchronized capture/compare input). The selected CCI input signal is latched
	 * with the EQUx signal and can be read via this bit.
	 ------------------------------------------------------------------------------------------
	 * BIT 9 RESERVED
	 ------------------------------------------------------------------------------------------
	 * BIT 8 CAP
	 * 0 compare mode
	 * 1 capture mode
	 ------------------------------------------------------------------------------------------
     * BIT 7-5 Output mode. Modes 2, 3, 6, and 7 are not useful for TAxCCR0 because EQUx
	 * = EQU0.
	 * 000 OUT bit value
	 * 001 set
	 * 010 Toggle/reset
	 * 011 Set/reset
	 * 100 Toggle
	 * 101 Reset
	 * 101 Toggle/set
	 * 111 Reset/set
	 ------------------------------------------------------------------------------------------
	 *  BIT 4 CCIE Capture/compare interrupt enable. . This bit enables the interrupt request of the
	 * corresponding CCIFG flag.
	 * 0 interrupt disabled
	 * 1 interrupt enabled
	 ------------------------------------------------------------------------------------------
	 *  BIT 3 CCI (Capture/compare input). The selected input signal can be read by this bit.
	 ------------------------------------------------------------------------------------------
	 * BIT 2 OUT (Output.) For output mode 0, this bit directly controls the state of the output
	 * 0 output low
	 * 1 output high
	 ------------------------------------------------------------------------------------------
	 * BIT 1 (Capture overflow.) This bit indicates a capture overflow occurred. COV must be
	 * reset with software.
	 * 0 no capture overflow occured
	 * 1 capture overflow occured
	 ------------------------------------------------------------------------------------------
	 * BIT 0 CCIFG (Capture/compare interrupt flag).
	 * 0 no interrupt pending
	 * 1 interrupt pending
	 */
	//TAxCCRn		//Timer_A Capture/Compare n Register
	/*
	 * Compare mode: TAxCCRn holds the data for the comparison to the timer value in the Timer_A Register, TAR.
	 * Capture mode: The Timer_A Register, TAR, is copied into the TAxCCRn register when a capture is performed.
	 */
	//TAxIV Register		//Timer_Ax Interrupt Vector Register
	/*
	 * Siin peaks olema siis interruptide prioriteedid, st 0 on väiksem prioriteet kui 1 jne.
	 * TAIV (Timer_A interrupt vector value)
	 * 00h = No interrupt pending
	 * 02h = Interrupt Source: Capture/compare 1; Interrupt Flag: TAxCCR1 CCIFG;
	 * Interrupt Priority: Highest
	 * 04h = Interrupt Source: Capture/compare 2; Interrupt Flag: TAxCCR2 CCIFG
	 * 06h = Interrupt Source: Capture/compare 3; Interrupt Flag: TAxCCR3 CCIFG
	 * 08h = Interrupt Source: Capture/compare 4; Interrupt Flag: TAxCCR4 CCIFG
	 * 0Ah = Interrupt Source: Capture/compare 5; Interrupt Flag: TAxCCR5 CCIFG
	 * 0Ch = Interrupt Source: Capture/compare 6; Interrupt Flag: TAxCCR6 CCIFG
	 * 0Eh = Interrupt Source: Timer overflow; Interrupt Flag: TAxCTL TAIFG; Interrupt
	 * Priority: Lowest
	 *
	 */
	//TAxEX0 Register		//Timer_Ax Expansion 0 Register
	/*
	 * TAIDEX Input divider expansion. These bits along with the ID bits select the divider for
	 * the input clock.
	 * 000b = Divide by 1
	 * 001b = Divide by 2
	 * 010b = Divide by 3
	 * 011b = Divide by 4
	 * 100b = Divide by 5
	 * 101b = Divide by 6
	 * 110b = Divide by 7
	 * 111b = Divide by 8
	 */
#include <msp430.h>
#include "MSP430F5xx_6xx/driverlib.h"

void timer_init()
{
	/*
	 * Timer_A_initContinuousModeParam on mingi korraliku sisuga struct, mille leiab datasheetist. sellele
	 * saan parameetrina [param] kaasa anda peale [Timer_A_initContinuousModeParam *param] kirjapilti.
	 * nii on ka tehtud nt [Timer_A_initContinuousMode(0x0340, param);]
	 * param-> ... muudan structi sees olevate väljade väärtused vastavalt enda vajadustele.
	 */
	Timer_A_initContinuousModeParam param;		//eraldan mälu, mitte ainult aadressi. aga teisele funcile kogu mälu kaasa ei anna, annan aint AADRESSI
	// sest see oleks rami raiskamine, kaasa annan ainult selle loodud structi väljade aadressid?
	param.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;		//set master clock, kuna nagel oli sellega teind
	param.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;		//clock jagunemine eeldefineeritud,
	//st kuskilt sain selle TIMER_A_CLOCKSOURCE_DIVIDER_1 võtta otse.
	param.timerInterruptEnable_TAIE = 0;		//lihtsuse mõttes ei soovi interrupte
	param.timerClear = 1;		//countib edasi, kust iganes, kuna ei tohiks tähtsust omada praegu
	param.startTimer = 1;		//start immediately?

	//TAxCCTLn |= 0x0800;		//modify TAxCCTLn bits. muudan ainult 11. bitti sync clock?


	Timer_A_initContinuousMode(0x0340, &param);		//0x0340 on base address, teine parameeter &param loeb sisse Timer_A_initContinuousModeParam
	// structi aadressi
	// kui nüüd &param toob sisse param bloki aadressi (bloki suurus on määratud sellega, et tegu on structiga Timer_A_initContinuousModeParam, mis on
	// kindla suurusega).. umbes nii, et kirjutatakse aadressile 0x02, bloki suurus on 2, seega järgmine välja antav aadress saaks olla 0x04.
	Timer_A_startCounter(0x0340, TIMER_A_CONTINUOUS_MODE);		//mode contrl=10

}

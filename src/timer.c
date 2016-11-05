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
	//		24.10.16
	//7. param.clockSource = TIMER_A_CLOCKSOURCE_EXTERNAL_TXCLK; kas XT2 korral on clock valik õige?
	//8. kas pean timer.h-sse lisama igale funcile prototüübi?
	//9. mis vahe on TAIE ja CCR0_CCIE interruptidel? uuri ise välja
	//10. ei oska compareoutputmode'i valida. vaja täpsustada, mida timer täpsemalt tegema hakkab
	//11. kas initupmode ja initcomparemode saab üldse koos kasutada? timerperiod ja comparevalue tekitavad segadust, justkui teeksid sarnast asja. EI TOHI KOOS KASUTADA
	//12. täpsusta, milliseid funce kasutama pead üldse. läks nende initite-ga segaseks ära


//#include <msp430.h>
//#include "MSP430F5xx_6xx/driverlib.h"


//void timer_init()
//{
	/*
	 * Timer_A_initContinuousModeParam on mingi korraliku sisuga struct, mille leiab datasheetist. sellele
	 * saan parameetrina [param] kaasa anda peale [Timer_A_initContinuousModeParam *param] kirjapilti.
	 * nii on ka tehtud nt [Timer_A_initContinuousMode(0x0340, param);]
	 * param-> ... muudan structi sees olevate väljade väärtused vastavalt enda vajadustele.
	 */
	//Timer_A_initContinuousModeParam param;		//eraldan mälu, mitte ainult aadressi. aga teisele funcile kogu mälu kaasa ei anna, annan aint AADRESSI
	// sest see oleks rami raiskamine, kaasa annan ainult selle loodud structi väljade aadressid?
	//param.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;		//set master clock, kuna nagel oli sellega teind
	//param.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;		//clock jagunemine eeldefineeritud,
	//st kuskilt sain selle TIMER_A_CLOCKSOURCE_DIVIDER_1 võtta otse.
	//param.timerInterruptEnable_TAIE = 0;		//lihtsuse mõttes ei soovi interrupte
	//param.timerClear = 1;		//countib edasi, kust iganes, kuna ei tohiks tähtsust omada praegu
	//param.startTimer = 1;		//start immediately?

	//TAxCCTLn |= 0x0800;		//modify TAxCCTLn bits. muudan ainult 11. bitti sync clock?


	//Timer_A_initContinuousMode(0x0340, &param);		//0x0340 on base address, teine parameeter &param loeb sisse Timer_A_initContinuousModeParam
	// structi aadressi
	// kui nüüd &param toob sisse param bloki aadressi (bloki suurus on määratud sellega, et tegu on structiga Timer_A_initContinuousModeParam, mis on
	// kindla suurusega).. umbes nii, et kirjutatakse aadressile 0x02, bloki suurus on 2, seega järgmine välja antav aadress saaks olla 0x04.
	//Timer_A_startCounter(0x0340, TIMER_A_CONTINUOUS_MODE);		//mode contrl=10

//}


#include <msp430.h>
#include "MSP430F5xx_6xx/driverlib.h"

void timer_init()
{

	uint32_t ClockCyclesCount = 32000000;
=======
	/*kas peaks mingi watchdogi disablema? JAH peaks*/
}
	Timer_A_initCompareModeParam compareparam;
	compareparam.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_0;
	compareparam.compareInterruptEnable = TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE;
	compareparam.compareOutputMode = 0x00; 	//KÜSIMUS
	compareparam.compareValue = 0x00;		//KÜSIMUS

	Timer_A_initUpModeParam upmodeparam; //KÜSIMUS

	Timer_A_initCompareMode	(TIMER_A0_BASE,//should be timer_A0 base address,
	&compareparam
	);

	Timer_A_initUpMode	(	TIMER_A0_BASE,
	&upmodeparam
	);
=======

	Timer_A_initUpMode	(	TIMER_A0_BASE,		/* timerA baseaddress*/
	Timer_A_initUpModeParam &param				/* timerA parameters*/
	);

	Timer_A_startCounter	(	TIMER_A0_BASE,		/*base address and timer mode*/
			TIMER_A_UP_MODE
	);

	/*Timer_A_enableInterrupt	(TIMER_A0_BASE); pole vaja eraldi välja kutsuda*/


}

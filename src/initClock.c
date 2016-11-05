#include <msp430.h>


#include "initClock.h"
#include "MSP430F5xx_6xx/driverlib.h"

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P1DIR |= 0x01;                            // P1.0 output
  TA0CCTL0 = CCIE;                          // CCR0 interrupt enabled
  TA0CCR0 = 65000;
  TA0CTL = TASSEL_2 + MC_1 + TACLR;         // SMCLK, upmode, clear TAR

  __bis_SR_register(LPM0_bits + GIE);       // Enter LPM0, enable interrupts
  __no_operation();                         // For debugger
}



int set_clock(){

	PMM_setVCore(PMM_CORE_LEVEL_3);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P5, GPIO_PIN4+GPIO_PIN2); // Connect XT1
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P5, GPIO_PIN5+GPIO_PIN3);

	UCS_setExternalClockSource(XT1_FREQ, XT2_FREQ);

	// Initialize the crystals

	UCS_turnOnXT2(UCS_XT2_DRIVE_24MHZ_32MHZ);
					//FLL Reference, use higher frequency crystal, divide
	UCS_initClockSignal(UCS_FLLREF, UCS_XT2CLK_SELECT, UCS_CLOCK_DIVIDER_4);

	// Start the FLL and let it settle
	// This becomes the MCLCK and SMCLK automatically

	UCS_initFLLSettle(MCLK_FREQ_KHZ, MCLK_FLLREFERENCE_RATIO);
	return 0;

// Timer0 A0 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) TIMER0_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  P1OUT ^= 0x01;                            // Toggle P1.0
}

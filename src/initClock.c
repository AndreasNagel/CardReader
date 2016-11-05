#include "initClock.h"
#include "MSP430F5xx_6xx/driverlib.h"

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
}

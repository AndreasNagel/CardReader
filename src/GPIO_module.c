#include "initGpio.h"
#include "MSP430F5xx_6xx/driverlib.h"


void GPIO_cyclic(void){
    RED_LED_ON;// kontrollib punast LED-i (P1.0)
    GREEN_LED_ON;  //kontrollib rohelist LED-i (P4.7)

}

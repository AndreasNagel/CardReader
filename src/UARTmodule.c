/*
 * UARTmodule.c
 *
 *  Created on: 19. sept 2016
 *      Author: Andreas Nagel
 */


//#include <msp430.h>
//#include "MSP430F5xx_6xx/driverlib.h"
#include "UARTmodule.h"
#include "fifo.h"


fifo_t cardBytes;


void init_UART(){
	//P4OUT |= 0x80;
	// set all config registers
	//then clear USCSWRST bit to 0

	//P3SEL |= TXD + RXD;  // Select Uart module on pins 3.3 = TX and 3.4 = RX

    GPIO_setAsPeripheralModuleFunctionInputPin(
        GPIO_PORT_P3,
        GPIO_PIN3 + GPIO_PIN4
        );

	USCI_A_UART_initParam initParam;
	USCI_A_UART_initParam *pInitParam;
	pInitParam = &initParam;
	pInitParam->selectClockSource = USCI_A_UART_CLOCKSOURCE_SMCLK;
	pInitParam->clockPrescalar = UART_PRESCALE;
	pInitParam->firstModReg = UART_FIRST_MOD_REG; //0x0F;
	pInitParam->secondModReg = UART_SECOND_MOD_REG;
	pInitParam->parity = USCI_A_UART_NO_PARITY;
	pInitParam->overSampling = USCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION; //UART_OVERSAMPLING;
	pInitParam->uartMode = USCI_A_UART_MODE;	//USCI_A_UART_AUTOMATIC_BAUDRATE_DETECTION_MODE;
	pInitParam->numberofStopBits = USCI_A_UART_ONE_STOP_BIT;


	USCI_A_UART_init(USCI_A0_BASE, pInitParam);
	USCI_A_UART_enable(USCI_A0_BASE);
	USCI_A_UART_disableInterrupt(USCI_A0_BASE, USCI_A_UART_RECEIVE_INTERRUPT+
								USCI_A_UART_TRANSMIT_INTERRUPT+
								USCI_A_UART_RECEIVE_ERRONEOUSCHAR_INTERRUPT+
								USCI_A_UART_BREAKCHAR_INTERRUPT
								);
	USCI_A_UART_transmitData(USCI_A0_BASE, 'F');

	// initialize fifo inside UART
    fifo_init(&cardBytes, 32);

}


int write_UART(unsigned char out){
	volatile unsigned char lineIdle;
	lineIdle = USCI_A_UART_queryStatusFlags(USCI_A0_BASE, USCI_A_UART_IDLELINE);
	lineIdle = 0x01;

	lineIdle = USCI_A_UART_queryStatusFlags(USCI_A0_BASE, USCI_A_UART_IDLELINE);
	lineIdle = 0x01;
	if(lineIdle){
		USCI_A_UART_transmitData(USCI_A0_BASE, out);
		return SUCCESS;
	}
	else{
		return FAILURE;
	}

}


unsigned char read_UART(){
	unsigned char in;
	in = '\0';
	unsigned char newBitIn = USCI_A_UART_getInterruptStatus(USCI_A0_BASE, USCI_A_UART_RECEIVE_INTERRUPT_FLAG);
	if(newBitIn)
	{
		in = USCI_A_UART_receiveData(USCI_A0_BASE);
		fifo_write(&cardBytes, in);
	}
	return in;
}

unsigned char UART_cyclic(void){
	// Reads data from fifo, checks if the card code is correct and passes an identifier to main function?
	char buf[FIFO_READ_LEN];
	int read = 0;
	read = fifo_read(&cardBytes, buf, FIFO_READ_LEN);
	if(read==FIFO_READ_LEN)
		//read successful, right amount of bytes read
		return SUCCESS;
	else{
		return FAILURE;
	}
	/*write_UART(0x2A);
	write_UART('\0');
	write_UART(0x7F);*/
	/*write_UART('D');
	write_UART('C');
	write_UART('B');
	write_UART('8');
	write_UART('4');*/
}

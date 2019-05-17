#include "RF_ID.h"


void RfIDinit()
{
	// Initialize Receiver Port
	RX_PORT = RX_PIN_MASK;
	
	// Initialize Input port for shift register
	INPUT_PORT_DDR = 0x00;
	
	// Initialize Pin change interrupt
	SYNC_PORT_DDR &= ~SYNC_PIN_MASK;				//Initialize Pin as Input
	EICRA |= (1<<ISC31) | (1<<ISC30);				//Trigger interrupt on rising and falling edge
	
	// Initialize Timer1 to CTC Mode
	TCCR1B = TCCR1B | (1<<WGM13) | (1<<WGM12);		//set timer1 to CTC Mode 
	
	ICR1 = fICR;									
	
	OCR1A = fOCR1A;
	OCR1B = fOCR1B;
	
	
		
}
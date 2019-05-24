#include "RF_ID.h"
#include <avr/io.h>

// --------- Defining (instantiating) extern variables ------------------
// RX instantiation
char GsaveD[RX_DATA_LENGTH] = {0};
int8_t Gcounter = -4;

// TX instantiation
char GsendData[TX_DATA_LENGTH] = {0};
int8_t GsendCounter = 0;

// Input-Counter for INT1
int InputCounter=0;

char RXflag = FALSE;

void RfIDinit()
{
	// Initialize Receiver Port
	RX_PORT_DDR &= ~RX_PIN_MASK;
	
	// Initial Transmitter Port
	TX_PORT_DDR |= TX_PIN_MASK;
	TX_PORT |= TX_PIN_MASK;							// Set Tx to high to deliver energy
	
	// Initialize Input port for shift register
	DATA_INPUT_PORT_DDR = 0x00;
	
	// Initialize Pin change interrupt
	DDRD &= ~(1 << DDD3);							// Initialize PD3 as Input
	EICRA |= (1<<ISC31) | (1<<ISC30);				// Trigger interrupt on rising and falling edge
	EIMSK |= (1<<INT3);								// Locally enable Interrupt for INT3	
	
	// Initialize Timer1 for receiving
	TCCR1B = TCCR1B | (1<<WGM13) | (1<<WGM12);							// Set Timer1 to CTC-Mode with ICR1 as TOP
	ICR1 = fICR;														// Set TOP Value				
	OCR1A = fOCR1A;														// Set threshold for COMP_A
	OCR1B = fOCR1B;														// Set threshold for COMP_B
	TIMSK0 = TIMSK0 | (1<<OCIE0B) | (1<<OCIE0A) | (1<<ICIE1);			//COMP_A, COMP_B  and Input capture as overflow
	
	// Initialize Interrupt1 for Input-Counter
	DDRD &= ~(1<<DDD1);								// Initialize PD1 as Input
	EIMSK = EIMSK | (1<<INT1);						// locally enable Interrupt for INT1
	EICRA = EICRA | (1<<ISC10) | (1<<ISC11);		// set INT1 to generate an interrput at the falling edge
	
	
	// Initialize Timer3 for sending
	TCCR3B = TCCR3B | (1<<WGM33) | (1<<WGM32);		// Set Timer1 to CTC-Mode with ICR3 as TOP 
	ICR3 = TOP_TX;									// Set TOP Value
	TIMSK3 |= (1 << ICIE3);							// Enable Interrupt on ICIE3
	
}


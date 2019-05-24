/*
 * RF_ID.c
 *
 * Created: 15.03.2019 14:47:50
 * Author : mlm20
 * 
 * Specifications:
 *	Shift register SIPO on PORTB
 * 	Data stored MSB first
 * 	Shift data on send
 * 	Bit width 1,37ms
 * 	Send MSB first
 * 	2 Startbits
 * 	Hamming Code 11/4
 */ 

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "includes/RF_ID.h"

#define TEST_TX_MACRO
#define TEST_RX


// ------------- Random comments ----------------------------------------------------------------
//PD7 ... Flipp low power LED




int main(){
	// --------- CLK_IO = 16MHz -----------
	CLKPR = 0x80;
	CLKPR = 0x00;		
	
	
	RfIDinit();		
	sei();	
	
	#ifdef TEST_TX_MACRO
	char current = '0';
	char data[TX_DATA_LENGTH];
	for(int i = 0; i < TX_DATA_LENGTH; i++)
	{
		if(current == '0')
		{
			data[i] = current;
			current = '1';
		}
		else
		{
			data[i] = current;
			current = '0';
		}
	}
	RF_ID_SEND(data);
	#endif // TEST_TX_MACRO


	// Never ever forget the while!!!!!!!!!!!!!!!!!!!!!!
	while(1)
	{
		#ifdef TEST_RX
			DDRD |= (1 << DDD4);
			
			if(RXflag == TRUE)
			{
				for(int i = 0; i < RX_DATA_LENGTH; i++);
			}
		#endif //TEST_RX
	}
	
	
	
	
	
	
	
	return 0;
}

ISR(TIMER1_COMPA_vect)
{
	// First routine to be triggered when something received
	if (Gcounter >= 0)
	{
		GsaveD[Gcounter] = RX_PORT & RX_PIN_MASK;
	}
	
	Gcounter++;
	
}


ISR(TIMER1_COMPB_vect)
{
	// Second routine to be triggered when something received
	
	if (Gcounter >= 0)
	{
		GsaveD[Gcounter] = RX_PORT & RX_PIN_MASK;
	}
	
	Gcounter++;
	
}


ISR(TIMER1_CAPT_vect)
{
	// Ends the transaction
	
	Gcounter = -4;
	RXflag = true;
	
	TCCR1B = TCCR1B & ~(1<<CS10) & ~(1<<CS11) & ~(1<<CS12);		//Timer1 stopped
	
}

ISR(INT1_vect)
{
	InputCounter++;
	if (InputCounter == 7)
	{
		INPUT_MSB_FIRST(PORTB);
		InputCounter = 0;
	}
}

ISR(INT3_vect)
{
	// Reset TCNT1
	TCNT1 = 0;

}

ISR(TIMER3_CAPT_vect)
{
	// Send Interrupt
	if ( GsendCounter < TX_DATA_LENGTH)
	{
		if(GsendData[GsendCounter] == '1')
		{
			TX_PORT |= TX_PIN_MASK;
		}
		else
		{
			TX_PORT &= ~TX_PIN_MASK;
		}
		
		GsendCounter++;
	} 
	else
	{
		GsendCounter = 0;
		TCCR3B &= ~(1 << CS32) & ~(1 << CS31) & ~(1 << CS30);			// Deactivate Timer3
		TCNT3 = 0;														// Reset Timer3
		TX_PORT |= TX_PIN_MASK;
	}
	
}
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

//PD7 Flipp low power LED

char GsaveD[22] = {0};
char Gcounter = -4;

 char GsendData[26];
 char GsendCounter;


int main(){
	// --------- CLK_IO = 16MHz -----------
	CLKPR = 0x80;
	CLKPR = 0x00;
	
	DDRD = 0xff;
	DDRC |= (1 << DDC6);
	
	//TIMSK1 = TIMSK1 | (1<<OCIE1A) | (1<<OCIE1B);
	/*
	 GsendCounter = 0;
	 GsendData[26];
	
	char current = '1';
	
	for(int i = 0; i < 26; i++)
	{
		if(current == '1')
		{
			GsendData[i] = current;
			current = '0';
		}
		else
		{
			GsendData[i] = current;
			current = '1';
		}
	}
	*/
	RfIDinit();
	TCCR3A |= (1 << COM3A0);
	
	sei();
	
	TCCR3B |= (1 << CS30);				// Start Timer3 (Set divider to 1)
	
	
	
	
	
	
	return 0;
}
/*
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
	
	TCCR1B = TCCR1B & ~(1<<CS10) & ~(1<<CS11) & ~(1<<CS12);		//Timer1 stopped
	
}

ISR(INT3_vect)
{
	// Reset TCNT1
	TCNT1 = 0;

}
*/
ISR(TIMER3_COMPA_vect)
{
	 
	/*
	// Send Interrupt
	if ( GsendCounter < 22)
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
		TCCR3B &= ~(1 << CS32) & ~(1 << CS31) & ~(CS30);			// Deactivate Timer3
		TCNT3 = 0;													// Reset Timer3
	}
	*/
	
	PORTD ^=0xff;
	
}


	
	
	
	
	
	

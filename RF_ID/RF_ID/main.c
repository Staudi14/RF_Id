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


int main(){
	// --------- CLK_IO = 16MHz -----------
	CLKPR = 0x80;
	CLKPR = 0x00;
	

	
	RfIDinit();
	sei();
	
	
	
	
	return 0;
}

ISR(TIMER1_COMPA_vect)
{
	// First routine to be triggered when something received
}


ISR(TIMER1_COMPB_vect)
{
	// Second routine to be triggered when something received
}


ISR(TIMER1_OVF_vect)
{
	// Ends the transaction
}

ISR(INT3_vect)
{
	//Reset TNT1
	TCNT1 = 0;

}


	
	
	
	
	
	

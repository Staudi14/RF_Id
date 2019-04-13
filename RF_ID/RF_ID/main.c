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
#include <AVR/io.h>

#include "includes/RF_ID.h"



int main(){
	DDRB = 0x00;
	DDRD = 0xff;
	
	PORTD = INPUT_MSB_FIRST(PINB);
	
	
	return 0;
}


	
	
	
	
	
	

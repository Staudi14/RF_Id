/*
 * RF_ID.c
 *
 * Created: 15.03.2019 14:47:50
 * Author : mlm20
 */ 

#include <stdio.h>
#include <string.h>
#include <AVR/io.h>


int main(){
	DDRB = 0x00;
	
	einlesenMSBfirst();
	
	return 0;
}

char einlesenMSBfirst()
{
		char input[] = PORTB;

		int length = strlen(input);				
		int last_pos = length-1;				
		for(int i = 0; i < length/2; i++)		
		{
			char tmp = input[i];				
			input[i] = input[last_pos - i];		
			input[last_pos - i] = tmp;			
		}
	
		return input;
}
	
	
	
	
	
	

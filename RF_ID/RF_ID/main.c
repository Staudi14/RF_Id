/*
 * RF_ID.c
 *
 * Created: 15.03.2019 14:47:51
 * Author : mlm20
 */ 

#include <avr/io.h>


char einlesen();

int main(void)
{
   //initialisierung für das Einlesen
   DDRB = 0x00;		//PortB als INPUT
   
  
	
}

char einlesenMSBfirst(){
	int i;
	char helptaround1;
	char helptaround2;
	char intputLSBfirst;
	char taroundMSBfirst;
	int x = 0;
	
	intputLSBfirst = PINB;			//lesen des PortPins
	
	for (i=7; i>=1; i=i-4)
	{
		helptaround1 = intputLSBfirst & (0b00000001 | (1<<x));		//letzte Stelle des eingelesenen Wertes mit der Maske hervorheben, so dass man nur eine 1 hat und sonst nur 0
		helptaround1 = helptaround1 | (1<<i);						//so verschieben, dass man es an der Richtigen Stelle hat(umgedreht)
		x++;
		helptaround2 = intputLSBfirst & (0b00000001 | (1<<x));
		helptaround2 = helptaround2 | (1<<(i-2));
		x++;
		taroundMSBfirst = taroundMSBfirst | helptaround1 | helptaround2;	//verodern, das man MSB first hat
		
	}
	
	
}
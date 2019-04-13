/*
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
#include <stdlib.h>

#include "includes/RF_ID.h"



int main (void)
{
    printf("%d", INPUT_MSB_FIRST(1));

    return 0;
}
#include "RF_ID.h"

void rfIDinit()
{
	RX_PORT = RX_PIN_MASK;
	INPUT_PORT_DDR = 0x00;
	
}
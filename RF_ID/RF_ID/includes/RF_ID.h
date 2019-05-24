#ifndef RF_ID_HEADER
#define RF_ID_HEADER

#include <stdio.h>

//Pin definitions
/************************************************************************************
 *	RX-Pin				PD3 (INT3)				// Must be a Pin with External Interrupt capabilities
 *	TX-Pin				PD2
 *	Data-Port			PORTB
 ***************************************************************************************/

#define RX_PIN_MASK 0x08
#define RX_PORT PORTD
#define RX_PORT_DDR DDRD

#define TX_PIN_MASK 0x04
#define TX_PORT PORTD
#define TX_PORT_DDR DDRD

#define DATA_INPUT_PORT PORTB
#define DATA_INPUT_PORT_DDR DDRB




// -------------------------Parameters---------------------------------------------------
#define DATA_LENGTH 8

// RX-Timer
#define fICR 27399
#define fOCR1A 5479
#define fOCR1B 16439

// TX-Timer
#define TOP_TX 11039

// TX General
#define TX_DATA_LENGTH 26

// RX General
#define  RX_DATA_LENGTH 22

// General
#define  TRUE 1
#define FALSE 0


// -----------------------Extern Variables------------------------------------------------
// RX variables
extern char GsaveD[RX_DATA_LENGTH + 1];
extern int8_t Gcounter;
extern char RXflag;

//TX variables
extern char GsendData[TX_DATA_LENGTH];
extern int8_t GsendCounter;


// ---------------------------Macros-----------------------------------------------------
/*!
 *@function		INPUT_MSB_FIRST
 *@abstract		Reads input from given Port
 *@discussion	Read input from given Port and saves it MSB first as char array then returns it
 *@param		input       Gets the to processing value and stores it MSB first
 *@result		The input value returned with MSB first
*/
#define INPUT_MSB_FIRST(input)  ({                                                      \
	unsigned char ret[DATA_LENGTH];                                                              \
	char tmp = input;                                                                   \
	do {                                                                                \
		for (int i = 0; i < DATA_LENGTH; i++)                                           \
		{                                                                               \
			ret[DATA_LENGTH - 1 - i] = (((1 << i) & tmp) == (1 << i) ? 1 : 0) ;   \
		}                                                                               \
	} while(0);                                                                         \
	ret;                                                                                    \
	})

/*
 *@function					RfIDsend
 *@abstract					Handles the transmission of the given data
 *@discussion				Calculates the Hamming code of the given and also encodes it to
 *							Manchester code then handles the correct set up of the timer
 *							and assigns the encoded data to GsendData.
 *@param		data		Is the pointer to the to transmitted data
 */
#define RF_ID_SEND(data) ({																\
	for(int i = 0; i < TX_DATA_LENGTH; i++)												\
	{																					\
		GsendData[i] = data[i];															\
	}																					\
	GsendCounter = 	0;																	\
																						\
	TCCR3B |= (1 << CS30);		/* Start Timer3 (Set divider to 1) */					\
	})


// -----------------------------Function Prototypes-----------------------------------------
/*
 *@function		RfIDinit
 *@abstract		Initializes all necessities for the RF_ID header
 *@discussion	Initializes all needed ports, timers, external interrupts and locally
 *				and locally enables all ISR
*/
void RfIDinit();





#endif
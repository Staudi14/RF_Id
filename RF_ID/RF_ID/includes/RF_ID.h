#ifndef RF_ID_HEADER
#define RF_ID_HEADER

//Pin definitions

#define RX_PIN_MASK 0x01
#define RX_PORT PORTD
#define RX_PORT_DDR DDRD

#define DATA_INPUT_PORT PORTB
#define DATA_INPUT_PORT_DDR DDRB




//Parameters
#define DATA_LENGTH 8

#define fICR 27399
#define fOCR1A 5479
#define fOCR1B 16439

//PORTB bei Input Pull-up Register !!!!!, sowie nur ein Byte(8Bit)!!!
//Needed to be changed as the specifications sais that the data must be stored msb first
/*!
 *@function		INPUT_MSB_FIRST
 *@abstract		Reads input from given Port
 *@discussion	Read input from given Port and saves it MSB first as char array then returns it
 *@param		input       Gets the to processing value and stores it MSB first
 *@result		The input value returned with MSB first
*/
#define INPUT_MSB_FIRST(input)  ({                                                      \
    unsigned char ret = 0;                                                              \
    char tmp = input;                                                                   \
    do {                                                                                \
        for (int i = 0; i < DATA_LENGTH; i++)                                           \
        {                                                                               \
            ret |= ((((1 << i) & tmp) == (1 << i) ? 1 : 0) << (DATA_LENGTH - 1 - i));   \
        }                                                                               \
    } while(0);                                                                         \
ret;                                                                                    \
})

/*
 *@function		RfIDinit
 *@abstract		Initailizes all necessarities for the RF_ID header
 *@discussion	Initializes all needed ports, timers, external interrupts and locally
 *				and locally enables all ISR
*/

void RfIDinit();


#endif
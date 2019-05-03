#ifndef RF_ID_HEADER
#define RF_ID_HEADER

//Parameters
#define DATA_LENGTH 8

//PORTB bei Input Pull-up Register !!!!!, sowie nur ein Byte(8Bit)!!!
//Needed to be changed as the specifications sais that the data must be stored msb first
/*!
 *@function    INPUT_MSB_FIRST
 *@param       input       Gets the to processing value and stores it MSB first
 *@result      The input value returned with MSB first
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
//Test


#endif
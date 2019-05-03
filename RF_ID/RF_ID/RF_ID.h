#ifndef RF_ID_HEADER
#define RF_ID_HEADER

//Parameters
#define DATA_LENGTH 7

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
            ret |= ((((1 << i) & tmp) == (1 << i) ? 1 : 0) << (DATA_LENGTH - 1 - i));   \  //: vergleich ?wenns true ist setzt er 1 ein wenn es false ist setzt er 0 ein
        }                                                                               \
    } while(0);                                                                         \
ret;                                                                                    \
})

//Manchester

#define MANCHESTER_CODIERUNG(daten) ({
    int i;
    
    for(i=0;i<11;i++){
        
    }

})

#endif


#include "ASA_DIO.h"

char M128_DIO_set(char LSByte, char Mask, char shift, char Data) {
    if(LSByte>7)
        return 1;
    else if(shift>7)
        return 2;

    Data=(Data<<shift);
    volatile uint8_t *PORT;
    volatile uint8_t *DDR;
    volatile uint8_t *PIN;
    switch(LSByte) {
        case 0: PORT = &PORTA; DDR = &DDRA; PIN = &PINA; break;
        case 1: PORT = &PORTB; DDR = &DDRB; PIN = &PINB; break;
        case 2: PORT = &PORTC; DDR = &DDRC; PIN = &PINC; break;
        case 3: PORT = &PORTD; DDR = &DDRD; PIN = &PIND; break;
        case 4: PORT = &PORTE; DDR = &DDRE; PIN = &PINE; break;
        case 5: PORT = &PORTF; DDR = &DDRF; PIN = &PINF; break;
        case 6: PORT = &PORTG; DDR = &DDRG; PIN = &PING; break;
        default: return 1;
    }
    *DDR |= (Data&Mask);
    return 0;
}

char M128_DIO_fpt(char LSByte, char Mask, char shift, char Data) {
    if(LSByte>7)
        return 1;
    else if(shift>7)
        return 2;

    Data=(Data<<shift);
    volatile uint8_t *PORT;
    volatile uint8_t *DDR;
    volatile uint8_t *PIN;
    switch(LSByte) {
        case 0: PORT = &PORTA; DDR = &DDRA; PIN = &PINA; break;
        case 1: PORT = &PORTB; DDR = &DDRB; PIN = &PINB; break;
        case 2: PORT = &PORTC; DDR = &DDRC; PIN = &PINC; break;
        case 3: PORT = &PORTD; DDR = &DDRD; PIN = &PIND; break;
        case 4: PORT = &PORTE; DDR = &DDRE; PIN = &PINE; break;
        case 5: PORT = &PORTF; DDR = &DDRF; PIN = &PINF; break;
        case 6: PORT = &PORTG; DDR = &DDRG; PIN = &PING; break;
        default: return 1;
    }
    *PORT=(*PORT&~Mask)|(Data&Mask);
    return 0;
}

char M128_DIO_fgt(char LSByte, char Mask, char shift, char *Data) {
    if(LSByte>7)
        return 1;
    else if(shift>7)
        return 2;
    // BUG set DDR if DDR bit is 1 ?
    volatile uint8_t *PORT;
    volatile uint8_t *DDR;
    volatile uint8_t *PIN;
    switch(LSByte) {
        case 0: PORT = &PORTA; DDR = &DDRA; PIN = &PINA; break;
        case 1: PORT = &PORTB; DDR = &DDRB; PIN = &PINB; break;
        case 2: PORT = &PORTC; DDR = &DDRC; PIN = &PINC; break;
        case 3: PORT = &PORTD; DDR = &DDRD; PIN = &PIND; break;
        case 4: PORT = &PORTE; DDR = &DDRE; PIN = &PINE; break;
        case 5: PORT = &PORTF; DDR = &DDRF; PIN = &PINF; break;
        case 6: PORT = &PORTG; DDR = &DDRG; PIN = &PING; break;
        default: return 1;
    }
    *Data=(*PIN&(~Mask))>>shift;
    return 0;
}

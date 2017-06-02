#include "ASA_DIO.h"
#include "ASA_DEVICE.h"
#include "bit_op.h"

char M128_DIO_set(char LSByte, char Mask, char shift, char Data) {
    if(LSByte<200||LSByte>206)
        return 1;
    else if(shift>7)
        return 2;

    volatile uint8_t *PORT;
    volatile uint8_t *DDR;
    volatile uint8_t *PIN;
    switch(LSByte) {
        case 200: PORT = &PORTA; DDR = &DDRA; PIN = &PINA; break;
        case 201: PORT = &PORTB; DDR = &DDRB; PIN = &PINB; break;
        case 202: PORT = &PORTC; DDR = &DDRC; PIN = &PINC; break;
        case 203: PORT = &PORTD; DDR = &DDRD; PIN = &PIND; break;
        case 204: PORT = &PORTE; DDR = &DDRE; PIN = &PINE; break;
        case 205: PORT = &PORTF; DDR = &DDRF; PIN = &PINF; break;
        case 206: PORT = &PORTG; DDR = &DDRG; PIN = &PING; break;
        default: return 1;
    }
    bits_put(*DDR,Data,Mask,shift);
    // Data=(Data<<shift);
    // *DDR = (*DDR&(~Mask))|(Data&Mask);
    return 0;
}

char M128_DIO_fpt(char LSByte, char Mask, char shift, char Data) {
    if(LSByte>7)
        return 1;
    else if(shift>7)
        return 2;

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
    bits_put(*PORT,Data,Mask,shift);
    // Data=(Data<<shift);
    // *PORT=(*PORT&~Mask)|(Data&Mask);
    return 0;
}

char M128_DIO_fgt(char LSByte, char Mask, char shift, char *Data) {
    if(LSByte<100||LSByte>106)
        return 1;
    else if(shift>7)
        return 2;

    volatile uint8_t *PORT;
    volatile uint8_t *DDR;
    volatile uint8_t *PIN;
    switch(LSByte) {
        case 100: PORT = &PORTA; DDR = &DDRA; PIN = &PINA; break;
        case 101: PORT = &PORTB; DDR = &DDRB; PIN = &PINB; break;
        case 102: PORT = &PORTC; DDR = &DDRC; PIN = &PINC; break;
        case 103: PORT = &PORTD; DDR = &DDRD; PIN = &PIND; break;
        case 104: PORT = &PORTE; DDR = &DDRE; PIN = &PINE; break;
        case 105: PORT = &PORTF; DDR = &DDRF; PIN = &PINF; break;
        case 106: PORT = &PORTG; DDR = &DDRG; PIN = &PING; break;
        default: return 1;
    }
    *Data = bits_get(*PIN,Mask,shift);
    // *Data=(*PIN&(Mask))>>shift;
    return 0;
}

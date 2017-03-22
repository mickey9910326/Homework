#ifndef __ASA_DIO_h__
#define __ASA_DIO_h__

#include <avr/io.h>

char M128_DIO_set(char LSByte, char Mask, char shift, char Data);
char M128_DIO_fpt(char LSByte, char Mask, char shift, char Data);
char M128_DIO_fgt(char LSByte, char Mask, char shift, char *Data);
// PORTA ：LSByte=200,
// PORTB ：LSByte=201,
// PORTC ：LSByte=202,
// PORTD ：LSByte=203,
// PORTE ：LSByte=204,
// PORTF ：LSByte=205,
// PORTG ：LSByte=206,
#endif

#ifndef __ASA_DIO_h__
#define __ASA_DIO_h__

#include <avr/io.h>

char M128_DIO_set(char LSByte, char Mask, char shift, char Data);
char M128_DIO_fpt(char LSByte, char Mask, char shift, char Data);
char M128_DIO_fgt(char LSByte, char Mask, char shift, char *Data);

#define ADDR_PORT_num 1
#define ADDR_PORT_msk (1<<5)|(1<<6)|(1<<7)
#define ADDR_PORT_sht 5
// SPI ADDR use PORTB bit 5,6,7 as id 0~7
// use DIO_put to set ADDR

#endif

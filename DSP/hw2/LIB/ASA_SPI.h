#ifndef __ASA_SPI_H__
#define __ASA_SPI_H__

#include <avr/io.h>
#include "ASA_DIO.h"

char M128_SPI_swap(char cData);
char SPI_Transmit(char cData);
char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data);
char M128_SPI_put(char NoAdd, char Addr, char Bytes, void *Data_p);
char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p);

#define DDR_SPI_num 1
#define DD_MISO DDB1
#define DD_MOSI DDB2
#define DD_SCK  DDB1
#define DD_SS   DDB0
// SPI use PORTB

#define CS_pin PF4
#define CS_PORT_NUM 5
#define CS_PORT_MSK (1<<CS_pin)
#define CS_PORT_SHT CS_pin
// CS : PF5

#define ADDR_PORT_num 1
#define ADDR_PORT_msk (1<<5)|(1<<6)|(1<<7)
#define ADDR_PORT_sht 5
// SPI ADDR use PORTB bit 5,6,7 as id 0~7
// use DIO_put to set ADDR

#endif

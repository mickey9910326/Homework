#ifndef __ASA_TMP121_H__
#define __ASA_TMP121_H__

#include "ASA_DIO.h"
#include "ASA_SPI.h"
#include <avr/io.h>
#include <util\delay.h>

void ASA_TMP121_ini();
void ASA_TMP121_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);


#define ADDR_PORT_num 1
#define ADDR_PORT_msk (1<<5)|(1<<6)|(1<<7)
#define ADDR_PORT_sht 5
// SPI ADDR use PORTB bit 5,6,7 as id 0~7
// use DIO_put to set ADDR

#endif

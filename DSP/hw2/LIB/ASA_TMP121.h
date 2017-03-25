#ifndef __ASA_TMP121_H__
#define __ASA_TMP121_H__

#include "ASA_DIO.h"
#include "ASA_SPI.h"
#include <avr/io.h>
#include <util\delay.h>

void ASA_TMP121_ini();
void ASA_TMP121_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

#endif

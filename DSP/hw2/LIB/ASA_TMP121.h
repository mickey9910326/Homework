#ifndef __ASA_TMP121_H__
#define __ASA_TMP121_H__

#include "ASA_Lib.h"
#include <util\delay.h>

void ASA_TMP121_ini();
void ASA_TMP121_get(char ASA_ID, char LSByte, char Bytes, void *Data_p);

#endif

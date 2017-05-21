#ifndef __ASA_CORE_SPI_H__
#define __ASA_CORE_SPI_H__

char ASA_SPI_swap(char data);
char ASA_SPI_set(char LSByte, char Mask, char shift, char Data);
char ASA_SPI_put(char LSByte, char Bytes, void *Data_p);
char ASA_SPI_get(char LSByte, char Bytes, void *Data_p);
char ASA_SPI_fpt(char LSByte, char Mask, char shift, char Data);
char ASA_SPI_fgt(char LSByte, char Mask, char shift, char* Data_p);
#endif

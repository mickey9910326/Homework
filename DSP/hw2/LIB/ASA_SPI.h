#ifndef __ASA_SPI_H__
#define __ASA_SPI_H__

char M128_SPI_swap(char cData);
char SPI_Transmit(char cData);
char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data);
char M128_SPI_put(char NoAdd, char Addr, char Bytes, void *Data_p);
char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p);


#endif

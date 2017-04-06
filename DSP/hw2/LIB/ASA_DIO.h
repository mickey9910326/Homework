#ifndef __ASA_DIO_h__
#define __ASA_DIO_h__

char M128_DIO_set(char LSByte, char Mask, char shift, char Data);
char M128_DIO_fpt(char LSByte, char Mask, char shift, char Data);
char M128_DIO_fgt(char LSByte, char Mask, char shift, char *Data);

#endif

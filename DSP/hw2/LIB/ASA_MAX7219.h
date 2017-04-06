#ifndef __ASA_MAX7219_H__
#define __ASA_MAX7219_H__

void ASA_MAX7219_ini();
char ASA_MAX7219_set(char ASA_ID, char LSByte, char Blocks, char Mask, char shift, char *Data_p);
char ASA_MAX7219_put(char ASA_ID, char LSByte, char Blocks, void *Data_p);
char ASA_MAX7219_put2(char ASA_ID, char LSByte, char Blocks,char Num, void *Data_p);

#endif

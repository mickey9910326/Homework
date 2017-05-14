#ifndef __ASA_slave_SPI_h__
#define __ASA_slave_SPI_h__

#define CALLTYPE_SET 0
#define CALLTYPE_PUT 1
#define CALLTYPE_GET 2
#define CALLTYPE_FPT 3
#define CALLTYPE_GPT 4

typedef struct {
    char statuse;
    TypeOfBuffer *OutBUFF_p;
    TypeOfBuffer *InBUFF_p;
} TypeOfslave_SPI_swap;

// slave <-> master 通訊
char ASA_Slave_set(char LSByte, char Mask, char shift, char Data);
char ASA_Slave_put(char LSByte, char Bytes, void *Data_p);
char ASA_Slave_get(char LSByte, char Bytes, void *Data_p);
char ASA_Slave_fpt(char LSByte, char Mask, char shift, char Data);
char ASA_Slave_fgt(char LSByte, char Mask, char shift, char* Data_p);

char command_run( char CallType, char Bytes, char* Data_p, char* Get_Data_p );
char slave_SPI_swap_step();
void slave_SPI_swap_ini(TypeOfslave_SPI_swap *str_p, TypeOfBuffer *OutBuff_p, TypeOfBuffer *InBuff_p);

#endif

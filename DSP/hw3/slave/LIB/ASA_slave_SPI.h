#ifndef __ASA_slave_SPI_h__
#define __ASA_slave_SPI_h__

#include "buffer.h"

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

typedef struct {
    char statuse;
    TypeOfBuffer* InBUFF_p;
    TypeOfBuffer* OutBUFF_p;
    char CallType;
    char LSByte;
    char Bytes;
    char Mask;
    char Shift;
    void* Data_p;
    char CheckSum;
} TypeOfSlave_SPI_PacDe;


char command_run( char CallType, char Bytes, char* Data_p, char* Get_Data_p );
char slave_SPI_swap_step();
void slave_SPI_swap_ini(TypeOfslave_SPI_swap *str_p, TypeOfBuffer *OutBuff_p, TypeOfBuffer *InBuff_p);
void slave_SPI_PacDe_ini(TypeOfSlave_SPI_PacDe* str_p,TypeOfBuffer* OutBuff_p,TypeOfBuffer* InBuff_p);
char slave_SPI_PacDe_step(TypeOfSlave_SPI_PacDe* str_p);
#endif

#ifndef __ASA_slave_SPI_h__
#define __ASA_slave_SPI_h__

#define MAXBUFFBYTES 32

typedef struct {
    unsigned char PUTindex; // data end index + 1
    unsigned char GETindex; // data start index
    char data[MAXBUFFBYTES]; // FIFO array
} TypeOfBuffer;

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

char buffer_get_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p);
char buffer_put_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p);

char buffer_get(TypeOfBuffer* Buffer_p, char* Data_p);
char buffer_put(TypeOfBuffer* Buffer_p, char Data);
void buffer_clear(TypeOfBuffer* Buffer_p);

#endif

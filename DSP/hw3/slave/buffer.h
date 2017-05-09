#ifndef __buffer_h__
#define __buffer_h__

#define MAXBUFFBYTES 32

typedef struct {
    char PUTindex; // data end index + 1
    char GETindex; // data start index
    char data[MAXBUFFBYTES]; // FIFO array
} TypeOfBuffer;

char get_buffer_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p);
char put_buffer_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p);



#endif

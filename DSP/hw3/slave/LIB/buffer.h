#ifndef __buffer_h__
#define __buffer_h__

#define MAXBUFFBYTES 32

typedef struct {
    unsigned char PUTindex; // data end index + 1
    unsigned char GETindex; // data start index
    char data[MAXBUFFBYTES]; // FIFO array
} TypeOfBuffer;

char buffer_get_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p);
char buffer_put_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p);

char buffer_get(TypeOfBuffer* Buffer_p, char* Data_p);
char buffer_put(TypeOfBuffer* Buffer_p, char* Data_p);
void buffer_clear(TypeOfBuffer* Buffer_p);

#endif

// change "char GETindex" to "unsigned char GETindex"
// avoid gain AVR-GCC Warnings " array subscript has type 'char' "
// when try to get TypeOfBuffer.data[GETindex]; (index with sign)

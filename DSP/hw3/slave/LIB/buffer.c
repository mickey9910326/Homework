#include <string.h>
#include "buffer.h"

char buffer_get_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p) {
    //get data in BUFFER

    char AvailableBytes ;
    if (Buffer_p->PUTindex >= Buffer_p->GETindex) {
        AvailableBytes = Buffer_p->PUTindex - Buffer_p->GETindex;
    } else {
        AvailableBytes = MAXBUFFBYTES - (Buffer_p->PUTindex - Buffer_p->GETindex) ;
    }
    if (AvailableBytes<Bytes) {
        // BUFFER is not enough to get
        return 1;
    }

    // handle the case that index out of the array size (MAXBUFFBYTES)
    if ( Buffer_p->GETindex + Bytes > MAXBUFFBYTES) {
        // get (MAXBUFFBYTES-Buffer_p->GETindex) bytes and do next
        char usingBytes = MAXBUFFBYTES-Buffer_p->GETindex;
        strncpy( Data_p, Buffer_p->data+Buffer_p->GETindex, usingBytes );
        Bytes -= usingBytes;
        Buffer_p->GETindex = 0;
        buffer_get_bytes(Buffer_p,Bytes,Data_p+usingBytes);
    } else {
        strncpy( Data_p, Buffer_p->data+Buffer_p->GETindex, Bytes );
        Buffer_p->GETindex += Bytes;
    }

    return 0;
    // Buffer_p->GETindex
}

char buffer_put_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p) {
    //put data in BUFFER

    char AvailableBytes;
    if (Buffer_p->PUTindex >= Buffer_p->GETindex) {
        AvailableBytes = MAXBUFFBYTES - Buffer_p->PUTindex + Buffer_p->GETindex;
    } else {
        AvailableBytes = Buffer_p->GETindex - Buffer_p->PUTindex  ;
    }
    if (AvailableBytes<Bytes) {
        return 1;
    }

    // handle the case that index out of the array size (MAXBUFFBYTES)
    if ( Buffer_p->PUTindex + Bytes > MAXBUFFBYTES) {
        // put (MAXBUFFBYTES-Buffer_p->PUTindex) bytes and do next
        char usingBytes = MAXBUFFBYTES-Buffer_p->PUTindex;
        strncpy( Buffer_p->data+Buffer_p->PUTindex , (char *)Data_p , usingBytes );
        Bytes -= usingBytes ;
        Buffer_p->PUTindex = 0;
        buffer_put_bytes(Buffer_p,Bytes,Data_p+usingBytes);
    } else {
        strncpy( Buffer_p->data+Buffer_p->PUTindex , (char *)Data_p , Bytes );
        Buffer_p->PUTindex += Bytes;
    }

    return 0;
    // Buffer_p->GETindex
}


char buffer_get(TypeOfBuffer* Buffer_p, char* Data_p) {
    //get 1 byte data in BUFFER
    if (Buffer_p->PUTindex != Buffer_p->GETindex) {
        *Data_p = Buffer_p->data[Buffer_p->GETindex];
        Buffer_p->GETindex = (Buffer_p->GETindex + 1) % MAXBUFFBYTES;
        return 0;
    }
    return 1;
}

char buffer_put(TypeOfBuffer* Buffer_p, char* Data_p) {
    //put 1 byte data to BUFFER
    if ( ((Buffer_p->PUTindex +1)%MAXBUFFBYTES) != Buffer_p->GETindex) {
        Buffer_p->data[Buffer_p->PUTindex] = *Data_p;
        Buffer_p->PUTindex = (Buffer_p->PUTindex + 1) % MAXBUFFBYTES;
        return 0;
    }
    return 1;
}

void buffer_clear(TypeOfBuffer* Buffer_p){
    Buffer_p->GETindex = 0;
    Buffer_p->PUTindex = 0;
}

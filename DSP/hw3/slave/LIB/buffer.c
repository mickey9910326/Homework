#include <string.h>
#include "buffer.h"

char get_buffer_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p) {
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
        get_buffer_bytes(Buffer_p,Bytes,Data_p+usingBytes);
    } else {
        strncpy( Data_p, Buffer_p->data+Buffer_p->GETindex, Bytes );
        Buffer_p->GETindex += Bytes;
    }

    return 0;
    // Buffer_p->GETindex
}

char put_buffer_bytes(TypeOfBuffer* Buffer_p, char Bytes, void *Data_p) {
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
        put_buffer_bytes(Buffer_p,Bytes,Data_p+usingBytes);
    } else {
        strncpy( Buffer_p->data+Buffer_p->PUTindex , (char *)Data_p , Bytes );
        Buffer_p->PUTindex += Bytes;
    }

    return 0;
    // Buffer_p->GETindex
}

#include "ASA_IC.h"

char ic_set(char LSByte, char Mask, char shift, char Data) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

char ic_put(char LSByte, char Bytes, void *Data_p) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

char ic_get(char LSByte, char Bytes, void *Data_p) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

char ic_fpt(char LSByte, char Mask, char shift, char Data) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

char ic_fgt(char LSByte, char Mask, char shift, char* Data_p) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

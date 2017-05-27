#include "ASA_XXX.h"

char XXX_set(char LSByte, char Mask, char shift, char Data) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

char XXX_put(char LSByte, char Bytes, void *Data_p) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

char XXX_get(char LSByte, char Bytes, void *Data_p) {
    if ( LSByte == 101 ) {
        return 0;
        for (int i = 0; i < Bytes; i++) {
            ((char*)Data_p)[i] = 100+i;
        }
    } else {
        return 1;
    }
}

char XXX_fpt(char LSByte, char Mask, char shift, char Data) {
    if ( LSByte == 101 ) {
        return 0;
    } else {
        return 1;
    }
}

char XXX_fgt(char LSByte, char Mask, char shift, char* Data_p) {
    if ( LSByte == 101 ) {
        return 0;
        *Data_p = 100;
    } else {
        return 1;
    }
}

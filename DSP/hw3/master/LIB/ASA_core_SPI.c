#include "ASA_core_SPI.h"
#include <avr/io.h>
#include "ASA_SPI.h"
#include "bit_op.h"
#include "ASA_DIO.h"
#include <util\delay.h>
#include "ASA_general.h"

#define CALLTYPE_SET 0
#define CALLTYPE_GET 1
#define CALLTYPE_PUT 2
#define CALLTYPE_FPT 3
#define CALLTYPE_FGT 4

char ASA_SPI_swap(char data) {
    char res = data;
    M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
    M128_SPI_put(1,0,1,&res);
    M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
    return res;
}

char ASA_SPI_set(char LSByte, char Mask, char shift, char Data) {
    char CheckSum = 0;
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    CheckSum += CALLTYPE_PUT;
    ASA_SPI_swap(CALLTYPE_PUT);
    CheckSum += LSByte;
    ASA_SPI_swap(LSByte);
    CheckSum += Mask;
    ASA_SPI_swap(Mask);
    CheckSum += shift;
    ASA_SPI_swap(shift);
    ASA_SPI_swap(CheckSum);

    unsigned char status = 0,count=0,times=0;
    char GetData = 0;
    char RetVal=100;
    while ( status != 3 ) {
        GetData = ASA_SPI_swap(0);
        switch(status) {
            case 2:
                // handle data
                times++;
                if ( GetData == 0xAB ) {
                    count ++;
                } else {
                    _delay_us(1);
                    count = 0;
                }
                if (count==3) {
                    status = 1;
                    count  = 0;
                    times  = 0;
                }
                if (times == 30) { //timeout?
                    status = 3;
                }
                break;
            case 1:
                RetVal = GetData;
                status = 2;
                break;
        }
    }
    return RetVal;
};

char ASA_SPI_put(char LSByte, char Bytes, void *Data_p) {
    char CheckSum = 0;
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    CheckSum += CALLTYPE_PUT;
    ASA_SPI_swap(CALLTYPE_PUT);
    CheckSum += LSByte;
    ASA_SPI_swap(LSByte);
    CheckSum += Bytes;
    ASA_SPI_swap(Bytes);

    for (unsigned char i = 0; i < Bytes; i++) {
        CheckSum += ((char*)Data_p)[i];
        ASA_SPI_swap(((char*)Data_p)[i]);
    }
    ASA_SPI_swap(CheckSum);

    unsigned char status = 0,count=0,times=0;
    char GetData = 0;
    char RetVal=10;
    while ( status != 3 ) {
        GetData = ASA_SPI_swap(0);
        switch(status) {
            case 0:
                // handle data
                times++;
                if ( GetData == 0xAB ) {
                    count ++;
                } else {
                    _delay_us(1);
                    count = 0;
                }
                if (count==3) {
                    status = 1;
                    count  = 0;
                    times  = 0;
                }
                if (times == 30) { //timeout?
                    status = 3;
                }
                break;
            case 1:
                RetVal = GetData;
                status = 2;
                break;
            case 2:
                // handle data
                ((char*)Data_p)[count] = GetData;
                count++;
                if ( count == Bytes ) {
                    status = 3;
                }
        }
    }
    return RetVal;
};
char ASA_SPI_get(char LSByte, char Bytes, void *Data_p) {
    char CheckSum = 0;
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    CheckSum += CALLTYPE_PUT;
    ASA_SPI_swap(CALLTYPE_PUT);
    CheckSum += LSByte;
    ASA_SPI_swap(LSByte);
    CheckSum += Bytes;
    ASA_SPI_swap(Bytes);

    for (unsigned char i = 0; i < Bytes; i++) {
        CheckSum += ((char*)Data_p)[i];
        ASA_SPI_swap(((char*)Data_p)[i]);
    }
    ASA_SPI_swap(CheckSum);

    unsigned char status = 0,count=0,times=0;
    char GetData = 0;
    char RetVal=10;
    while ( status != 3 ) {
        GetData = ASA_SPI_swap(0);
        switch(status) {
            case 0:
                // handle data
                times++;
                if ( GetData == 0xAB ) {
                    count ++;
                } else {
                    _delay_us(1);
                    count = 0;
                }
                if (count==3) {
                    status = 1;
                    count  = 0;
                    times  = 0;
                }
                if (times == 30) { //timeout?
                    status = 3;
                }
                break;
            case 1:
                RetVal = GetData;
                status = 2;
                break;
            case 2:
                // handle data
                ((char*)Data_p)[count] = GetData;
                count++;
                if ( count == Bytes ) {
                    status = 3;
                }
        }
    }
    return RetVal;
};
char ASA_SPI_fpt(char LSByte, char Mask, char shift, char Data) {
    char CheckSum = 0;
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    CheckSum += CALLTYPE_PUT;
    ASA_SPI_swap(CALLTYPE_PUT);
    CheckSum += LSByte;
    ASA_SPI_swap(LSByte);
    CheckSum += Mask;
    ASA_SPI_swap(Mask);
    CheckSum += Data;
    ASA_SPI_swap(Data);
    ASA_SPI_swap(CheckSum);

    unsigned char status = 0,count=0,times=0;
    char GetData = 0;
    char RetVal=10;
    while ( status != 2 ) {
        GetData = ASA_SPI_swap(0);
        switch(status) {
            case 0:
                // handle data
                times++;
                if ( GetData == 0xAB ) {
                    count ++;
                } else {
                    _delay_us(1);
                    count = 0;
                }
                if (count==3) {
                    status = 1;
                    count  = 0;
                    times  = 0;
                }
                if (times == 30) { //timeout?
                    status = 3;
                }
                break;
            case 1:
                RetVal = GetData;
                status = 2;
                break;
        }
    }
    return RetVal;
};
char ASA_SPI_fgt(char LSByte, char Mask, char shift, char* Data_p) {
    char CheckSum = 0;
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    CheckSum += CALLTYPE_PUT;
    ASA_SPI_swap(CALLTYPE_PUT);
    CheckSum += LSByte;
    ASA_SPI_swap(LSByte);
    CheckSum += Mask;
    ASA_SPI_swap(Mask);
    ASA_SPI_swap(CheckSum);

    unsigned char status = 0,count=0,times=0;
    char GetData = 0;
    char RetVal=10;
    while ( status != 3 ) {
        GetData = ASA_SPI_swap(0);
        switch(status) {
            case 0:
                // handle data
                times++;
                if ( GetData == 0xAB ) {
                    count ++;
                } else {
                    _delay_us(1);
                    count = 0;
                }
                if (count==3) {
                    status = 1;
                    count  = 0;
                    times  = 0;
                }
                if (times == 30) { //timeout?
                    status = 3;
                }
                break;
            case 1:
                RetVal = GetData;
                status = 2;
                break;
            case 2:
                ((char*)Data_p)[0] = GetData;
                status = 3;
        }
    }
    return RetVal;
};

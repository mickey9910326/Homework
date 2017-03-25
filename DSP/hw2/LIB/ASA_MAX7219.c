#include "ASA_MAX7219.h"

#define MAX7219_ADDR_DECODE       0x09
#define MAX7219_ADDR_INTENSITY    0x0A
#define MAX7219_ADDR_SCAN_LIMIT   0x0B
#define MAX7219_ADDR_POWER        0x0C
#define MAX7219_ADDR_TEST         0x0F
#define MAX7219_ADDR_NOOP         0x00

void ASA_MAX7219_ini() {
    // set ADDR pins (PB5~7) as output
    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0));
}

char ASA_MAX7219_set(char ASA_ID, char LSByte, char Blocks, char Mask, char shift, char *Data_p) {
    int i;
    char addr  = 0;
    char bytes = 1;
    char data  = *Data_p;

    switch (LSByte) {
        case 200 :
            // TODO set decode
            if ( data != 1 && data != 0xFF) { return 3; }
            addr = MAX7219_ADDR_DECODE;
            break;
        case 201 :
            // TODO set intensity
            if ( data > 15 ) { return 3; }
            addr = MAX7219_ADDR_INTENSITY;
            break;
        case 202 :
            // TODO set scan limit
            if ( data > 15 ) { return 3; }
            addr = MAX7219_ADDR_SCAN_LIMIT;
            break;
        case 203 :
            // TODO set shutdown
            if ( data > 7 ) { return 3; }
            addr = MAX7219_ADDR_POWER;
            break;
        case 204 :
            // TODO set display test
            if ( data > 1 ) { return 3; }
            addr = MAX7219_ADDR_TEST;
            break;
        default :
            return 1;
    }
    // start communication
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
    for (i = 0; i < Blocks; i++) {
        M128_SPI_put(0,addr,bytes,Data_p+i);
    }
    return 0;
}

char ASA_MAX7219_put(char ASA_ID, char LSByte, char Blocks, void *Data_p) {
    if(LSByte>7) { return 1; }
    char i;
    char addr = LSByte;
    char bytes = 1;
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
    for (i = 0; i < Blocks; i++) {
        M128_SPI_put(0,addr,bytes,Data_p+i);
    }
    return 0;
}

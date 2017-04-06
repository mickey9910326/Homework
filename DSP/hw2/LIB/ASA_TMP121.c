#include "ASA_DIO.h"
#include "ASA_SPI.h"
#include <avr/io.h>
#include <util\delay.h>
#include "ASA_general.h"
#include "ASA_TMP121.h"

void ASA_TMP121_ini() {
    // set ADDR pins (PB5~7) as output
    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR));
}
char ASA_TMP121_get(char ASA_ID, char LSByte, char Bytes, void *Data_p) {
    if(ASA_ID>7)    { return 1; }
    if(LSByte!=100) { return 2; }
    if(Bytes!=2)    { return 3; }

    char data[2],check=0;
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
    _delay_ms(250);
    check = M128_SPI_get(1,0,Bytes,data);
    if ( (data[0]&0b10000000) == 1 ) { // 負號
        *(double*)Data_p = (double)(((~data[0])<<5) + ((~data[1])>>3)+1) *0.0625; //translate 2byte data to temptature
    } else {
        *(double*)Data_p = (double)((data[0]<<5) + (data[1]>>3)) *0.0625; //translate 2byte data to temptature
    }
    if (check) {
        return 4; // WCOL SPI通訊相撞
    }
    return 0;
}

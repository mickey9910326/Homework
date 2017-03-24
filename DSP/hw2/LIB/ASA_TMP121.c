#include "ASA_TMP121.h"

void ASA_TMP121_ini() {
    // set ADDR pins (PB5~7) as output
    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR));
}
void ASA_TMP121_get(char ASA_ID, char LSByte, char Bytes, void *Data_p) {
    char data[2];
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
    _delay_ms(250);          //轉換時間長，CS腳須維持 250ms才能完成一次轉換
    M128_SPI_get(1,0,Bytes,data);
    *(double*)Data_p = (double)((data[0]<<5) + (data[1]>>3)) *0.0625; //translate 2byte data to temptature
    return ;
}

#include "ASA_TMP121.h"

void ASA_TMP121_ini() {
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR));
}
void ASA_TMP121_get(char ASA_ID, char LSByte, char Bytes, void *Data_p) {
    char data[2];
    _delay_ms(250);          //轉換時間長，CS腳須維持 250ms才能完成一次轉換
    M128_SPI_get(0,ASA_ID,Bytes,data);
    *(double*)Data_p = (double)((data[0]<<5) + (data[1]>>3)) *0.0625; //translate 2byte data to temptature
    return ;
}

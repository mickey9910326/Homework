#include "LIB\ASA_Lib.h"
#include "LIB\ASA_SPI.h"
#include "LIB\bit_op.h"

int main(void) {
    ASA_M128_set();
    double TEM;
    uint8_t H,L;
    printf("start!-----------------------------\n");
    char data[2];
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR));
    while (1){
        _delay_ms(250);          //轉換時間長，CS腳須維持 250ms才能完成一次轉換
        M128_SPI_get(0,7,2,data);
        H = data[0];
        L = data[1];
        TEM = (double)((H<<5) + (L>>3)) *0.0625; //translate 2byte data to temptature
        printf("TEMP = %f\n",TEM);
    }
    return 0;
}

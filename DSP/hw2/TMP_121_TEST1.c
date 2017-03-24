#include "LIB\ASA_Lib.h"
#include "LIB\ASA_SPI.h"
#include "LIB\bit_op.h"

int main(void) {
    ASA_M128_set();
    double TEM;
    uint8_t H,L;
    printf("start!-----------------------------\n");
    DDRF = 16;
    char data[2];
    char ADDR_MSK = (1<<5)|(1<<6)|(1<<7);
    char ADDR_SHT = 5;
    char ADDR = 7;
    M128_DIO_set(1,ADDR_MSK,ADDR_SHT,ADDR);
    M128_DIO_fpt(1,ADDR_MSK,ADDR_SHT,ADDR);
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR));
    while (1){
        _delay_ms(250);          //轉換時間長，CS腳須維持 250ms才能完成一次轉換
        PORTF = 16 ;             //enable TM121 CS to start transfer data
        data[0] = M128_SPI_swap(0);    //receive the High byte from TM121
        data[1] = M128_SPI_swap(0);    //receive the Low  byte from TM121
        PORTF = 0;               //disable TM121 CS
        H = data[0];
        L = data[1];
        TEM = (double)((H<<5) + (L>>3)) *0.0625; //translate 2byte data to temptature
        printf("TEMP = %f\n",TEM);
    }
    return 0;
}

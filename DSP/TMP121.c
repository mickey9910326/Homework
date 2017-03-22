#include "ASA_Lib.h"

int main(void)
{
    ASA_M128_set();
    double TEM;
    uint8_t H,L;
    printf("start!-----------------------------\n");
    spi_init_master();
    while (1){
        _delay_ms(250);                     //轉換時間長，CS腳須維持 250ms才能完成一次轉換
        PORTB = 32;              //enable TM121 CS to start transfer data
        H = SPI_send_receive(0); //receive the High byte from TM121
        L = SPI_send_receive(0); //receive the Low  byte from TM121
        PORTB = 0 ;              //disable TM121 CS
        TEM = (double)((H<<5) + (L>>3)) *0.0625; //translate 2byte data to temptature
        printf("TEMP = %f\n",TEM);
    }
    return 0;
}

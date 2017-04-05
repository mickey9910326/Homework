#include "LIB\ASA_Lib.h"
#include "LIB\ASA_MAX7219.h"

int main() {
    ASA_M128_set();
    printf("start!-----------------------------\n");
    char ASA_ID = 1;
    char check,i;
    char Data,Addr,LSByte;
    int input;

    char matrix[8]={
    0b11111111,
    0b01000000,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00000100,
    0b00000010,
    0b11111111
    };
    char matrix2[8]={
    0b00000000,
    0b11111111,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b11111111,
    0b00000000
    };

    ASA_MAX7219_ini();
    Data=0,LSByte=204;ASA_MAX7219_set(ASA_ID,LSByte,1,0xFF,0,&Data); // 關閉 DISPLAY_TEST MODE
    Data=7,LSByte=202;ASA_MAX7219_set(ASA_ID,LSByte,1,0xFF,0,&Data); // 顯示7位數
    Data=0,LSByte=201;ASA_MAX7219_set(ASA_ID,LSByte,1,0xFF,0,&Data); // 亮度0(最低)
    Data=1,LSByte=203;ASA_MAX7219_set(ASA_ID,LSByte,1,0xFF,0,&Data); // 關閉 SHOTDOWN模式
    _delay_ms(200);
    for(i=1;i<=8;i++){
        ASA_MAX7219_put(1,i,1,&matrix2[i-1]);
    }
    while (1) {
        printf("\nAddr = ");
        scanf("%d", &input);
        Addr = (char)input;
        printf("\nData = ");
        scanf("%d", &input);
        Data = (char)input;
        printf("Addr=%02x  ",Addr );
        printf("Data=%02x\n",Data );

        M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
        M128_SPI_swap(0);
        M128_SPI_swap(0);
        M128_SPI_swap(Addr);
        M128_SPI_swap(Data);
        scanf("%d", &input);
    	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
    }
    return 0;
}

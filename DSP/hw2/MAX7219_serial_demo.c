// DEMO serial MAX7219 TEST
#include "LIB\ASA_Lib.h"
#include "LIB\ASA_MAX7219.h"

int main() {
    ASA_M128_set();
    printf("start!-----------------------------\n");
    char ASA_ID = 1;
    char i;
    char Data[2],LSByte;

    char matrix1[8]={
    0b01010101,
    0b00000000,
    0b11111111,
    0b10010001,
    0b10010001,
    0b00000000,
    0b00000000,
    0b11110001
    };
    char matrix2[8]={
    0b10001001,
    0b10000111,
    0b00000000,
    0b00000000,
    0b00000001,
    0b11111111,
    0b10000001,
    0b00000000
    };

    ASA_MAX7219_ini();
    Data[0]=Data[1]=0,LSByte=204; ASA_MAX7219_set(ASA_ID,LSByte,2,0xFF,0,Data); // 關閉 DISPLAY_TEST MODE
    Data[0]=Data[1]=7,LSByte=202; ASA_MAX7219_set(ASA_ID,LSByte,2,0xFF,0,Data); // 顯示7位數
    Data[0]=Data[1]=0,LSByte=201; ASA_MAX7219_set(ASA_ID,LSByte,2,0xFF,0,Data); // 亮度0(最低)
    Data[0]=Data[1]=1,LSByte=203; ASA_MAX7219_set(ASA_ID,LSByte,2,0xFF,0,Data); // 關閉 SHOTDOWN模式
    Data[0]=Data[1]=1,LSByte=203; ASA_MAX7219_set(ASA_ID,LSByte,2,0xFF,0,Data); // 關閉 SHOTDOWN模式
    _delay_ms(200);
    for(i=1;i<=8;i++){
        Data[0] = matrix1[i-1];
        Data[1] = matrix2[i-1];
        ASA_MAX7219_put(ASA_ID,i,2,Data);
    }

    while (1) {
        printf("OAO\n");
    }
    return 0;
}

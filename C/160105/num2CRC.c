#include <stdio.h>
#include <inttypes.h>

const uint8_t CRC7_POLY = 0b00001011;
const uint8_t num_bit = 4;
const uint8_t crc_bit = 3;

void printbin(uint8_t);
uint8_t getCRC(uint8_t num);

int main()
{
    uint8_t num = 0;

    printf("#:CRC code\n");

    for(num=0;num<=9;num++){
        printf("%d:",num);
        printbin( getCRC(num) );
        printf("\n");
    }

    return 0;
}

uint8_t getCRC(uint8_t num) {
    uint8_t bit, devidend, result;
    devidend = num << crc_bit;
    for( bit = num_bit ; bit>=1 ; bit-- ) {
        if( devidend>>(bit+crc_bit-1) & 1){ //如果最高位是1
            devidend = ( (devidend >> (bit-1))^CRC7_POLY )<<(bit-1) | (uint8_t)( num<<(crc_bit)<<(8-bit+1) )>>(8-bit+1);
        }
    }
    result = (num << crc_bit) | devidend;
    return result;
}

void printbin(uint8_t num) {
    uint8_t bit , length;
    length = 7;
    for( bit = length ; bit>=1 ; bit-- ) {
        printf("%d", num>>(bit-1) &1 );
    }
}

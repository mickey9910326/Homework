// use IEEE 754

#include <stdio.h>
#include <string.h>

int   FloatGetExponent(float f);
float FloatGetMantissa(float f);

void ExponentToBinary(int num, char* binary);
void MantissaToBinary(float mantissa, char* binary);
void FloatToIntBits(float f, char* binary);

int main()
{
    float target = 19.85;
    char s[33];
    FloatToIntBits(target,s);

    printf("32bit binary is %s",s);

    // char 末位中放入 '\0' 為字串終止符號

    return 0;
}

int FloatGetExponent(float f) {
    // 這裡效率較差，沒有加入估算方法
    int exponent = 0;
    if ( f<0  ) f*=-1;
    if ( f>=2 ) {
        while ( f>=2 ){
            f/=2;
            exponent++;
        }
        return exponent;
    }
    if ( f<1 ) {
        while ( f<1 ){
            f*=2;
            exponent--;
        }
        exponent--;
        return exponent;
    }
}

float FloatGetMantissa(float f) {
    // 這裡效率較差，沒有加入估算方法
    int exponent = 1;
    float mantissa;
    if ( f<0  ) f*=-1;
    if ( f>=2 ) {
        while ( f>=2 ){
            f/=2;
            exponent++;
        }
        mantissa = f;
        return mantissa;
    }
    if ( f<1 ) {
        while ( f<1 ){
            f*=2;
            exponent--;
        }
        mantissa = f;
        return mantissa;
    }
}

void ExponentToBinary(int num, char* binary) {
    // 未包含非正規部分
    // -126 無法轉換為非正規 0000 0000
    if ( num > 0 ) {
        binary[0] = '1';
        num = ~(num)+1;
    } else {
        num = (num)*-1;
        binary[0] = '0';
    }
    int bit = 7;
    while ( bit>=1 ) {
        if ( num%2 ) {
            binary[bit] = '0';
        }
        else {
            binary[bit] = '1';
        }
        num = num>>1;
        bit--;
        // debug point
        // printf("%3d ,%s",num,binary)
    }
    binary[8] = '\0';
}

void MantissaToBinary(float mantissa, char* binary) {
    mantissa -= 1;
    int bit = 0;
    float sum = 1;
    while( bit<=22 ) {
        sum/=2;
        // debug point
        // printf("%d %f %f %s", bit, mantissa, sum);
        if( mantissa >= sum ){
            mantissa -= sum;
            binary[bit] = '1';
        } else {
            binary[bit] = '0';
        }
        bit++;
    }
    binary[24] = '\0';
}

void FloatToIntBits(float f, char* binary) {
    char sign[2];
    if ( f<0 ){
        binary[0] = '1';
        f*=-1;
    } else {
        binary[0] = '0';
    }
    sign[1]='\0';

    int exponent = FloatGetExponent(f);
    float mantissa = FloatGetMantissa(f);

    char exponent_binary[9];
    char mantissa_binary[24];
    ExponentToBinary(exponent,exponent_binary);
    MantissaToBinary(mantissa,mantissa_binary);

    // debug point
    printf("exponent is %f, binary is %s\n", (float)exponent, exponent_binary);
    printf("mantissa is %f, binary is %s\n", mantissa, mantissa_binary);

    int bit = 0;
    for ( bit = 0 ; bit < 8; bit++) {
        binary[bit+1] = exponent_binary[bit];
    }
    for ( bit = 0 ; bit < 23; bit++) {
        binary[bit+9] = mantissa_binary[bit];
    }
    binary[33] = '\0';
}

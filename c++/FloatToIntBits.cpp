#include <iostream>
#include <string>

int   FloatGetExponent(float f);
float FloatGetMantissa(float f);

std::string ExponentToBinary(int num);
std::string MantissaToBinary(float mantissa);
std::string FloatToIntBits(float f);

using namespace std;

int main()
{
    float target = 19.85;

    std::string s = FloatToIntBits(target);

    cout<< s << endl;

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

std::string ExponentToBinary(int num) {
    // 未包含非正規部分
    // -126 無法轉換為非正規 0000 0000
    std::string binary;
    if ( num > 0 ) {
        binary += '1';
        num = ~(num)+1;
    } else {
        num = (num)*-1;
        binary += '0';
    }
    int bit = 2;
    while ( bit<=8 ) {
        if ( num%2 ) {
            binary.insert (1,"0");
        }
        else {
            binary.insert (1,"1");
        }
        num = num>>1;
        bit++;
        // debug point
        // cout << num <<"\t"<< binary << endl;
    }
    return binary;
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

std::string MantissaToBinary(float mantissa){
    mantissa -= 1;
    int bit = 1;
    float sum = 1;
    string binary;
    while( bit<=23 ) {
        sum/=2;
        // debug point
        // cout << bit << "\t" << mantissa << "\t" << sum <<endl;
        if( mantissa >= sum ){
            mantissa -= sum;
            binary += '1';
        } else {
            binary += '0';
        }
        bit++;
    }
    return binary;
}

std::string FloatToIntBits(float f) {
    string binary;

    if ( f<0 ){
        binary += '1';
        f*=-1;
    } else {
        binary += '0';
    }

    int exponent = FloatGetExponent(f);
    float mantissa = FloatGetMantissa(f);

    // debug point
    // cout << "exponent:" << exponent << "  mantissa:" << mantissa <<endl;

    binary += ExponentToBinary(exponent);
    binary += MantissaToBinary(mantissa);

    return binary;
}

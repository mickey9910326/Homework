// 8bit 二補數
#include <iostream>
#include <string>

std::string DecimalTo2Complement(int num);

using namespace std;

int main()
{
    std::string s = DecimalTo2Complement(-17);
    cout << s << endl;
    return 0;
}

std::string DecimalTo2Complement(int num) {
    std::string binary;
    if ( num < 0 ) {
        binary += '1';
        num = ~(num*(-1))+1;
    } else {
        binary += '0';
    }
    int i = 0;
    while ( i<=7) {
        if ( num%2 ) {
            binary.insert (1,"1");
        }
        else {
            binary.insert (1,"0");
        }
        num = num>>1;
        i++;
        cout << num <<"\t"<< binary << endl;
    }
    return binary;
}

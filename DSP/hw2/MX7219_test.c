#include "LIB\ASA_Lib.h"
#include "LIB\ASA_MAX7219.h"

int main() {
    ASA_M128_set();
    printf("start!-----------------------------\n");
    char check;
    int input;
    char data,lsbyte;
    ASA_MAX7219_ini();
    while (1) {
        printf("\ndata = ");
        scanf("%d", &input);
        data = input;
        printf("\nLSbyte = ");
        scanf("%d", &input);
        lsbyte = input;
        check = ASA_MAX7219_set(1,lsbyte,1,0xFF,0,&data);
        printf("\ncheck = %d", check);
    }
    return 0;
}

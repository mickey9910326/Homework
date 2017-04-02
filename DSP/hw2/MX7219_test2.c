#include "LIB\ASA_Lib.h"
#include "LIB\ASA_MAX7219.h"

int main() {
    ASA_M128_set();
    printf("start!-----------------------------\n");
    char check;
    int input;
    char Data,Addr;
    ASA_MAX7219_ini();
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,1);
    while (1) {
        printf("\nAddr = ");
        scanf("%d", &input);
        Addr = (char)input;
        printf("Addr=%02x\n",Addr );
        printf("\nData = ");
        scanf("%d", &input);
        Data = (char)input;
        printf("Data=%02x\n",Addr );

        M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
    	M128_SPI_swap(Addr);
        M128_SPI_swap(Data);
    	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
    }
    return 0;
}

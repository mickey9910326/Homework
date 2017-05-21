#include <avr/io.h>
#include "LIB\ASA_lib.h"
#include "LIB\ASA_DIO.h"
#include "LIB\ASA_SPI.h"
#include "LIB\ASA_general.h"

char ASA_SPI_swap(char data) {
    char res = data;
    M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
    M128_SPI_put(1,0,1,&res);
    M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
    return res;
}

int main() {
    ASA_M128_set();
    char ASA_ID = 1;
    uint8_t data = 0,count = 0;
    int tmp;
    //spi pins on port b MOSI SCK,SS outputs
    const char MSTR_DDR = ((1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS));
    M128_DIO_set(200+DDR_SPI_num,15,0, 0);
    M128_DIO_set(200+DDR_SPI_num,15,0, MSTR_DDR);

    //set CS pin (PF4) output 0
    M128_DIO_set(200+CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
    M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);

    // set ADDR pins (PB5~7) as output
    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);

    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR)|(0<<SPIE));


    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);

    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    ASA_SPI_swap(170);
    ASA_SPI_swap(2);
    ASA_SPI_swap(101);
    ASA_SPI_swap(1);
    ASA_SPI_swap(128);
    ASA_SPI_swap(232);

    int status = 0,countt=0,times=0;
    char GetData = 0;
    char return_val,dataa;
    while ( status != 3 ) {
        GetData = ASA_SPI_swap(0);
        switch(status) {
            case 0:
            // handle data
            times++;
            if ( GetData == 0xAB ) {
                countt ++;
            } else {
                countt = 0 ;
            }
            if (countt==3) {
                status = 1;
            }
            // if (times == 10) {
            //     statuse = 10;
            // }
            break;
        case 1:
            return_val = GetData;
            status = 2;
            break;
        case 2:
            dataa = GetData;
            status = 3;
            break;
        }
    }
    printf("r=%d,d=%d\n",return_val,dataa);


    while (1) {
        count++;
        printf("input data:");
        scanf("%d",&tmp);
        data = tmp;
        M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
        M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
        M128_SPI_put(1,0,1,&data);
        M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
        printf("times:%3d,getdata:%3d\n",count,data);
    }
    return 0;
}

#include <avr/io.h>
#include "LIB\ASA_lib.h"
#include "LIB\ASA_DIO.h"
#include "LIB\ASA_SPI.h"
#include "LIB\ASA_general.h"

char SPI_swap(char cData);

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

    while (1) {
        count++;
        data = count;
        printf("data=%3d",count);
        M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
        M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
        M128_SPI_put(1,0,1,&data);
        M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
        printf(",getdata =%3d\n", data);
        scanf("%d",&tmp);
    }
    return 0;
}


char SPI_swap(char cData){
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;
}

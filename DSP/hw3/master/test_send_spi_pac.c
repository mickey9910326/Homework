#include <avr/io.h>
#include "LIB\ASA_lib.h"
#include "LIB\ASA_DIO.h"
#include "LIB\ASA_SPI.h"
#include "LIB\ASA_general.h"
#include "LIB\ASA_core_SPI.h"

void master_spi_ini();
void set_id(char ASA_ID);

int main() {
    ASA_M128_set();
    master_spi_ini();

    char ASA_ID = 1;
    set_id(ASA_ID);

    char check,data;
    data = 123;
    check = ASA_SPI_put(101,1,&data);
    printf("test ASA_SPI_put exp:[r,d]=[%d,%d],res:[r,d]=[%d,%d]\n",0,123,check,data);
    _delay_ms(100);
    data = 122;
    check = ASA_SPI_put(1,1,&data);
    printf("test ASA_SPI_put exp:[r,d]=[%d,%d],res:[r,d]=[%d,%d]\n",1,0,check,data);
    _delay_ms(100);
    data = 123;
    check = ASA_SPI_get(101,1,&data);
    printf("test ASA_SPI_put exp:[r,d]=[%d,%d],res:[r,d]=[%d,%d]\n",0,123,check,data);
    _delay_ms(100);
    data = 123;
    check = ASA_SPI_set(101,1,1,3);
    printf("test ASA_SPI_put exp:[r,d]=[%d,%d],res:[r,d]=[%d,%d]\n",0,123,check,data);

    return 0;
}

void master_spi_ini(){
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
}

void set_id(char ASA_ID){
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
}

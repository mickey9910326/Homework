#include <avr/io.h>
#include <avr/interrupt.h>
#include "LIB\ASA_LIB.h"
#include "LIB\ASA_general.h"
#include "LIB\ASA_slave_SPI.h"
#include <stdlib.h>
#include <stdio.h>

void print_TypeOfSlave_SPI_PacDe(TypeOfSlave_SPI_PacDe* str_p);
void print_buffer_data(TypeOfBuffer* Buffer_p);
void slave_spi_ini();
extern TypeOfSlave_SPI_PacDe slave_SPI_PacDe_str;
extern TypeOfslave_SPI_swap slave_SPI_swap_str;
extern TypeOfBuffer Com_Buff_str;
extern TypeOfBuffer Res_Buff_str;

int main() {
    ASA_M128_set();
    slave_spi_ini();
    slave_SPI_swap_ini(&slave_SPI_swap_str,&Res_Buff_str,&Com_Buff_str);
    slave_SPI_PacDe_ini(&slave_SPI_PacDe_str,&Res_Buff_str,&Com_Buff_str);
    sei();
    printf("start slave!----------\n" );
    while (1) {
        slave_SPI_PacDe_step(&slave_SPI_PacDe_str);
    }

    return 0;
}

void slave_spi_ini() {
    DDR_SPI = (1<<DD_MISO);
    SPCR = (1<<SPE)|(1<<SPIE);
    SPSR = (1<<SPIF);
}

void print_buffer_data(TypeOfBuffer* Buffer_p) {
    unsigned char i;
    int tmp;
    printf("G:%d,P:%d,data:",Buffer_p->GETindex,Buffer_p->PUTindex);
    for (i = 0; i < MAXBUFFBYTES; i++) {
        tmp = Buffer_p->data[i];
        printf("%d,", tmp );
    }
    printf("\n");
}

void print_TypeOfSlave_SPI_PacDe(TypeOfSlave_SPI_PacDe* str_p) {
    printf("statuse :%d\n",str_p->statuse);
    printf("CallType:%d\n",str_p->CallType);
    printf("LSByte  :%d\n",str_p->LSByte);
    printf("Mask    :%d\n",str_p->Mask);
    printf("Shift   :%d\n",str_p->Shift);
    printf("Bytes   :%d\n",str_p->Bytes);
    printf("CheckSum:%d\n",str_p->CheckSum);
}

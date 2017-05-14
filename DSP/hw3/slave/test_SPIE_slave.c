#include <avr/io.h>
#include <avr/interrupt.h>
#include "LIB\ASA_DIO.h"
#include "LIB\ASA_LIB.h"
#include "LIB\ASA_SPI.h"
#include "LIB\ASA_general.h"

char SPI_swap(char cData);
uint8_t INT_times = 0;
uint8_t count = 0,getdata=0;

int main() {
    ASA_M128_set();
    printf("start2!----------\n" );
    DDR_SPI = (1<<DD_MISO);
    SPCR = (1<<SPE)|(1<<SPIE);
    SPSR = (1<<SPIF);
    while (1) {
            printf("getdata=%3d,senddata=%3d,INT_times=%3d\n", getdata, getdata+10,INT_times);
    }

    return 0;
}

char SPI_swap(char cData) {
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;
}

ISR(SPI_STC_vect) {
    getdata = SPDR;
    SPDR = getdata+10;
    INT_times++;
}

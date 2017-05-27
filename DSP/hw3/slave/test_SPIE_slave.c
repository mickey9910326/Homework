#include <avr/io.h>
#include <avr/interrupt.h>
#include "LIB\ASA_general.h"

char SPI_swap(char cData);
uint8_t INT_times = 0;
uint8_t count = 0,getdata=0;

int main() {
    DDR_SPI = (1<<DD_MISO);
    SPCR = (1<<SPE)|(1<<SPIE);
    SPSR = (1<<SPIF);
    DDRB |= (1<<0);
    PORTB |= (1<<0);
    while (1) {
        INT_times++;
    }

    return 0;
}

ISR(SPI_STC_vect) {
    getdata = SPDR;
    SPDR = getdata+10;
}

#include "LIB\ASA_Lib.h"
#include "LIB\ASA_SPI.h"
#include "LIB\bit_op.h"
#include "LIB\ASA_DIO.h"
#include "LIB\ASA_general.h"

int main(void) {
    ASA_M128_set();

    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);
    M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR)|(1<<SPR1)|(0<<SPR0));
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,1);
    while (1) {
        M128_SPI_swap(0);
    }
    return 0;
}

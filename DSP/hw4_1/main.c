#include "..\LIB\ASA_TWI.h"
#include "..\LIB\ASA_DEVICE.h"
#include "..\LIB\ASA_STDIO.h"
#include "..\LIB\ASA_SPI.h"
#include "..\LIB\ASA_DIO.h"
void ASA_ID_init();
void ASA_ID_set(char ASA_ID);

int main() {
    ASA_STDIO_set();
    ASA_ID_init();
    ASA_ID_set(1);
    printf("Start-------------\n");

    return 0;
}


void ASA_ID_init() {
    // set ADDR pins (PB5~7) as output
    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);
}

void ASA_ID_set(char ASA_ID) {
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
}

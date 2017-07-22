#include "ASA_core_lib.h"
#include "ASA_DIO.h"
#include "ASA_DEVICE.h"
#include "bit_op.h"



void ASA_ID_init() {
    // set ADDR pins (PB5~7) as output
    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);
}

void ASA_ID_set(char ASA_ID) {
    // set ASA_ID
    M128_DIO_set(200+ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);
    M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,ASA_ID);
}

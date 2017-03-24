#include "LIB\ASA_LIB.h"
#include "LIB\ASA_TMP121.h"

int main(void) {
    ASA_M128_set();
    double TEM;
    printf("start!-----------------------------\n");
    ASA_TMP121_ini();
    while (1){

        ASA_TMP121_get(1,100,2,&TEM);
        printf("TEMP = %f\n",TEM);
    }
    return 0;
}

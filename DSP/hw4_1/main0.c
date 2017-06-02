#include "..\ASAlib\ASA_Lib.h"

int main() {
    ASA_M128_set();
    printf("Start-------------\n");
    float temp;
    ASA_THM01_get(1,100,2,&temp);

    return 0;
}

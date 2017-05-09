#include "LIB\ASA_SPI.h"
#include "LIB\bit_op.h"
#include "LIB\ASA_DIO.h"
#include "LIB\ASA_general.h"

char ASA_SPI_put();
char ASA_SPI_get();
char ASA_SPI_fpt();
char ASA_SPI_fgt();
char ASA_SPI_set();

int main() {
    return 0;
}

#define MAXBUFFBYTES 32
typedef struct {
    char PUTindex;
    char GETindex;
    char data[MAXBUFFBYTES];
} TypeOfBuffer;

TypeOfBuffer Com_Buff_str;
TypeOfBuffer Res_Buff_str;


//宣告結構形態
typedef struct {
    char statuse;
    TypeOfBuffer* OutBUFF_p;
    TypeOfBuffer* InBUFF_p;
} TypeOfslave_SPI_swap;

//定義資料結構
TypeOfslave_SPI_swap slave_SPI_swap_str;



ASA MASTER  <->  SLAVE  <->  IC
            (SPI)       (???)

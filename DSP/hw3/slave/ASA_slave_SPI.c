#include <string.h>
#include "buffer.h"
#define MAXBUFFBYTES 32

#define STAT_HEADER 0
#define STAT_CALLTYPE 1
#define STAT_LSBYTE 2
#define STAT_MASK 3
#define STAT_SHIFT 4
#define STAT_BYTES 5
#define STAT_DATA 6
#define STAT_CHECKSUM 7

#define SPI_HEADER_BIN 0xAA

// 建立一個緩衝區資料結構型態TypeOfBuffer：包含，寫入指標欄，讀取指標
// 欄，以及資料暫存矩陣欄。
// this is FIFO array


// SPI通訊處理用資料結構slave_SPI_swap_str：資料結構內要有一欄
// 記錄狀態機械狀態，一欄可存放通訊命令封包緩衝區指標，另一欄存放通訊回
// 應封包緩衝區指標。
typedef struct {
    char statuse;
    TypeOfBuffer *OutBUFF_p;
    TypeOfBuffer *InBUFF_p;
} TypeOfslave_SPI_swap;

TypeOfslave_SPI_swap slave_SPI_swap_str;
TypeOfBuffer Com_Buff_str;
TypeOfBuffer Res_Buff_str;

void slave_SPI_swap_ini(
    TypeOfslave_SPI_swap *str_p,
    TypeOfBuffer *OutBuff_p,
    TypeOfBuffer *InBuff_p)
{
    str_p->OutBUFF_p = OutBuff_p;
    str_p->InBUFF_p  = InBuff_p;
}


char slave_SPI_swap_step() {
    static TypeOfslave_SPI_swap *str_p=&slave_SPI_swap_str;

    // this is the part to get data from master
    // PROBLEM : how to combine get part and put part in SPI
    char str;
    static int count , times;
    switch(str_p->statuse) {
        case STAT_HEADER:
            get_buffer_bytes(str_p->InBUFF_p,1,&str);
            if ( str == SPI_HEADER_BIN ) {
                count ++;
            }
            times ++;
            if ( count == 3 ) {
                str_p->statuse = STAT_CALLTYPE;
            } else if (times == 3) {
                return 1;
            }
            break;
        case STAT_CALLTYPE:
        break;
        case STAT_LSBYTE:
        break;
        case STAT_MASK:
        break;
        case STAT_SHIFT:
        break;
        case STAT_BYTES:
        break;
        case STAT_DATA:
        break;
        case STAT_CHECKSUM:
        break;
    }
}

#include <string.h>
#include "buffer.h"
#include "ASA_slave_SPI.h"
#include "ASA_IC.h"
#include <stdlib.h>
#include <avr\io.h>
#include <avr\interrupt.h>
#include <stdio.h>
#include <util\delay.h>
#define MAXBUFFBYTES 32

#define STAT_HEADER 0
#define STAT_CALLTYPE 1
#define STAT_LSBYTE 2
#define STAT_MASK 3
#define STAT_SHIFT 4
#define STAT_BYTES 5
#define STAT_DATA 6
#define STAT_CHECKSUM 7
#define STAT_ERROR 8


#define SPI_HEADER_BIN 0xAA


// SPI通訊處理用資料結構slave_SPI_swap_str：資料結構內要有一欄
// 記錄狀態機械狀態，一欄可存放通訊命令封包緩衝區指標，另一欄存放通訊回
// 應封包緩衝區指標。

TypeOfslave_SPI_swap slave_SPI_swap_str;
TypeOfBuffer Com_Buff_str;
TypeOfBuffer Res_Buff_str;

void slave_SPI_swap_ini(
    TypeOfslave_SPI_swap *str_p,
    TypeOfBuffer *OutBuff_p,
    TypeOfBuffer *InBuff_p)
{
    str_p->statuse = 0;
    str_p->OutBUFF_p = OutBuff_p;
    str_p->InBUFF_p  = InBuff_p;
    str_p->OutBUFF_p->GETindex = 0;
    str_p->OutBUFF_p->PUTindex = 0;
    str_p->InBUFF_p->GETindex = 0;
    str_p->InBUFF_p->PUTindex = 0;
}


char slave_SPI_swap_step() {
    static TypeOfslave_SPI_swap *str_p=&slave_SPI_swap_str;
    // this is the part to get data from master
    // PROBLEM : how to combine get part and put part in SPI
    char str;
    static char count, times, CheckSum;
    static char CallType , Bytes;
    static char *Data_p,*Get_Data_p;
    char GetCheckSum;

    switch(str_p->statuse) {
        case STAT_HEADER:
            get_buffer_bytes(str_p->InBUFF_p,1,&str);
            if ( str == SPI_HEADER_BIN ) {
                count ++;
            }
            times ++;
            if ( count == 3 ) {
                str_p->statuse = STAT_CALLTYPE;
                CheckSum = 0;
            } else if (times == 3) {
                str_p->statuse = STAT_ERROR;
                return 1;
            }
            break;
        case STAT_CALLTYPE:
            get_buffer_bytes(str_p->InBUFF_p,1,&CallType);
            // calltype case handle?
            str_p->statuse = STAT_BYTES;
            CheckSum += CallType;
            break;
        case STAT_BYTES:
            get_buffer_bytes(str_p->InBUFF_p,1,&Bytes);
            // calltype case handle?
            str_p->statuse = STAT_DATA;
            CheckSum += Bytes;
            count = 0 ;
            Data_p = realloc ( Data_p , sizeof(char)*Bytes );
            break;
        case STAT_DATA:
            get_buffer_bytes(str_p->InBUFF_p,1,Data_p+count);
            CheckSum += *(Data_p+count);
            count++;
            if (count == Bytes) {
                str_p->statuse = STAT_CHECKSUM;
                command_run(CallType,Bytes,Data_p,Get_Data_p);
            }
            break;
        case STAT_CHECKSUM:
            get_buffer_bytes(str_p->InBUFF_p,1,&GetCheckSum);
            if (CheckSum != GetCheckSum) {
                str_p->statuse = STAT_CHECKSUM;
                command_run(CallType,Bytes,Data_p,Get_Data_p);
            }
            break;
    }
    return 0;
}



char command_run( char CallType, char Bytes, char* Data_p, char* Get_Data_p ) {
    char check = 0;
    switch ( CallType ) {
        case CALLTYPE_SET:
        check = ic_set(Data_p[0],Data_p[1],Data_p[2],Data_p[3]);
        break;
        case CALLTYPE_PUT:
        check = ic_put(Data_p[0],Data_p[1],Data_p+3);
        break;
        case CALLTYPE_GET:
        check = ic_get(Data_p[0],Data_p[1],Get_Data_p);
        break;
        case CALLTYPE_FPT:
        check = ic_fpt(Data_p[0],Data_p[1],Data_p[2],Data_p[3]);
        break;
        case CALLTYPE_GPT:
        Get_Data_p = realloc(Get_Data_p,sizeof(char)*Data_p[2]);
        check = ic_fgt(Data_p[0],Data_p[1],Data_p[2],Get_Data_p);
        break;
        default: // set
        return 4;


    }
    return 0;
}

uint8_t getdata=0;
uint8_t INT_times=0;

ISR(SPI_STC_vect) {
    getdata = SPDR;
    put_buffer_bytes(&Com_Buff_str,1,&getdata);
    SPDR = getdata+10;
    INT_times++;
}

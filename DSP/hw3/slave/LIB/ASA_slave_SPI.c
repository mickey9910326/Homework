#include "ASA_slave_SPI.h"
#include "ASA_XXX.h"
#include <avr\io.h>
#include <avr\interrupt.h>
#include <stdlib.h>
#include <util\delay.h>

#define STAT_HEADER 0
#define STAT_CALLTYPE 1
#define STAT_LSBYTE 2
#define STAT_MASK 3
#define STAT_SHIFT 4
#define STAT_BYTES 5
#define STAT_DATA 6
#define STAT_CHECKSUM 7
#define STAT_ERROR 8

#define CALLTYPE_SET 0
#define CALLTYPE_GET 1
#define CALLTYPE_PUT 2
#define CALLTYPE_FPT 3
#define CALLTYPE_FGT 4

#define SPI_HEADER_GET_BIN 0xAA
#define SPI_HEADER_RES_BIN 0xAB

TypeOfBuffer Com_Buff_str;
TypeOfBuffer Res_Buff_str;
TypeOfslave_SPI_swap slave_SPI_swap_str;
TypeOfSlave_SPI_PacDe slave_SPI_PacDe_str;

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

void slave_SPI_PacDe_ini(
    TypeOfSlave_SPI_PacDe* str_p,
    TypeOfBuffer* OutBuff_p,
    TypeOfBuffer* InBuff_p)
{
    str_p->statuse = 0;
    str_p->OutBUFF_p = OutBuff_p;
    str_p->InBUFF_p  = InBuff_p;
}

char slave_SPI_PacDe_step( TypeOfSlave_SPI_PacDe* str_p ) {
    // this is the part to get data from master
    // PROBLEM : how to combine get part and put part in SPI
    static unsigned char count=0, times=0;

    if( str_p->InBUFF_p->GETindex == str_p->InBUFF_p->PUTindex ){
        return 1;
    }

    char GetData = str_p->InBUFF_p->data[str_p->InBUFF_p->GETindex];
    str_p->InBUFF_p->GETindex = (1 + str_p->InBUFF_p->GETindex)%32;

    switch(str_p->statuse) {
        case STAT_HEADER:
            // handle data
            times++;
            if ( GetData == SPI_HEADER_GET_BIN ) {
                count ++;
            } else {
                times = 0 ;
                count = 0 ;
            }
            // Switch to other statuse
            if ( count == 3 ) {
                str_p->statuse = STAT_CALLTYPE;
                str_p->CheckSum = 0;
                times = 0;
                count = 0;
            } else if (times == 3) {
                str_p->statuse = STAT_ERROR;
                return 1;
            }
            break;

        case STAT_CALLTYPE:
            // handle data
            str_p->CheckSum += GetData;
            str_p->CallType = GetData;
            // Switch to other statuse
            str_p->statuse = STAT_LSBYTE;
            break;

        case STAT_LSBYTE:
            // handle data
            str_p->CheckSum += GetData;
            str_p->LSByte = GetData;
            // Switch to other statuse
            switch (str_p->CallType) {
                case CALLTYPE_GET: str_p->statuse = STAT_BYTES; break;
                case CALLTYPE_PUT: str_p->statuse = STAT_BYTES; break;
                case CALLTYPE_SET: str_p->statuse = STAT_MASK; break;
                case CALLTYPE_FGT: str_p->statuse = STAT_MASK; break;
                case CALLTYPE_FPT: str_p->statuse = STAT_MASK; break;
                default: str_p->statuse = STAT_ERROR; return 2;
            }
            break;

        case STAT_MASK:
            // handle data
            str_p->CheckSum += GetData;
            str_p->Mask = GetData;
            // Switch to other statuse
            str_p->statuse = STAT_SHIFT;
            break;

        case STAT_SHIFT:
            // handle data
            str_p->CheckSum += GetData;
            str_p->Mask = GetData;
            // Switch to other statuse
            switch (str_p->CallType) {
                case CALLTYPE_GET: str_p->statuse = STAT_ERROR; break;
                case CALLTYPE_PUT: str_p->statuse = STAT_ERROR; break;
                case CALLTYPE_SET: str_p->statuse = STAT_DATA; break;
                case CALLTYPE_FGT: str_p->statuse = STAT_DATA; break;
                case CALLTYPE_FPT: str_p->statuse = STAT_DATA; break;
                default: str_p->statuse = STAT_ERROR; return 2;
            }
            break;

        case STAT_BYTES:
            // handle data
            str_p->CheckSum += GetData;
            str_p->Bytes = GetData;
            str_p->Data_p = realloc(str_p->Data_p, str_p->Bytes*sizeof(char));
            // Switch to other statuse
            switch (str_p->CallType) {
                case CALLTYPE_PUT: str_p->statuse = STAT_DATA; break;
                case CALLTYPE_GET: str_p->statuse = STAT_CHECKSUM; break;
                case CALLTYPE_SET: str_p->statuse = STAT_DATA; break;
                case CALLTYPE_FPT: str_p->statuse = STAT_DATA; break;
                case CALLTYPE_FGT: str_p->statuse = STAT_CHECKSUM; break;
                default: str_p->statuse = STAT_ERROR; return 2;
            }
            break;

        case STAT_DATA:
            // handle data
            str_p->CheckSum += GetData;
            ((char *)str_p->Data_p)[count] = GetData;
            count++;
            // Switch to other statuse
            if (count==str_p->Bytes){
                str_p->statuse = STAT_CHECKSUM;
                count=0;
            }
            break;

        case STAT_CHECKSUM:
            // handle data
            if (str_p->CheckSum != GetData) {
                str_p->statuse = STAT_ERROR;
                return 5;
            }
            // do command
            char check;
            switch (str_p->CallType) {
                case CALLTYPE_PUT:
                    check = XXX_put(str_p->LSByte, str_p->Bytes, str_p->Data_p);
                    break;
                case CALLTYPE_GET:
                    check = XXX_get(str_p->LSByte, str_p->Bytes, str_p->Data_p);
                    break;
                case CALLTYPE_SET:
                    check = XXX_set(str_p->LSByte, str_p->Mask, str_p->Shift, *(char*)str_p->Data_p);
                    break;
                case CALLTYPE_FPT:
                    check = XXX_fpt(str_p->LSByte, str_p->Mask, str_p->Shift, *(char*)str_p->Data_p);
                    break;
                case CALLTYPE_FGT:
                    check = XXX_fgt(str_p->LSByte, str_p->Mask, str_p->Shift, str_p->Data_p);
                    break;
                default:
                    str_p->statuse = STAT_ERROR;
                    return 2;
            }

            // respond
            buffer_put(str_p->OutBUFF_p,SPI_HEADER_RES_BIN);
            buffer_put(str_p->OutBUFF_p,SPI_HEADER_RES_BIN);
            buffer_put(str_p->OutBUFF_p,SPI_HEADER_RES_BIN);
            buffer_put(str_p->OutBUFF_p,check);
            if (!check)
            switch (str_p->CallType) {
                case CALLTYPE_PUT:
                case CALLTYPE_FPT:
                case CALLTYPE_SET:
                    break;
                case CALLTYPE_GET:
                    for (int i = 0; i < str_p->Bytes; i++) {
                        buffer_put(str_p->OutBUFF_p,((char*)str_p->Data_p)[i]);
                    }
                    break;
                case CALLTYPE_FGT:
                    buffer_put(str_p->OutBUFF_p,((char*)str_p->Data_p)[0]);
                    break;
                default:
                    return 2;
            }
            // Switch to other statuse
            str_p->statuse = STAT_HEADER;
            break;
    } /// end switch statuse
    return 0;
}

ISR(SPI_STC_vect) {
    if ( ((Com_Buff_str.PUTindex +1)%MAXBUFFBYTES) != Com_Buff_str.GETindex ) {
        Com_Buff_str.data[Com_Buff_str.PUTindex] = SPDR;
        Com_Buff_str.PUTindex = (Com_Buff_str.PUTindex + 1) % MAXBUFFBYTES;
    }
    if (Res_Buff_str.PUTindex != Res_Buff_str.GETindex) {
        SPDR = Res_Buff_str.data[Res_Buff_str.GETindex];
        Res_Buff_str.GETindex = (Res_Buff_str.GETindex + 1) % MAXBUFFBYTES;
    }
}

/* BUFFER  function */
char buffer_get(TypeOfBuffer* Buffer_p, char* Data_p) {
    //get 1 byte data in BUFFER
    if (Buffer_p->PUTindex != Buffer_p->GETindex) {
        *Data_p = Buffer_p->data[Buffer_p->GETindex];
        Buffer_p->GETindex = (Buffer_p->GETindex + 1) % MAXBUFFBYTES;
        return 0;
    }
    return 1;
}

char buffer_put(TypeOfBuffer* Buffer_p, char Data) {
    //put 1 byte data to BUFFER
    if ( ((Buffer_p->PUTindex +1)%MAXBUFFBYTES) != Buffer_p->GETindex) {
        Buffer_p->data[Buffer_p->PUTindex] = Data;
        Buffer_p->PUTindex = (Buffer_p->PUTindex + 1) % MAXBUFFBYTES;
        return 0;
    }
    return 1;
}

void buffer_clear(TypeOfBuffer* Buffer_p){
    Buffer_p->GETindex = 0;
    Buffer_p->PUTindex = 0;
}

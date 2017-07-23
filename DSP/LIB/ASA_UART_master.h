#ifndef __ASA_USART_H__
#define __ASA_USART_H__

#include "buffer.h"
volatile char I_RX_count;

TypeOfBuffer UART_trm_buffer;
TypeOfBuffer UART_rec_buffer;

char M128_UARTM_trm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void* Data_p);
char M128_UARTM_rec(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void* Data_p);

char M128_UARTM_ftm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char Data);
char M128_UARTM_frc(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char* Data_p);
char M128_UARTM_tpk(char OneSLA,char UARTID, char RegAdd, char BytesInf, void *Data_p);
char M128_UARTM_rpk(char OneSLA,char UARTID, char RegAdd, char BytesInf, void* Data_p);
#endif

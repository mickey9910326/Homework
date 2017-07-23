#ifndef __ASA_USART_H__
#define __ASA_USART_H__

#include "buffer.h"
volatile char I_RX_count;

// typedef struct {
//     char statuse; //狀態機器狀態
//     char Pack1st; //暫存區第一封包與否狀態
//     char CMType; //命令編號
//     char RegAdd; //暫存器編號
//     char BytesInf; //封包內位元組數資訊
//     char InCheckSum;
//     volatile char BWi; //BUFFER write indes寫入指標
//     char BRi; //BUFFER read index讀出指標
//     char RRWi; //Register Read & Write index暫存區讀寫指標
//     volatile char Buffer[MaxPackBytes]; //封包緩衝區
//     char* Data_p[MaxRegAdd]; //各暫存器起始所在指標住址。
//     char Bytes[MaxRegAdd]; //各暫存器所佔BYTES數
// } TypeOfUARTS_str;
//
// typedef struct {
//     volatile char BWi;
//     volatile char BRi;
//     volatile char Buffer[MaxPackBytes+4];
// } TypeOfUARTS_buffer;

TypeOfBuffer UART_trm_buffer;
TypeOfBuffer UART_rec_buffer;

// void UARTS_str_Ini(void);
// void UARTS_tb_Ini(void);
// void UARTS_mb_Ini(void);
// char M128_UARTM_trm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void* Data_p);
// char M128_UARTM_rec(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void* Data_p);
// void M128_UARTS_rx();
// void M128_UARTS_rx2();
// void M128_UARTS_tx();
// void UARTS_dppk(void);
// char M128_UARTM_ftm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char Data);
// char M128_UARTM_frc(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char* Data_p);
// char M128_UARTM_tpk(char OneSLA,char UARTID, char RegAdd, char BytesInf, void *Data_p);
// char M128_UARTM_rpk(char OneSLA,char UARTID, char RegAdd, char BytesInf, void* Data_p);
#endif

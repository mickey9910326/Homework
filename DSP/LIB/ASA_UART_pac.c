#include "ASA_UART_pac.h"
#include "ASA_UART.h"
#include "ASA_DEVICE.h"
#include "bit_op.h"
//
// void uart_slave_ini(void){
//
// 	M128_UART_set(203, 0xff, 0, BAUDRATE);
// 	M128_UART_set(204, 0xff, 0, (BAUDRATE)>>8);
// 	M128_UART_set(201, (1<<RXEN1)|(1<<TXEN1), 0, (1<<RXEN1)|(1<<TXEN1));
// 	M128_UART_set(201, (1<<RXCIE1)|(1<<TXCIE1), 0, (1<<RXCIE1)|(1<<TXCIE1));
// 	// working with 9 Data Bits  & MPCM
// 	M128_UART_set(200, (1<<MPCM1), 0, (1<<MPCM1));
// 	M128_UART_set(201, (1<<UCSZ12), 0, (1<<UCSZ12));
// 	M128_UART_set(202, (1<<UCSZ10)|(1<<UCSZ11), 0, (1<<UCSZ10)|(1<<UCSZ11));
// }
// void uart_master_ini(void){
//
// 	M128_UART_set(203, 0xff, 0, BAUDRATE);
// 	M128_UART_set(204, 0xff, 0, (BAUDRATE)>>8);
// 	M128_UART_set(201, (1<<RXEN1)|(1<<TXEN1), 0, (1<<RXEN1)|(1<<TXEN1));
// 	M128_UART_set(201, (1<<RXCIE1)|(1<<TXCIE1), 0, (1<<RXCIE1)|(0<<TXCIE1));
// 	// working with 9 Data Bits  & NOT MPCM
// 	M128_UART_set(200, (1<<MPCM1), 0, (0<<MPCM1));
// 	M128_UART_set(201, (1<<UCSZ12), 0, (1<<UCSZ12));
// 	M128_UART_set(202, (1<<UCSZ10)|(1<<UCSZ11), 0, (1<<UCSZ10)|(1<<UCSZ11));
// }
//
// void UARTS_str_Ini(void){
// 	UARTS_rec_str.statuse=1;
// 	UARTS_rec_str.Pack1st=0;
// 	UARTS_rec_str.CMType=0;
// 	UARTS_rec_str.RegAdd=0;
// 	UARTS_rec_str.BytesInf=0;
// 	UARTS_rec_str.InCheckSum=0;
// 	UARTS_rec_str.BWi=0;
// 	UARTS_rec_str.BRi=0;
// 	UARTS_rec_str.RRWi=0;
// 	for (int i = 0; i < MaxPackBytes; ++i) {
// 		UARTS_rec_str.Buffer[i]=0;
// 	}
// 	for (int i = 0; i < MaxRegAdd; ++i) {
// 		UARTS_rec_str.Data_p[i]=NULL;
// 		UARTS_rec_str.Bytes[i]=0;
// 	}
// }
//
// void UARTS_tb_Ini(void){
// 	UARTS_trm_buffer.BWi=0;
// 	UARTS_trm_buffer.BRi=0;
// 	for (int i = 0; i < MaxPackBytes+4; ++i) {
// 		UARTS_trm_buffer.Buffer[i] = 0;
// 	}
// }
//
// void UARTS_mb_Ini(void){
// 	UARTS_mastrec_buffer.BWi=0;
// 	UARTS_mastrec_buffer.BRi=0;
// 	for (int i = 0; i < MaxPackBytes+4; ++i) {
// 		UARTS_mastrec_buffer.Buffer[i] = 0;
// 	}
// }
//
//
// char M128_UARTM_trm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void* Data_p){
// 	char check=0;
// 	if(OneSLA!=1){
// 		UCSR1B|=(1<<TXB81);
// 		check=M128_UART_put(0, 1, &UARTID);
// 		if(check!=0)	return 1;
// 	}
// 	if(OneReg!=1){
// 		UCSR1B &= ~(1<<TXB81);
// 		check=M128_UART_put(0, 1, &RegAdd);
// 		if(check!=0)	return 2;
// 	}
// 	for (int i = 0; i < Bytes; ++i){
// 		UCSR1B&= ~(1<<TXB81);
// 		check=M128_UART_put(0, 1, (char*)(Data_p+i));
// 		if(check!=0)	return 3;
// 	}
// 	return 0;
// }
//
// char M128_UARTM_rec(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void* Data_p){
// 	char check=0;
// 	int poi;
// 	char Index=0;
// 	if(OneSLA!=1){
// 		UCSR1B|=(1<<TXB81);
// 		check=M128_UART_put(0, 1, &UARTID);
// 		if(check!=0)	return 1;
// 	}
// 	if(OneReg!=1){
// 		UCSR1B &= ~(1<<TXB81);
// 		check=M128_UART_put(0, 1, &RegAdd);
// 		if(check!=0)	return 2;
// 	}
// 	poi=MAXPoi;
// 	while(poi!=0 && Index < Bytes){
// 		if(UARTS_mastrec_buffer.BWi!=UARTS_mastrec_buffer.BRi){
// 			*((char*)Data_p+Index)=UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BRi];
// 			UARTS_mastrec_buffer.BRi=(UARTS_mastrec_buffer.BRi+1)%(MaxPackBytes+4);
// 			Index = Index+1;
// 			poi=MAXPoi;
// 		}
// 		else{
// 			poi = poi-1;
// 		}
// 	}
// 	if(poi==0)	return 3;
// 	return 0;
// }
//
// char M128_UARTM_ftm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char Data){
// 	char data_dest;
// 	char result=0;
// 	result=M128_UARTM_rec(OneSLA, OneReg, UARTID, RegAdd, 1, &data_dest);
// 	if(result!=0)	return result;
// 	data_dest = (data_dest & ~Mask) | ((Data << shift) & Mask) ;
// 	result=M128_UARTM_trm(OneSLA, OneReg, UARTID, RegAdd, 1, &data_dest);
// 	if(result!=0)	return 4+result;
// 	return 0;
// }
//
// char M128_UARTM_frc(char OneSLA, char OneReg, char UARTID, char RegAdd, char Mask,  char shift, char* Data_p){
// 	char result=0;
// 	result=M128_UARTM_rec(OneSLA, OneReg, UARTID, RegAdd, 1, Data_p);
// 	if(result!=0)	return result;
// 	*Data_p= (*Data_p & Mask) >> shift;
// 	return 0;
// }
//
// void M128_UARTS_rx(){
// 	if( UCSR1B&(1<<RXB81) ){
// 		if ( UDR1==USART_ID ){
// 			UCSR1A&= ~(1<<MPCM1);
// 			//MPCM disable, data frames receiving
// 		}
// 		else{
// 			UCSR1A|=(1<<MPCM1);
// 			//MPCM enable, adderss frames receiving
// 		}
// 	}
// 	else{
// 		UARTS_rec_str.Buffer[(int)UARTS_rec_str.BWi]=UDR1;
// 		UARTS_rec_str.BWi=(UARTS_rec_str.BWi+1)%MaxPackBytes;
// 	}
// }
//
// void M128_UARTS_rx2(){
// 	if(UARTS_mastrec_buffer.BRi!=(UARTS_mastrec_buffer.BWi+1)){
// 		UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BWi]=UDR1;
// 		UARTS_mastrec_buffer.BWi=(UARTS_mastrec_buffer.BWi+1)%(MaxPackBytes+4);
// 	}
// }
//
// void M128_UARTS_tx(){
// 	if(UARTS_trm_buffer.BRi!=UARTS_trm_buffer.BWi){
// 		UDR1=UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BRi];
// 		UARTS_trm_buffer.BRi=(UARTS_trm_buffer.BRi+1)%(MaxPackBytes+4);
// 	}
// }
//
// void UARTS_dppk(void){
// 	static char check_sum = 0;
// 	static char ByteSum=0;
// 	static char Pack1st=1;
// 	if(UARTS_rec_str.BWi==UARTS_rec_str.BRi);
// 	else{
// 		switch(UARTS_rec_str.statuse){
// 			case 1:
// 				check_sum=0;
// 				UARTS_rec_str.CMType=UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				check_sum=check_sum+UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				UARTS_rec_str.BRi=(UARTS_rec_str.BRi+1)%MaxPackBytes;
// 				UARTS_rec_str.statuse=2;
// 			break;
// 			case 2:
// 				UARTS_rec_str.RegAdd=UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				check_sum=check_sum+UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				UARTS_rec_str.BRi=(UARTS_rec_str.BRi+1)%MaxPackBytes;
// 				UARTS_rec_str.statuse=3;
// 			break;
// 			case 3:
// 			// 第一批 BytesInf=Bytes
// 			// 第二批 BytesInf=0
// 			// 最後一批 BytesInf= 剩餘比數
// 				UARTS_rec_str.BytesInf = UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				check_sum = check_sum+UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				UARTS_rec_str.BRi = (UARTS_rec_str.BRi+1)%MaxPackBytes;
// 				if(UARTS_rec_str.BytesInf == 0){
// 					// >32的中間筆
// 					ByteSum = ByteSum+MaxPackBytes;//累計位元組
// 				}
// 				else{
// 					if (Pack1st==1){
// 						// 第一筆
// 						UARTS_rec_str.Bytes[(int)UARTS_rec_str.RegAdd] = UARTS_rec_str.BytesInf;
// 						if(UARTS_rec_str.CMType == 0) UARTS_rec_str.Data_p[(int)UARTS_rec_str.RegAdd] = realloc(UARTS_rec_str.Data_p[(int)UARTS_rec_str.RegAdd], UARTS_rec_str.BytesInf*sizeof(char));
// 						if(UARTS_rec_str.BytesInf > MaxPackBytes){
// 							// >MaxDataBytes
// 							Pack1st=0;
// 							ByteSum = ByteSum+MaxPackBytes;
// 						}
// 						else{
// 							// <=MaxDataBytes
// 							Pack1st=1;
// 							ByteSum = ByteSum+UARTS_rec_str.BytesInf;
// 						}
// 					}
// 					else{
// 						// >32的末筆
// 						Pack1st=1;
// 						ByteSum = ByteSum+UARTS_rec_str.BytesInf;
// 					}
// 				}
// 				if( ByteSum == UARTS_rec_str.Bytes[(int)UARTS_rec_str.RegAdd] || Pack1st == 0 ){
// 					ByteSum=ByteSum%UARTS_rec_str.Bytes[(int)UARTS_rec_str.RegAdd];
// 					if(UARTS_rec_str.CMType == 0) UARTS_rec_str.statuse = 4;
// 					else if(UARTS_rec_str.CMType == 1) UARTS_rec_str.statuse = 5;
// 				}
// 				else{
// 					UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi] = 1;
// 					// 代表NG之碼1
// 					UARTS_trm_buffer.BWi = (UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 					UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi] = 1;
// 					// CheckSum=OK碼1
// 					UARTS_trm_buffer.BWi = (UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 					UARTS_rec_str.statuse = 1;
// 					M128_UARTS_tx();
// 				}
// 			break;
// 			case 4:
// 				*(UARTS_rec_str.Data_p[(int)UARTS_rec_str.RegAdd]+UARTS_rec_str.RRWi)=UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				check_sum=check_sum+UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				UARTS_rec_str.BRi=(UARTS_rec_str.BRi+1)%MaxPackBytes;
// 				UARTS_rec_str.RRWi=(UARTS_rec_str.RRWi+1)%UARTS_rec_str.Bytes[(int)UARTS_rec_str.RegAdd];
// 				if(Pack1st == 1){
// 					if(UARTS_rec_str.RRWi == 0) UARTS_rec_str.statuse=5;
// 				}
// 				else{
// 					if(UARTS_rec_str.RRWi%MaxPackBytes == 0) {
// 						UARTS_rec_str.statuse=5;
// 					}
// 				}
// 			break;
// 			case 5:
// 				UARTS_rec_str.InCheckSum=UARTS_rec_str.Buffer[(int)UARTS_rec_str.BRi];
// 				UARTS_rec_str.BRi=(UARTS_rec_str.BRi+1)%MaxPackBytes;
// 				if(UARTS_rec_str.InCheckSum != check_sum){
// 					UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi] = 2;
// 					// 代表NG之碼2
// 					UARTS_trm_buffer.BWi = (UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 					UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi] = 2;
// 					// CheckSum=OK碼2
// 					UARTS_trm_buffer.BWi = (UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 				}
// 				else{
// 					switch(UARTS_rec_str.CMType){
// 						case 0:
// 							// 建OK不含資料回應封包
// 							UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi]=0;
// 							// 代表OK之碼0
// 							UARTS_trm_buffer.BWi=(UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 							UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi]=0;
// 							// CheckSum=OK碼0
// 							UARTS_trm_buffer.BWi=(UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 						break;
// 						case 1:
// 							check_sum=0;
// 							// 建OK含資料回應封包
// 							UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi]=0;
// 				 			// 代表OK之碼0
// 							UARTS_trm_buffer.BWi=(UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 							if(Pack1st==1){
// 								for(int i=0;i<UARTS_rec_str.BytesInf;++i){
// 									UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi] = *(UARTS_rec_str.Data_p[(int)UARTS_rec_str.RegAdd]+UARTS_rec_str.RRWi);
// 									UARTS_rec_str.RRWi=(UARTS_rec_str.RRWi+1)%UARTS_rec_str.Bytes[(int)UARTS_rec_str.RegAdd];
// 									check_sum=check_sum+UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi];
// 									UARTS_trm_buffer.BWi=(UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 								}
// 							}
// 							else{
// 								for(int i=0;i<MaxPackBytes;++i){
// 									UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi] = *(UARTS_rec_str.Data_p[(int)UARTS_rec_str.RegAdd]+UARTS_rec_str.RRWi);
// 									UARTS_rec_str.RRWi=(UARTS_rec_str.RRWi+1)%UARTS_rec_str.Bytes[(int)UARTS_rec_str.RegAdd];
// 									check_sum=check_sum+UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi];
// 									UARTS_trm_buffer.BWi=(UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 								}
// 							}
// 							UARTS_trm_buffer.Buffer[(int)UARTS_trm_buffer.BWi] = check_sum;
// 							UARTS_trm_buffer.BWi=(UARTS_trm_buffer.BWi+1)%(MaxPackBytes+4);
// 						break;
// 					}
// 				}
// 				UARTS_rec_str.statuse=1;
// 				M128_UARTS_tx();
// 			break;
// 		}
// 	}
// }
//
//
// char M128_UARTM_tpk(char OneSLA, char UARTID, char RegAdd, char BytesInf, void *Data_p){
// 	static char status=0;
// 	static char RRWi=0;
// 	char PackByte=0;
// 	char check;
// 	char CMType;
// 	char check_sum=0;
// 	int Poll;
// 	char ReadByte;
// 	char Res=0;
// 	char ResCheck;
// 	if(OneSLA!=1){
// 		UCSR1B|=(1<<TXB81);
// 		check=M128_UART_put(0, 1, &UARTID);
// 		if(check!=0)	return 1;
// 	}
// 	UCSR1B &= ~(1<<TXB81);
// 	CMType=0;
// 	check=M128_UART_put(0, 1, &CMType);
// 	if(check!=0)	return 2;
// 	check_sum=check_sum+CMType;
// 	check=M128_UART_put(0, 1, &RegAdd);
// 	if(check!=0)	return 2;
// 	check_sum=check_sum+RegAdd;
// 	check=M128_UART_put(0, 1, &BytesInf);
// 	if(check!=0)	return 2;
// 	check_sum=check_sum+BytesInf;
// 	switch (status){
// 		case 0:
// 			if (BytesInf>MaxPackBytes){
// 				RRWi=0;
// 				PackByte=MaxPackBytes;
// 				status=1;
// 			}
// 			else if(BytesInf == 0){
// 				RRWi=0;
// 				return 3;
// 			}
// 			else{
// 				RRWi=0;
// 				PackByte=BytesInf;
// 			}
// 		break;
// 		case 1:
// 			if(BytesInf > 0){
// 				PackByte=BytesInf;
// 				status=0;
// 			}
// 			else if(BytesInf > MaxPackBytes){
// 				RRWi=0;
// 				return 3;
// 			}
// 			else{
// 				PackByte=MaxPackBytes;
// 			}
// 		break;
// 	}
// 	for(int i=0;i<PackByte;++i){
// 		check=M128_UART_put(0, 1, ((char*)Data_p)+RRWi);
// 		if(check!=0)	return 2;
// 		check_sum=check_sum+*(((char*)Data_p)+RRWi);
// 		RRWi++;
// 	}
// 	check=M128_UART_put(0, 1, &check_sum);
// 	if(check!=0)	return 2;
// 	Poll=MAXPoi;
// 	ReadByte=0;
// 	while(Poll!=0 || ReadByte <2){
// 		if(UARTS_mastrec_buffer.BWi!=UARTS_mastrec_buffer.BRi){
// 			if(ReadByte==0){
// 				Res=UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BRi];
// 				UARTS_mastrec_buffer.BRi=(UARTS_mastrec_buffer.BRi+1)%(MaxPackBytes+4);
// 			}
// 			else{
// 				ResCheck=UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BRi];
// 				UARTS_mastrec_buffer.BRi=(UARTS_mastrec_buffer.BRi+1)%(MaxPackBytes+4);
// 				if(Res == ResCheck) return Res;
// 				else return 5;
// 			}
// 			ReadByte++;
// 			Poll=MAXPoi;
// 		}
// 		else{
// 			Poll=Poll-1;
// 		}
// 	}
// 	return 4;
// }
//
// char M128_UARTM_rpk(char OneSLA,char UARTID, char RegAdd, char BytesInf, void* Data_p){
// 	static char status=0;
// 	static char RRWi=0;
// 	char PackByte=0;
// 	char check;
// 	char CMType;
// 	char check_sum=0;
// 	int Poll;
// 	char Flied;
// 	char Res=0;
// 	char tem[32];
// 	int twi=0;
// 	char ResCheck;
// 	if(OneSLA!=1){
// 		UCSR1B|=(1<<TXB81);
// 		check=M128_UART_put(0, 1, &UARTID);
// 		if(check!=0)	return 1;
// 	}
// 	UCSR1B &= ~(1<<TXB81);
// 	CMType=1;
// 	check=M128_UART_put(0, 1, &CMType);
// 	if(check!=0)	return 2;
// 	check_sum=check_sum+CMType;
// 	check=M128_UART_put(0, 1, &RegAdd);
// 	if(check!=0)	return 2;
// 	check_sum=check_sum+RegAdd;
// 	check=M128_UART_put(0, 1, &BytesInf);
// 	if(check!=0)	return 2;
// 	check_sum=check_sum+BytesInf;
// 	switch (status){
// 		case 0:
// 			if (BytesInf>MaxPackBytes){
// 				RRWi=0;
// 				PackByte=MaxPackBytes;
// 				status=1;
// 			}
// 			else if(BytesInf == 0){
// 				RRWi=0;
// 				return 3;
// 			}
// 			else{
// 				RRWi=0;
// 				PackByte=BytesInf;
// 			}
// 		break;
// 		case 1:
// 			if(BytesInf > 0){
// 				PackByte=BytesInf;
// 				status=0;
// 			}
// 			else if(BytesInf > MaxPackBytes){
// 				RRWi=0;
// 				return 3;
// 			}
// 			else{
// 				PackByte=MaxPackBytes;
// 			}
// 		break;
// 	}
// 	check=M128_UART_put(0, 1, &check_sum);
// 	if(check!=0)	return 2;
//
// 	Poll=MAXPoi;
// 	Flied=0;
// 	check_sum=0;
// 	while(Poll!=0){
// 		if(UARTS_mastrec_buffer.BWi!=UARTS_mastrec_buffer.BRi){
// 			switch(Flied){
// 				case 0:
// 					Res=UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BRi];
// 					UARTS_mastrec_buffer.BRi=(UARTS_mastrec_buffer.BRi+1)%(MaxPackBytes+4);
// 					check_sum=check_sum+Res;
// 					if(Res==0){
// 						Flied=1;
// 					}
// 					else{
// 						Flied=2;
// 					}
// 				break;
// 				case 1:
// 					tem[twi]=UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BRi];
// 					check_sum=check_sum+UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BRi];
// 					UARTS_mastrec_buffer.BRi=(UARTS_mastrec_buffer.BRi+1)%(MaxPackBytes+4);
// 					twi++;
// 					if(twi==PackByte) Flied=2;
// 				break;
// 				case 2:
// 					ResCheck=UARTS_mastrec_buffer.Buffer[(int)UARTS_mastrec_buffer.BRi];
// 					UARTS_mastrec_buffer.BRi=(UARTS_mastrec_buffer.BRi+1)%(MaxPackBytes+4);
// 					if(check_sum==ResCheck){
// 						if(Res==0){
// 							for (int i = 0; i < PackByte; ++i) {
// 								*((char*)Data_p+RRWi)=tem[i];
// 								RRWi++;
// 							}
// 						}
// 						return Res;
// 					}
// 					else{
// 						return 5;
// 					}
// 				break;
// 			}
// 			Poll=MAXPoi;
// 		}
// 		else{
// 			Poll=Poll-1;
// 		}
// 	}
// 	return 4;
// }

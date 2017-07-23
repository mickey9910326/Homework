// #include "ASA_UART_pac.h"
// #include "ASA_UART.h"
// #include "ASA_DEVICE.h"
// #include "bit_op.h"
//
// char M128_UARTM_trm(char OneSLA, char OneReg, char UARTID, char RegAdd, char Bytes, void* Data_p){
// 	char check=0;
// 	if(OneSLA!=1){
//         bit_set(UCSR1B,TXB81);
// 		check=M128_UART_put(0, 1, &UARTID);
// 		if(check!=0)	return 1;
// 	}
// 	if(OneReg!=1){
//         bit_clear(UCSR1B,TXB81);
// 		check=M128_UART_put(0, 1, &RegAdd);
// 		if(check!=0)	return 2;
// 	}
// 	for (int i = 0; i < Bytes; ++i){
//         bit_clear(UCSR1B,TXB81);
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

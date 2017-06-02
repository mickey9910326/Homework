#ifndef __ASA_TWI_H__
#define __ASA_TWI_H__

//Commutication Standard - TWI
//--------------------------------------------------------------------------------------------------------------------
/*Status codes for start and restart condition*/
#define TWI_START			0x08
#define TWI_REP_START		0x10
//--------------------------------------------------------------------------------------------------------------------
/*Status codes for master transmitter mode*/
#define TWI_MT_SLA_ACK		0x18
#define TWI_MT_SLA_NACK		0x20
#define TWI_MT_DATA_ACK		0x28
#define TWI_MT_DATA_NACK	0x30
#define TWI_MT_ARB_LOST		0x38
//--------------------------------------------------------------------------------------------------------------------
/*Status codes for master receiver mode*/
#define TWI_MR_SLA_ACK		0x40
#define TWI_MR_SLA_NACK		0x48
#define TWI_MR_DATA_ACK		0x50
#define TWI_MR_DATA_NACK	0x58
#define TWI_MR_ARB_LOST	    0x38
//--------------------------------------------------------------------------------------------------------------------
#define TWI_STATUS	((TWSR)&(0xF8))
//--------------------------------------------------------------------------------------------------------------------
char M128_TWI_set(char LSByte, char Mask, char shift, char Data);
char M128_TWI_fpt(char LSByte, char Mask, char shift, char Data);
char M128_TWI_fgt(char LSByte, char Mask, char shift, char* Data_p);
char M128_TWI_trm(char NoAdd, char SLA, char Addr, char Bytes, void *Data_p);
char M128_TWI_rec(char NoAdd, char SLA, char Addr, char Bytes, void *Data_p);

#endif

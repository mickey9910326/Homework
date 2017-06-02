#include "ASA_TWI.h"
#include "ASA_DEVICE.h"
#include "bit_op.h"

//Global Variables
static volatile char write_to_read=0;

void TWI_ERROR(void) {
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);       //Transmit STOP condition
}

//--------------------------------------------------------------------------------------------------------------------
char TWI_Start(void)
{
	TWCR = (1 << TWINT)|(1 << TWSTA)|(1 << TWEN);
	while (!(TWCR & (1<<TWINT)));
	if (TWI_STATUS != TWI_START)
	{
		TWI_ERROR();
		return 1;
	}
	else
		return 0;
}
//--------------------------------------------------------------------------------------------------------------------
void TWI_Stop(void)
{
	TWCR = (1 << TWINT)|(1 << TWEN)|(1 << TWSTO);
}
//--------------------------------------------------------------------------------------------------------------------
char TWI_ReStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if (TWI_STATUS != TWI_REP_START)
	{
		TWI_ERROR();
		return 2;
	}
	else
		return 0;
}
//--------------------------------------------------------------------------------------------------------------------
void TWI_SendSLAW(unsigned char addr)
{
	TWDR = (addr << 1)& 0XFE;
	TWCR = (1 << TWINT)|(1 << TWEN);
	while (!(TWCR & (1<<TWINT)));
	if(TWI_STATUS != TWI_MT_SLA_ACK){TWI_ERROR();}
}
//--------------------------------------------------------------------------------------------------------------------
void TWI_SendSLAR(unsigned char addr)
{
	TWDR = (addr << 1) + 1;
	TWCR = (1 << TWINT)|(1 << TWEN);
	while (!(TWCR & (1<<TWINT)));
	if(TWI_STATUS != TWI_MR_SLA_ACK){TWI_ERROR();}
}
//--------------------------------------------------------------------------------------------------------------------
void TWI_TransmitData(unsigned char data)
{
	TWDR = data;
	TWCR = (1 << TWINT)|(1 << TWEN);
	while (!(TWCR & (1<<TWINT)));
	if(TWI_STATUS != TWI_MT_DATA_ACK){TWI_ERROR();}
}
//--------------------------------------------------------------------------------------------------------------------
unsigned char TWI_ReceiveData(void)
{
	unsigned char data;
	TWCR = (1 << TWINT)|(1 << TWEN)|(1 << TWEA);
	while (!(TWCR & (1<<TWINT)));
	if(TWI_STATUS != TWI_MR_DATA_ACK){TWI_ERROR();}
	data = TWDR;
	return data;
}
//--------------------------------------------------------------------------------------------------------------------
void TWI_SendNoAck(void)
{
	TWCR = (1 << TWINT)|(1 << TWEN);
	while (!(TWCR & (1<<TWINT)));
	if(TWI_STATUS != TWI_MR_DATA_NACK){TWI_ERROR();}
}
//--------------------------------------------------------------------------------------------------------------------
void TWI_wr(unsigned char Saddress,unsigned char SRegSet, unsigned char data)
{
	TWI_Start();
	TWI_SendSLAW(Saddress);
	TWI_TransmitData(SRegSet);
	TWI_TransmitData(data);
	TWI_Stop();
}
//--------------------------------------------------------------------------------------------------------------------
unsigned char TWI_rd(unsigned char Saddress,unsigned char SRegSet)
{
	unsigned char data;
	TWI_Start();
	TWI_SendSLAW(Saddress);
	TWI_TransmitData(SRegSet);
	TWI_ReStart();
	TWI_SendSLAR(Saddress);
	data = TWI_ReceiveData();
	TWI_SendNoAck();
	TWI_Stop();
	return data;
}
//--------------------------------------------------------------------------------------------------------------------
void TWI_initialize(char speed)
{
	TWBR = speed;

}
//--------------------------------------------------------------------------------------------------------------------
/* extra use */
char TWI_Write(char address, char *data, char n)
{
	unsigned int SLA_W = (address<<1) & 0XFE;
	char chk;

	chk=TWI_Start();
	if(chk==1)
		return chk;

	//---------------------------
	TWDR = SLA_W;
	TWCR = (1<<TWINT)|(1<<TWEN);

	while (!(TWCR & (1<<TWINT)));
	if (TWI_STATUS != TWI_MT_SLA_ACK)
	{
		TWI_ERROR();
		return 3;
	}
	//---------------------------
	for(char i=0;i<n;i++)
	{
		TWDR = *(data+i);
		TWCR = (1<<TWINT)|(1<<TWEN);

		while (!(TWCR & (1<<TWINT)));
		if (TWI_STATUS != TWI_MT_DATA_ACK)
		{
			TWI_ERROR();
			return 4;
		}
	}

	if(n>1)
	{
		TWI_Stop();
	}
	else
		write_to_read=1;

	return 0;
}

char TWI_Read(char address, char *data, char n)
{
	unsigned int SLA_R = (address<<1) | 0X01;
	char chk;

	if(write_to_read==1)
	{
		chk=TWI_ReStart();
		if(chk==2)
			return chk;

		write_to_read=0;
	}
	else
		chk=TWI_Start();
		if(chk==1)
			return chk;
	//---------------------------
	TWDR = SLA_R;
	TWCR = (1<<TWINT)|(1<<TWEN);

	while (!(TWCR & (1<<TWINT)));
	if (TWI_STATUS != TWI_MR_SLA_ACK)
	{
		TWI_ERROR();
		return 5;
	}
	//---------------------------
	if(n>1)
	{
		for(char i=0;i<(n-1);i++)
		{
			TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);

			while (!(TWCR & (1<<TWINT)));
			if (TWI_STATUS != TWI_MR_DATA_ACK)
			{
				TWI_ERROR();
				return 6;
			}

			*(data+i) = TWDR;
		}
		TWCR = (1<<TWINT)|(1<<TWEN);

		while (!(TWCR & (1<<TWINT)));
		if (TWI_STATUS != TWI_MR_DATA_NACK)
		{
			TWI_ERROR();
			return 7;
		}

		*(data+(n-1)) = TWDR;				//burst read �� data�̫��@���O�SACK��
	}
	else
	{
		TWCR = (1<<TWINT)|(1<<TWEN);

		while (!(TWCR & (1<<TWINT)));
		if (TWI_STATUS != TWI_MR_DATA_NACK) {
			TWI_ERROR();
			return 8;
		}

		*(data) = TWDR;				//data�̫��@���O�SACK��
	}


	TWI_Stop();

	return 0;
}
//--------------------------------------------------------------------------------------------------------------------

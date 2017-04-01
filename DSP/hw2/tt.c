#include "LIB\ASA_Lib.h"

#define SPI_SS PB0
#define SPI_SCK PB1
#define SPI_MOSI PB2
#define CS_test PF4
#define ADDR0 PB5
#define ADDR1 PB6
#define ADDR2 PB7

#define bit(m) (1<<(m))
#define bit_clear(p,m) ((p)&= ~bit(m))  //clear the bit m of p

void SPI_Init(void)
	{
	/* Set MOSI and SCK output, all others input */
	DDRB = (1<<SPI_SS)|(1<<SPI_SCK)|(1<<SPI_MOSI)|(1<<ADDR0)|(1<<ADDR1)|(1<<ADDR2);
	DDRF = (1<<CS_test);
	/* Enable SPI, Master, set clock rate fck/16 */
	SPCR = (1<<SPE)|(1<<MSTR)|(0<<SPR0)|(1<<SPR1)|(0<<CPOL)|(0<<CPHA);

	}

char SPI_Transmit_Receive(char cData)
	{
	/* Start transmission */
	SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
	return SPDR;
	}

void MAX7219(char reg,char data)
	{

	PORTF = (1<<PF4);
	SPI_Transmit_Receive(reg);
	SPI_Transmit_Receive(data);
	PORTF = (0<<PF4);
	}

char m[8]={
			0b11111111,
			0b01000000,
			0b00100000,
			0b00010000,
			0b00001000,
			0b00000100,
			0b00000010,
			0b11111111
		};



char t1=0,t2=0;
float T=0;
int main()
{
	ASA_M128_set();
	PORTB = 0b01110111;
	SPI_Init();


	//Scan Limit
	MAX7219(0x0b,0x07);

	//Decode Mode
//	MAX7219(0x09,0x00);

	//Display Test
	MAX7219(0x0f,0x00);

	//Intensity
	MAX7219(0x0a,0x01);

	//Shutdown
	MAX7219(0x0c,0x01);

	int i=1,j=1;

	char A=0b00000011;
	A=bit_clear(A,1);

	printf("%d\n",A);


	while(1)
		{
		for(int y=1;y<=8;y++){MAX7219(y,m[y-1]);}
		//MAX7219(0x0c,0x00);
		printf("www");
		_delay_ms(50);

		}

}

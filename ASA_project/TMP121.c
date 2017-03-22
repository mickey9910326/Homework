#include "ASA_Lib.h"

#define  _BV(bit)	   (1 << (bit))
#define  _bit_set(p,m)   ((p)|= _BV(m))
#define  _bit_clear(p,m) ((p)&= _BV(m))
#define  _bit_get(p,m)   (((p)& _BV(m)) >>m)
#define  _bit_is_set(p,m)
#define  _bit_is_clear(p,m)

char M128_SPI_swap(char cData);
char SPI_Transmit(char cData);
char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data);
char M128_SPI_put(char NoAdd, char Addr, char Bytes, void *Data_p);
char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p);


int main(void)
{
	ASA_M128_set();
    double TEM;
    char H,L;
    printf("start!-----------------------------\n");
	M128_SPI_set(200,0xFF,0,(1<<SPE)|(1<<MSTR)|(1<<SPR0));
    while (1){
        _delay_ms(250);                     //轉換時間長，CS腳須維持 250ms才能完成一次轉換
        PORTB = 32;          //enable TM121 CS to start transfer data
        H = SPI_Transmit(0); //receive the High byte from TM121
        L = SPI_Transmit(0); //receive the Low  byte from TM121
        PORTB = 0 ;          //disable TM121 CS
        TEM = (double)((H<<5) + (L>>3)) *0.0625; //translate 2byte data to temptature
        printf("TEMP = %f\n",TEM);
    }
	return 0;
}

void M128_SPI_ini(void){
	DDRB = ((1<<DDB2)|(1<<DDB1)|(1<<DDB0)); //spi pins on port b MOSI SCK,SS outputs
	SPCR = ((1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<CPOL)|(1<<CPHA));  // SPI enable, Master, f/16
}

char M128_SPI_swap(char cData){
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;
}

char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data) {
	// FIXME muti-set? when to set DDRB?
	// DDRB = ((1<<DDB2)|(1<<DDB1)|(1<<DDB0)); //spi pins on port b MOSI SCK,SS outputs
	if ( LSByte==200 ) {
		SPCR = Data;
	} else if ( LSByte==201 ) {
		_bit_set(SPSR,SPI2X);
	}

	// _bit_set(DDRB, m)
	return 0;
}

char M128_SPI_put(char NoAdd, char Addr, char Bytes, void *Data_p) {
	char i;
	if ( NoAdd ) {
		M128_SPI_swap(Addr);
	}
	for (i = 0; i < Bytes; i++) {
		*((char*)Data_p) = M128_SPI_swap( *((char*)Data_p) );
	}

	return 0;
}

char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p) {
	char i;
	if ( NoAdd ) {
		M128_SPI_swap(Addr);
	}
	for (i = 0; i < Bytes; i++) {
		*((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p) );
	}

	return 0;
}

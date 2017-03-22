#include "ASA_SPI.h"
#define  _bit_set(p,m)   ((p)|= _BV(m))

void M128_SPI_ini(void){
	// DDR_SPI = ((1<<DD_MOSI)|(1<<DD_SCK)); //spi pins on port b MOSI SCK,SS outputs
	DDRB = ((1<<DDB2)|(1<<DDB1)|(1<<DDB0)); //spi pins on port b MOSI SCK,SS outputs
	// SPCR = ((1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<CPOL)|(1<<CPHA));  // SPI enable, Master, f/16
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
	if ( !NoAdd ) {
		M128_DIO_set(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,Addr);
	}
	for (i = 0; i < Bytes; i++) {
		*((char*)Data_p) = M128_SPI_swap( *((char*)Data_p) );
	}
	if ( !NoAdd ) {
		M128_DIO_set(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,0);
	}

	return 0;
}

char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p) {
	char i;
	if ( !NoAdd ) {
		M128_DIO_set(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,Addr);
	}
	for (i = 0; i < Bytes; i++) {
		*((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p) );
	}
	if ( !NoAdd ) {
		M128_DIO_set(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,0);
	}

	return 0;
}

#include "ASA_SPI.h"
#define  _bit_set(p,m)   ((p)|= _BV(m))

char M128_SPI_swap(char cData){
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;
}

char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data) {
	if(LSByte < 200 || LSByte > 202) { return 2; }
	if(shift  < 0   || shift  >   7) { return 3; }

	//spi pins on port b MOSI SCK,SS outputs
	const char MSTR_DDR = ((1<<DDB2)|(1<<DDB1)|(1<<DDB0));
	M128_DIO_fpt(DDR_SPI_num,15,0, MSTR_DDR);
	if ( LSByte==200 ) {
		SPCR |= (Data&Mask);
	} else if ( LSByte==201 ) {
		_bit_set(SPSR,SPI2X);
	}

	// _bit_set(DDRB, m)
	return 0;
}

char M128_SPI_put(char NoAdd, char Addr, char Bytes, void *Data_p) {

	if(Bytes < 0 ) { return 3; }

	// TODO check the size of Data_p is enough to put Bytes data

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

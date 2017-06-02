#include "ASA_SPI.h"
#include "ASA_DEVICE.h"
#include "bit_op.h"

char M128_SPI_swap(char cData){
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;
}

char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data) {
	if(LSByte < 200 || LSByte > 202) { return 1; }
	if(shift  < 0   || shift  >   7) { return 2; }

	if ( LSByte==200 ) {
		bits_put(SPCR,Data,Mask,shift);
		// SPCR = (SPCR&(~Mask))|(Data&Mask);
	} else if ( LSByte==201 ) {
		bits_put(SPSR,Data,Mask,shift);
		// SPSR = (SPSR&(~Mask))|(Data&Mask);
	}
	return 0;
}

char M128_SPI_put(char NoAdd, char Addr, char Bytes, void *Data_p) {
	if ( NoAdd > 2 ) { return 1; }
	if ( Bytes < 0 ) { return 3; }
	char wrong = 0;
	char i;

	if ( !NoAdd ) {
		M128_SPI_swap(Addr);
		if ( bit_get(SPSR,WCOL) ) { wrong = 4; }
	}
	for (i = 0; i < Bytes; i++) {
		 *((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p +i) );
		 if ( bit_get(SPSR,WCOL) ) { wrong = 4; }
	}

	return wrong;
}

char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p) {
	if ( NoAdd > 2 ) { return 1; }
	if ( Bytes < 0 ) { return 3; }

	int i;

	if ( !NoAdd ) {
		M128_SPI_swap(Addr);
	}
	for (i = 0; i < Bytes; i++) {
		 *((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p +i) );
	}

	return 0;
}

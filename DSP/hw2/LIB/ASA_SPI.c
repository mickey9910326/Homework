#include <avr/io.h>
#include "ASA_DIO.h"
#include "ASA_SPI.h"
#include "ASA_general.h"

char M128_SPI_swap(char cData){
	SPDR = cData;
	while(!(SPSR & (1<<SPIF)))
		;
	return SPDR;
}

// char M128_SPI_swap_with_timeout(char cData,char timeout){
// 	SPDR = cData;
// 	uint8_t t = 0;
// 	while(!(SPSR & (1<<SPIF)) && t<timeout){
// 		t++;
// 		_delay_us(1);
// 	}
// 	return SPDR;
// }

char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data) {
	if(LSByte < 200 || LSByte > 202) { return 1; }
	if(shift  < 0   || shift  >   7) { return 2; }

	//spi pins on port b MOSI SCK,SS outputs
	const char MSTR_DDR = ((1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS));
	M128_DIO_set(200+DDR_SPI_num,15,0, 0);
	M128_DIO_set(200+DDR_SPI_num,15,0, MSTR_DDR);

	//set CS pin (PF4) output 0
	M128_DIO_set(200+CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);

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
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);

	if ( !NoAdd ) {
		M128_SPI_swap(Addr);
		if ( SPSR&(1<<WCOL) ) { wrong = 4; }
	}
	for (i = 0; i < Bytes; i++) {
		 *((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p +i) );
		 if ( SPSR&(1<<WCOL) ) { wrong = 4; }
	}
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);

	return wrong;
}

char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p) {
	if ( NoAdd > 2 ) { return 1; }
	if ( Bytes < 0 ) { return 3; }

	int i;
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);

	if ( !NoAdd ) {
		M128_SPI_swap(Addr);
	}
	for (i = 0; i < Bytes; i++) {
		 *((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p +i) );
	}
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);

	return 0;
}

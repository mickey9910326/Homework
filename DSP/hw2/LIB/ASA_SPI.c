#include "ASA_SPI.h"
#define  _bit_set(p,m)   ((p)|= _BV(m))

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
// 		_delay_ms(1);
// 	}
// 	return SPDR;
// }

char M128_SPI_set(char LSByte, char Mask,  char shift,  char Data) {
	if(LSByte < 200 || LSByte > 202) { return 1; }
	if(shift  < 0   || shift  >   7) { return 2; }

	//spi pins on port b MOSI SCK,SS outputs
	const char MSTR_DDR = ((1<<DDB2)|(1<<DDB1)|(1<<DDB0));
	M128_DIO_set(DDR_SPI_num,15,0, MSTR_DDR);

	//set CS pin (PB5) output 0
	M128_DIO_set(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);

	// set ADDR pins (PB5~7) as output
	M128_DIO_set(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,7);

	if ( LSByte==200 ) {
		SPCR |= (Data&Mask);
	} else if ( Data==201 ) {
		if ( Data!=(1<<SPI2X) ) {
			// invaild write
			// NOTE is this error number required?
			return 3;
		}
		SPSR |= (Data&Mask);
	}
	return 0;
}

char M128_SPI_put(char NoAdd, char Addr, char Bytes, void *Data_p) {
	if ( NoAdd > 2 ) { return 1; }
	if ( Addr  > 7 ) { return 2; }
	if ( Bytes < 0 ) { return 3; }

	// TODO check the size of Data_p is enough to put Bytes data
	int i;
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
	if ( !NoAdd ) {
		M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,Addr);
	}
	for (i = 0; i < Bytes; i++) {
		 *((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p +i) );    //receive the High byte from TM121
	}
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
	// ADDR禁能->IC斷電?->致能後需要轉換時間
	// if ( !NoAdd ) {
	// 	M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,0);
	// }

	return 0;
}

char M128_SPI_get(char NoAdd, char Addr, char Bytes, void *Data_p) {
	if ( NoAdd > 2 ) { return 1; }
	if ( Addr  > 7 ) { return 2; }
	if ( Bytes < 0 ) { return 3; }

	int i;
	if ( !NoAdd ) {
		M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,Addr);
	}
	// _delay_ms(250);
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 1);
	for (i = 0; i < Bytes; i++) {
		 *((char*)Data_p +i) = M128_SPI_swap( *((char*)Data_p +i) );    //receive the High byte from TM121
	}
	M128_DIO_fpt(CS_PORT_NUM, CS_PORT_MSK, CS_PORT_SHT, 0);
	// ADDR禁能->IC斷電?->致能後需要轉換時間
	// BUG
	// if ( !NoAdd ) {
	// 	M128_DIO_fpt(ADDR_PORT_num,ADDR_PORT_msk,ADDR_PORT_sht,0);
	// }

	return 0;
}

#include "ASA_UART.h"
#include "ASA_DEVICE.h"
#include "bit_op.h"

void UART1_putchar(char  data)
{
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = data;

	// _delay_us(250);	//wait for data transmitting
}

char UART1_getchar(void)
{
	while(!(UCSR1A & (1<<RXC1)));

	return UDR1;
}

void UART1_init()
{
    unsigned int baud;
    baud = F_CPU/16/USART_baud-1;

    UBRR1H = (unsigned char)(baud>>8);
	UBRR1L = (unsigned char)baud;

	UCSR1B |= (1<<RXEN1) | (1<<TXEN1);
	UCSR1C |= (3<<UCSZ10);
}


void uart1_transmit (char c){
	while(!(UCSR1A&(1<<UDRE1)));
	UDR1 = c;
}

char uart1_receive(void){
	while(!(UCSR1A & (1<<RXC1)));
	return UDR1;
}

char M128_UART_set(char LSByte, char Mask, char shift, char Data) {
	if (LSByte<200 || LSByte>204) return 1;
	if (Mask<0 || Mask>255) return 2;
	if(shift<0 || shift>7) return 3;
	volatile uint8_t *Dest;
	switch(LSByte){
		case 200: Dest = &UCSR1A; break;
		case 201: Dest = &UCSR1B; break;
		case 202: Dest = &UCSR1C; break;
		case 203: Dest = &UBRR1L; break;
		case 204: Dest = &UBRR1H; break;
		default : return 1;
	}
	bits_put(*Dest, Data, Mask, shift);
	return 0;
}

char M128_UART_put(char LSByte, char Bytes, char* Data_p) {
	if(LSByte!=0) return 1;
	if(Bytes!=1) return 2;
	UDR1 = *Data_p;
	return 0;
}

char M128_UART_get(char LSByte, char Bytes, char* Data_p) {
	if(LSByte!=0) return 1;
	if(Bytes!=1) return 2;
	*Data_p = UDR1;
	return 0;
}

char M128_UART_fpt(char LSByte, char Mask, char shift, char Data) {
	if (LSByte<200 || LSByte>201) return 1;
	if (Mask<0 || Mask>255) return 2;
	if (shift<0 || shift>7) return 3;
	char def_mask;
	volatile uint8_t *Dest;
	switch(LSByte){
		case 200: Dest = &UCSR1A; def_mask = 0xff; break;
		case 201: Dest = &UCSR1B; def_mask = 0xff; break;
		default : return 1;
	}
	bits_put(*Dest, Data, (Mask&def_mask), shift);
	return 0;
}

char M128_UART_fgt(char LSByte, char Mask, char shift, char* Data_p) {
	if(LSByte!=200) return 1;
	if (Mask<0 || Mask>255) return 1;
	if(shift<0 || shift>7) return 1;
	*Data_p=bits_get(UCSR1A, Mask, shift);
	return 0;
}

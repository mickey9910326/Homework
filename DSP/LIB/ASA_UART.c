#include "ASA_UART.h"
#include "ASA_DEVICE.h"
#include "bit_op.h"

void UART1_putchar(char  data)
{
	while(!(UCSR1A & (1<<UDRE1)));
	UDR1 = data;

	_delay_us(250);	//wait for data transmitting
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

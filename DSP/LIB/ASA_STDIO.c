//Last Build : 2016/11/8 4pm
#include "ASA_DEVICE.h"
#include "ASA_STDIO.h"
#include <stdio.h>

//Internal Function Prototypes

int stdio_putchar(char c, FILE *stream);
int stdio_getchar(FILE *stream);

static FILE STDIO_BUFFER = FDEV_SETUP_STREAM(stdio_putchar, stdio_getchar, _FDEV_SETUP_RW);

int stdio_putchar(char c, FILE *stream)
{
   if (c == '\n')
        stdio_putchar('\r',stream);

    while((UCSR0A&(1<<UDRE0))==0);

    UDR0 = c;

    return 0;
}

int stdio_getchar(FILE *stream)
{
	int UDR_Buff;

    while((UCSR0A&(1<<RXC0))==0);

	UDR_Buff = UDR0;

	stdio_putchar(UDR_Buff,stream);

	return UDR_Buff;
}

char ASA_STDIO_set(void)
{
	unsigned int baud;

	baud = F_CPU/16/USART_baud-1;
	UBRR0H = (unsigned char)(baud>>8);
	UBRR0L = (unsigned char)baud;

	UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
	UCSR0C |= (3<<UCSZ00);

	stdout = &STDIO_BUFFER;
	stdin = &STDIO_BUFFER;

	return 0;
}

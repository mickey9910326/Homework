#include "..\..\LIB\ASA_DEVICE.h"
#include "..\..\LIB\ASA_STDIO.h"
#include "..\..\LIB\ASA_UART.h"
#include "..\..\LIB\ASA_core_lib.h"

void UART_init();

int main() {
    ASA_STDIO_set();
    ASA_ID_set(1);
    printf("Start-------------\n");
    UART_init();
    unsigned char data = 0;

    while (1) {
        data = UART1_getchar();
        printf("%d\n", data);
    }

    return 0;
}

void UART_init()
{
    unsigned int baud;
    baud = F_CPU/16/USART_baud-1;

    UBRR1H = (unsigned char)(baud>>8);
	UBRR1L = (unsigned char)baud;

	UCSR1B |= (1<<RXEN1) | (1<<TXEN1);
	UCSR1C |= (3<<UCSZ10);
}

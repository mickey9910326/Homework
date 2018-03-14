#include "..\..\LIB\ASA_DEVICE.h"
#include "..\..\LIB\ASA_STDIO.h"
#include "..\..\LIB\ASA_UART.h"
#include "..\..\LIB\ASA_core_lib.h"

void UART_init();

int main() {
    ASA_STDIO_set();
    ASA_ID_init();
    ASA_ID_set(1);
    printf("Start-------------\n");
    UART_init();
    unsigned char data = 0;
    int intput;

    while (1) {
        scanf("%d\n", &intput);
        data = intput;
        UART1_putchar(data);
    }

    return 0;
}

void UART_init() {
    unsigned int baud;
    baud = F_CPU/16/USART_baud-1;

	M128_UART_set(203, 0xff, 0, baud); // UBRR1H
	M128_UART_set(204, 0xff, 0, (baud)>>8); // UBRR1L
	M128_UART_set(201, (1<<RXEN1)|(1<<TXEN1), 0, (1<<RXEN1)|(1<<TXEN1)); // UCSR1B
	M128_UART_set(201, (1<<RXCIE1)|(1<<TXCIE1), 0, (1<<RXCIE1)|(0<<TXCIE1)); // UCSR1B
    M128_UART_set(202, (1<<UCSZ10)|(1<<UCSZ11), 0, (1<<UCSZ10)|(1<<UCSZ11)); // UCSR1C
}
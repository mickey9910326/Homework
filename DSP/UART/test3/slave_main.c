#include "..\..\LIB\ASA_DEVICE.h"
#include "..\..\LIB\ASA_STDIO.h"
#include "..\..\LIB\ASA_UART.h"
#include "..\..\LIB\ASA_UART_pac.h"
#include "..\..\LIB\ASA_core_lib.h"

void UART_init();
void print_buffer_data(TypeOfBuffer* Buffer_p);
extern TypeOfBuffer UART_trm_buffer;
extern TypeOfBuffer UART_rec_buffer;

int main() {
    ASA_STDIO_set();
    ASA_ID_set(1);
    printf("Start-------------\n");
    UART_init();
    sei();

    while (1) {
        print_buffer_data(&UART_rec_buffer);
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

void print_buffer_data(TypeOfBuffer* Buffer_p) {
    uint8_t i;
    int tmp;
    printf("G:%d,P:%d,data:",Buffer_p->GETindex,Buffer_p->PUTindex);
    for (i = 0; i < MAXBUFFBYTES; i++) {
        tmp = Buffer_p->data[i];
        printf("%d,", tmp );
    }
    printf("\n");
}

ISR(USART1_RX_vect) {
    unsigned char data = UART1_getchar();
    buffer_put(&UART_rec_buffer, data);
}

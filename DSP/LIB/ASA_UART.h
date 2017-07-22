#ifndef __ASA_UART_H__
#define __ASA_UART_H__

void UART1_putchar(char data);
char UART1_getchar(void);
void UART1_init();

char M128_UART_set(char LSByte, char Mask, char shift, char Data);
char M128_UART_put(char LSByte, char Bytes, char* Data_p);
char M128_UART_get(char LSByte, char Bytes, char* Data_p);
char M128_UART_fpt(char LSByte, char Mask, char shift, char Data);
char M128_UART_fgt(char LSByte, char Mask, char shift, char* Data_p);

#endif

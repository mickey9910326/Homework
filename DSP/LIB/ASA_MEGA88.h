#ifndef __ASA_MEGA88_H__
#define __ASA_MEGA88_H__

#define USART_baud 38400

//UART1
#define UART_PORT1	PORTD
#define UART_PIN1	PIND
#define UART_RXD1	PD1
#define UART_TXD1	PD2

//TWI
#define TWI_DDR_num 2
#define TWI_PORT	PORTC
#define TWI_PIN		PINC
#define TWI_DDR		DDRC
#define TWI_SCL		PC5
#define TWI_SDA		PC4

//SPI
#define SPI_DDR_num 1
#define SPI_PORT	PORTB
#define SPI_PIN		PINB
#define SPI_DDR		DDRB
#define SPI_MISO	PB4
#define SPI_MOSI	PB3
#define SPI_SCK		PB5
#define SPI_SS      PB2

//ASA_ID
#define ADDR_PORT	PORTB
#define ADDR_PIN	PINB
#define ADDR_DDR	DDRB
#define ADDR0       PB5
#define ADDR1       PB6
#define ADDR2       PB7

//DIO
#define DIO_PORT	PORTF
#define DIO_PIN		PINF
#define DIO_DDR		DDRF
#define DIO_RW_PORT	PORTG
#define DIO_RW_PIN	PING
#define DIO_RW_DDR	DDRG
#define DIO0		PF4
#define DIO1		PF5
#define DIO2		PF6
#define DIO3		PF7
#define DIO_RD		PG3
#define DIO_WR		PG4

#endif

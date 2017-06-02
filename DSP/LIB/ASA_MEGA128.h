#ifndef __ASA_MEGA128_H__
#define __ASA_MEGA128_H__

#define USART_baud 38400
// ASA_ID
#define ADDR_PORT_num 1
#define ADDR_PORT_msk (1<<5)|(1<<6)|(1<<7)
#define ADDR_PORT_sht 5

//UART1
#define UART_PORT1	PORTD
#define UART_PIN1	PIND
#define UART_RXD1	PD1
#define UART_TXD1	PD2

//TWI
#define TWI_PORT	PORTD
#define TWI_PIN		PIND
#define TWI_DDR		DDRD
#define TWI_SCL		PD0
#define TWI_SDA		PD1

//SPI
#define SPI_PORT	PORTB
#define SPI_PIN		PINB
#define SPI_DDR		DDRB
#define SPI_MISO	PB3
#define SPI_MOSI	PB2
#define SPI_SCK		PB1
#define SPI_SS      PB0

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

#ifndef __ASA_STDIO_H__
#define __ASA_STDIO_H__

#if defined (__AVR_ATmega128__)
#  define USART_baud 38400
#elif defined (__AVR_ATmega88__)
#  define USART_baud 38400
#else
#  if !defined(__COMPILING_AVR_LIBC__)
#    warning "device type not defined"
#  endif
#endif

char ASA_STDIO_set(void);

#endif

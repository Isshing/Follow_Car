#ifndef __UART_H__
#define __UART_H__
#include "headfile.h"

extern float Gz;
extern int Data_USCI_A0;
extern int Data_USCI_A1;
extern int Data_USCI_A0_int;
extern int Data_USCI_A1_int;
extern char Data_USCI_A0_char;
extern char Data_USCI_A1_char;

void uart_init(unsigned int uart_pin);
void uart_sent(unsigned int uart_pin, unsigned char text);
void uart_read(unsigned int uart_pin);
void uart_putbuff(unsigned int uart_pin, unsigned char *buff, unsigned long len);

#endif /* UART_H_ */

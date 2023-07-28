#ifndef _WIRELESS_H_
#define _WIRELESS_H_

#include "headfile.h"


#define WIRELESS_UART               11
#define WIRELESS_UART_BAUD          115200
#define WIRELESS_UART_TX
#define WIRELESS_UART_RX
#define RTS_PIN                     BIT6
#define WIRELESS_BUFFER_SIZE        16



void wireless_init(void);
unsigned long wireless_send_buff(unsigned char *buff, unsigned long len);
void wireless_uart_callback(unsigned char data);





#endif /* HARDWARE_WIRELESS_H_ */

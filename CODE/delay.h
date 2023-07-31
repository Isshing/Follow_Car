#ifndef CODE_DELAY_H_
#define CODE_DELAY_H_
#include "headfile.h"

#define F_CPU ((double)15990784)
#define delay_us(x) __delay_cycles((long)((F_CPU * (double)x / 1000000.0)))
#define delay_ms(x) __delay_cycles((long)((F_CPU * (double)x / 1000.0)))

void delay(unsigned int ms);
void set_clock(void);
void clock_init(unsigned char Fre); // �޸���Ƶ����

#endif /* CODE_DELAY_H_ */

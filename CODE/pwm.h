#ifndef __PWM_H__
#define __PWM_H__
#include "headfile.h"

void pwm_init(unsigned int pin, unsigned int freq, unsigned int duty);
void pwm_duty(unsigned int pin, unsigned int duty);

#endif /* PWM_H_ */

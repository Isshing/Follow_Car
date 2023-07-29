
#include "Beep.h"
void Beep_Sing(void)
{
    P3DIR |= BIT5;  // P3.5输设置为输出
    P3OUT |= BIT5;  // P3.5输出高低电平
    delay(50);      // 这样是不是太慢了？？？？
    P3OUT &= ~BIT5; // P3.5输出低电平
}
void Light_On(void)
{
    P4DIR |= BIT1; // P4.1输设置为输出
    P4OUT |= BIT1; // P4.1输出高低电平
}
void Light_Off(void)
{
    P4OUT &= ~BIT1; // P4.1输出低电平
}

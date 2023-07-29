#include "button.h"

void button_init(void)
{
    // 按键一端连接IO口一端连接GDN，按下时IO端口读到的低电平
    P1DIR &= ~BIT1; // 初始化按键1所在IO口P1.1为输入
    P1REN |= BIT1;  // 打开P1.1的使能
    P1OUT |= BIT1;  // 使能P1.1的上拉电阻

    P2DIR &= ~BIT1; // 初始化按键2所在IO口P2.1为输入
    P2REN |= BIT1;  // 打开P2.1的使能
    P2OUT |= BIT1;  // 使能P2.1的上拉电阻
}

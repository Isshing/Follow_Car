#include "button.h"

void button_init(void){
    //����һ������IO��һ������GDN������ʱIO�˿ڶ����ĵ͵�ƽ
    P1DIR &= ~BIT1; //��ʼ������1����IO��P1.1Ϊ����
    P1REN |= BIT1; //��P1.1��ʹ��
    P1OUT |= BIT1; //ʹ��P1.1����������

    P2DIR &= ~BIT1; //��ʼ������2����IO��P2.1Ϊ����
    P2REN |= BIT1; //��P2.1��ʹ��
    P2OUT |= BIT1; //ʹ��P2.1����������
}

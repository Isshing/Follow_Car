
#include "Beep.h"
void Beep_Sing(void){
    P3DIR |= BIT5;//P3.5������Ϊ���
    P3OUT |= BIT5;//P3.5����ߵ͵�ƽ
    delay(50); //�����ǲ���̫���ˣ�������
    P3OUT &= ~BIT5;//P3.5����͵�ƽ
}
void Light_On(void){
    P4DIR |= BIT1;//P4.1������Ϊ���
    P4OUT |= BIT1;//P4.1����ߵ͵�ƽ
}
void Light_Off(void){
    P4OUT &= ~BIT1;//P4.1����͵�ƽ
}



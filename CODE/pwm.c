#include "pwm.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM输出初始化
//  @param      pin         选择的引脚，可选择范围：1_2，1_3，1_4，1_5，2_0，2_4，2_5，对应12，13，14，15，20，24，25
//  @param      freq        输出频率Hz
//  @param      duty        PWM波初始化占空比0~100
//  @return     void
//  Sample usage:           pwm_init("1_2", 100, 0);//P1_2初始化为PWM输出，频率100Hz，初始占空比0%
//  @note                   共用同一个定时器的引脚应保持相同频率
//-------------------------------------------------------------------------------------------------------------------
void pwm_init(unsigned int pin, unsigned int freq, unsigned int duty)
{
    if(pin == 12)
    {
        P1DIR |=BIT2;
        P1SEL |=BIT2;
        TA0CCR0=1000/freq*32.89;
        TA0CCTL1=OUTMOD_7;
        TA0CCR1=duty*TA0CCR0/100;
        TA0CTL =TASSEL_1+MC_1+TACLR;
    }
    if(pin == 13)
    {
        P1DIR |=BIT3;
        P1SEL |=BIT3;
        TA0CCR0=1000/freq*32.89;
        TA0CCTL2=OUTMOD_7;
        TA0CCR2=duty*TA0CCR0/100;
        TA0CTL =TASSEL_1+MC_1+TACLR;
    }
    if(pin == 14)
    {
        P1DIR |=BIT4;
        P1SEL |=BIT4;
        TA0CCR0=1000/freq*32.89;
        TA0CCTL3=OUTMOD_7;
        TA0CCR3=duty*TA0CCR0/100;
        TA0CTL =TASSEL_1+MC_1+TACLR;
    }
    if(pin == 15)
    {
        P1DIR |=BIT5;
        P1SEL |=BIT5;
        TA0CCR0=1000/freq*32.89;
        TA0CCTL4=OUTMOD_7;
        TA0CCR4=duty*TA0CCR0/100;
        TA0CTL =TASSEL_1+MC_1+TACLR;
    }
    if(pin == 20)
    {
        P2DIR |=BIT0;
        P2SEL |=BIT0;
        TA1CCR0=1000/freq*32.89;
        TA1CCTL1=OUTMOD_7;
        TA1CCR1=duty*TA1CCR0/100;
        TA1CTL =TASSEL_1+MC_1+TACLR;
    }
    if(pin == 24)
    {
        P2DIR |=BIT4;
        P2SEL |=BIT4;
        TA2CCTL1=OUTMOD_7;
        TA2CCR0=1000/freq*32.89;
        TA2CCR1=duty*TA2CCR0/100;
        TA2CTL =TASSEL_1+MC_1+TACLR;
    }
    if(pin == 25)
    {
        P2DIR |=BIT5;
        P2SEL |=BIT5;
        TA2CCTL2=OUTMOD_7;
        TA2CCR0=1000/freq*32.89;
        TA2CCR2=duty*TA2CCR0/100;
        TA2CTL =TASSEL_1+MC_1+TACLR;
    }

}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      PWM输出设置
//  @param      pin         选择的引脚，可选择范围：1_2, 1_3, 1_4, 1_5, 2_0, 2_4, 2_5
//  @param      duty        PWM波占空比0~100
//  @return     void
//  Sample usage:           pwm_init("1_2", 50);//P1_2设置PWM输出占空比50%
//-------------------------------------------------------------------------------------------------------------------
void pwm_duty(unsigned int pin, unsigned int duty)
{
    if(pin == 12)
    {
        TA0CCR1=(int)(duty*TA0CCR0/100.0);
    }
    if(pin == 13)
    {
        TA0CCR2=(int)(duty*TA0CCR0/100.0);
    }
    if(pin == 14)
    {
        TA0CCR3=(int)(duty*TA0CCR0/100.0);
    }
    if(pin == 15)
    {
        TA0CCR4=(int)(duty*TA0CCR0/100.0);
    }
    if(pin == 20)
    {
        TA1CCR1=duty*TA1CCR0/100;
    }
    if(pin == 24)
    {
        TA2CCR1=duty*TA2CCR0/100;
    }
    if(pin == 25)
    {
        TA2CCR2=duty*TA2CCR0/100;
    }
}



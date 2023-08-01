#include "timer.h"

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器中断初始化
//  @param      timer_name      定时器名称
//  @param      peri_s         中断执行周期ms
//  @return     void
//  @note       中断周期会影响其他相同定时器的引脚功能
//-------------------------------------------------------------------------------------------------------------------
void timer_init(unsigned int timer_name, long peri_s)
{
    if (timer_name == 10) // A0
    {
        TA0CCTL0 |= CCIE;
        TA0CCR0 |= peri_s * 33;
        TA0CTL = TASSEL_1 + MC_1 + TACLR;
    }
    if (timer_name == 11) // A1
    {
        TA1CCTL0 |= CCIE;
        TA1CCR0 |= peri_s * 33;
        TA1CTL = TASSEL_1 + MC_1 + TACLR;
    }
    if (timer_name == 12) // A2
    {
        TA2CCTL0 |= CCIE;
        TA2CCR0 |= peri_s * 33;
        TA2CTL = TASSEL_1 + MC_1 + TACLR;
    }
    if (timer_name == 20) // B0           具有更高的时钟频率和更多的比较器通道
    {
        TB0CCTL0 |= CCIE;
        TB0CCR0 |= peri_s * 33;
        TB0CTL = TBSSEL_1 + MC_1 + TBCLR;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器中断TA0_0
//  @return     void
//  @note       中断内的内容会影响中断执行速度
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER0_A0(void)
{
    // 中断执行内容---------------------------------------------------------------------------------------------------
    P1OUT ^= BIT0;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器中断TA1_0
//  @return     void
//  @note
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = TIMER1_A0_VECTOR
__interrupt void TIMER1_A0(void)
{
    // 中断执行内容---------------------------------------------------------------------------------------------------
    mpupose();
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器中断TA2_0
//  @return     void
//  @note
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = TIMER2_A0_VECTOR
__interrupt void TIMER2_A0(void)
{
    // 中断执行内容---------------------------------------------------------------------------------------------------
    P1OUT ^= BIT0;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器中断TB0_0
//  @return     void
//  @note
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = TIMER0_B0_VECTOR
__interrupt void TIMER0_B0(void)
{
    // 中断执行内容---------------------------------------------------------------------------------------------------
    Get_Speed();

    if (start_flag)
    {
        EncoderCount();
        Speed_Control();
        //        Turn_Left();
        //        Turn_Right();
        //        Reback();
    }
}

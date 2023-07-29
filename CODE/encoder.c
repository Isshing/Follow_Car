#include "encoder.h"

const int EncoderPerMeter = 1350;
int encoder_R = 0;  // 2_4引脚编码器计数(右轮)
int encoder_L = 0;  // 1_2引脚编码器计数(左轮)
int encoder_RR = 0; // 2_4引脚编码器计数(右轮)
int encoder_LL = 0; // 1_2引脚编码器计数(左轮)
int speed_R = 0;
int speed_L = 0;
int LeftMotor_TotalEncoder = 0;
int RightMotor_TotalEncoder = 0;
float Avg_speed = 0;

void Get_Speed(void)
{

    encoder_RR = encoder_R; // 获取编码器计数

    encoder_LL = encoder_L; // 获取编码器计数

    if (encoder_LL < 0)
        encoder_LL = -encoder_LL;
    if (encoder_RR < 0)
        encoder_RR = -encoder_RR;

    Avg_speed = (encoder_LL + encoder_RR) / 2.0;

    encoder_R = 0; // 定时器清空        左轮
    encoder_L = 0;
    ; // 定时器清空        右轮
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      编码器初始化
//  @return     void
//  @note       引脚P2_4和1_2
//-------------------------------------------------------------------------------------------------------------------
void encoder_init(void)
{
    P2OUT &= ~(BIT4);
    P2SEL |= BIT4;
    TA2CTL = TASSEL__SMCLK + ID__8 + MC_2 + TACLR + TAIE;
    TA2CCTL1 = CM_1 + SCS + CAP + CCIE + CCIS_0;

    P1OUT &= ~(BIT2);
    P1SEL |= BIT2;
    TA0CTL = TASSEL__SMCLK + ID__8 + MC_2 + TACLR + TAIE;
    TA0CCTL1 = CM_1 + SCS + CAP + CCIE + CCIS_0;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      显示编码器读数
//  @return     void
//  @note       speed_right为P2_4读数
//              speed_left为P1_2读数
//-------------------------------------------------------------------------------------------------------------------
// void encoder_read(void)
//{
////    OLED_ShowNum(14,1,speed_left,7,12);
////    OLED_ShowNum(0,1,speed_right,7,12);//显示编码器读值
//
//    if(speed_left < 0){
//        OLED_ShowChar(12,1,'-',12);
//        OLED_ShowNum(18,1,-speed_left,2,12);
//    }else{
//        OLED_ShowChar(12,1,'+',12);
//        OLED_ShowNum(18,1,speed_left,2,12);
//    }
//
//    if(speed_right < 0){
//        OLED_ShowChar(12,2,'-',12);
//        OLED_ShowNum(18,2,-speed_right,2,12);
//    }else{
//        OLED_ShowChar(12,2,'+',12);
//        OLED_ShowNum(18,2,speed_right,2,12);
//    }
//
//    if(Set_Left < 0){
//        OLED_ShowChar(12,3,'-',12);
//        OLED_ShowNum(18,3,-Set_Left,2,12);
//    }else{
//        OLED_ShowChar(12,3,'+',12);
//        OLED_ShowNum(18,3,Set_Left,2,12);
//    }
//
//    if(Set_Right < 0){
//        OLED_ShowChar(12,4,'-',12);
//        OLED_ShowNum(18,4,-Set_Right,2,12);
//    }else{
//        OLED_ShowChar(12,4,'+',12);
//        OLED_ShowNum(18,4,Set_Right,2,12);
//    }
//
//    if(Vd < 0){
//        OLED_ShowChar(12,5,'-',12);
//        OLED_ShowNum(18,5,-Vd,2,12);
//    }else{
//        OLED_ShowChar(12,5,'+',12);
//        OLED_ShowNum(18,5,Vd,2,12);
//    }
//
//
//
////    if(outL>0){
////        OLED_ShowNum(14,2,outL,7,12);
////    }else{
////        OLED_ShowNum(14,3,-outL,7,12);
////    }
//
////    if(speed_right < 0)OLED_ShowNum(14,2,-speed_right,7,12);
////    else OLED_ShowNum(14,2,speed_right,7,12);
////    if(speed_left<0)OLED_ShowNum(14,1,-speed_left,7,12);
////    else OLED_ShowNum(14,1,speed_left,7,12);
//}

// 用编码器计算里程
void EncoderCount(void)
{

    LeftMotor_TotalEncoder += encoder_L;
    RightMotor_TotalEncoder += encoder_R;
}

// 获取测里程(米)
float GetEncoder(void)
{
    return (LeftMotor_TotalEncoder + RightMotor_TotalEncoder) / 2.0 / EncoderPerMeter;
}
void Encoder_clear(void)
{
    LeftMotor_TotalEncoder = 0;
    RightMotor_TotalEncoder = 0;
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器输入中断TA0_1
//  @return     void
//  @note       用于编码器P1_2
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void)
{
    switch (__even_in_range(TA0IV, 2))
    {
    case 0:
        break;
    case 2:
        if (P1IN & BIT2)
        {
            encoder_L++;
        }
        else
        {
            encoder_L--;
        }

        //          OLED_ShowNum(10,6,encoder_count1_2,4,15);
        break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      定时器输入中断TA2_1
//  @return     void
//  @note       用于编码器P2_4
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = TIMER2_A1_VECTOR
__interrupt void TIMER2_A1_ISR(void)
{
    switch (__even_in_range(TA2IV, 2))
    {
    case 0:
        break;
    case 2:
        if (P2IN & BIT4)
        {
            encoder_R++;
        }
        else
        {
            encoder_R--;
        }

        //          OLED_ShowNum(10,5,encoder_count2_4,4,15);
        break;
    }
}

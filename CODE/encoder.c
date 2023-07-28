#include "encoder.h"

const int EncoderPerMeter   = 1350;
int encoder_R = 0;       //2_4���ű���������(����)
int encoder_L = 0;       //1_2���ű���������(����)
int encoder_RR = 0;       //2_4���ű���������(����)
int encoder_LL = 0;       //1_2���ű���������(����)
int speed_R=0;
int speed_L=0;
int LeftMotor_TotalEncoder  = 0;
int RightMotor_TotalEncoder = 0;
float Avg_speed =0;



void Get_Speed(void)
{

    encoder_RR = encoder_R; // ��ȡ����������

    encoder_LL = encoder_L; // ��ȡ����������

    if (encoder_LL < 0)
        encoder_LL = -encoder_LL;
    if (encoder_RR < 0)
        encoder_RR = -encoder_RR;

    Avg_speed = (encoder_LL + encoder_RR) / 2.0;


    encoder_R=0; // ��ʱ�����        ����
    encoder_L=0;; // ��ʱ�����        ����
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��������ʼ��
//  @return     void
//  @note       ����P2_4��1_2
//-------------------------------------------------------------------------------------------------------------------
void encoder_init(void)
{
    P2OUT &= ~(BIT4);
    P2SEL |=  BIT4;
    TA2CTL   = TASSEL__SMCLK + ID__8 + MC_2 + TACLR + TAIE;
    TA2CCTL1 = CM_1 + SCS +CAP + CCIE + CCIS_0;


    P1OUT &= ~(BIT2);
    P1SEL |=  BIT2;
    TA0CTL   = TASSEL__SMCLK + ID__8 + MC_2 + TACLR + TAIE;
    TA0CCTL1 = CM_1 + SCS +CAP + CCIE + CCIS_0;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ʾ����������
//  @return     void
//  @note       speed_rightΪP2_4����
//              speed_leftΪP1_2����
//-------------------------------------------------------------------------------------------------------------------
//void encoder_read(void)
//{
////    OLED_ShowNum(14,1,speed_left,7,12);
////    OLED_ShowNum(0,1,speed_right,7,12);//��ʾ��������ֵ
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


// �ñ������������
void EncoderCount(void)
{

    LeftMotor_TotalEncoder += encoder_L;
    RightMotor_TotalEncoder += encoder_R;
}

// ��ȡ�����(��)
float GetEncoder(void)
{
    return (LeftMotor_TotalEncoder + RightMotor_TotalEncoder) / 2.0 / EncoderPerMeter;
}
void Encoder_clear(void)
{
    LeftMotor_TotalEncoder  = 0;
    RightMotor_TotalEncoder = 0;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ʱ�������ж�TA0_1
//  @return     void
//  @note       ���ڱ�����P1_2
//-------------------------------------------------------------------------------------------------------------------
#pragma vector=TIMER0_A1_VECTOR
__interrupt void TIMER0_A1_ISR(void)
{
    switch(__even_in_range(TA0IV,2))
    {
      case  0:break;
      case  2:
          if(P1IN & BIT2){
              encoder_L++;
          }else{
              encoder_L--;
          }


//          OLED_ShowNum(10,6,encoder_count1_2,4,15);
          break;
    }
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ��ʱ�������ж�TA2_1
//  @return     void
//  @note       ���ڱ�����P2_4
//-------------------------------------------------------------------------------------------------------------------
#pragma vector=TIMER2_A1_VECTOR
__interrupt void TIMER2_A1_ISR(void)
{
    switch(__even_in_range(TA2IV,2))
    {
      case  0:break;
      case  2:
          if(P2IN & BIT4){
              encoder_R++;
          }else{
              encoder_R--;
          }



//          OLED_ShowNum(10,5,encoder_count2_4,4,15);
          break;
    }
}



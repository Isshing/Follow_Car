#include "delay.h"

void delay(unsigned int ms)
{
    int i,j;
    for(j=0;j<ms;j++)
    {
        for(i=0;i<207;i++);
    }
}

void set_clock(void)
{
  P1SEL &= ~BIT1;
  P1DIR |= BIT1;
  P1SEL |= BIT0; //ACLK
  P1DIR |= BIT0;
  P2SEL |= BIT2; //SMCLK
  P2DIR |= BIT2;
  P7SEL |= BIT7; //MCLK
  P7DIR |= BIT7;
  P5SEL |= BIT4|BIT5;

  UCSCTL6 |= XCAP_3;//����  SMCLKʱ��   ѡ�����
  UCSCTL6 &= ~XT1OFF;//�� XT1������ XT1LFOFFG ���ܱ���
//  PMMCTL0_H = 0xA5;
//  PMMCTL0 |=PMMPW+ PMMCOREV_3;

      PMMCTL0_H = 0xA5;                                         //��PMM��Դ����
       SVSMLCTL |= SVSMLRRL_1 + SVMLE;                            //����SVML��ѹ
       PMMCTL0 =  PMMPW + PMMCOREV_2;                             //�����ں˵�ѹ
       while((PMMIFG & SVSMLDLYIFG ) == 0);                       //�ȴ��������
       PMMIFG &= ~(SVMLVLRIFG + SVMLIFG + SVSMLDLYIFG);
       if((PMMIFG & SVMLIFG) == 1)                                //�ж��ں˵�ѹ�Ƿ�������VSVML
             while((PMMIFG & SVMLVLRIFG) == 0);                   //���û�еȴ�
  SVSMLCTL &= ~SVMLE;                                        //�ص�SVMLģ��
  PMMCTL0_H = 0X00;                                          //��������

  __bis_SR_register(SCG0);//���﷨Ϊ�̶���ʽ����Ϊ�������ڵı�����λ��SCG0��ϵͳ����ģʽ�йأ���ʱ MCLK ��ͣ����
  UCSCTL0 = 0; //�����㣬FLL ����ʱ���üĴ���ϵͳ���Զ����ã����ù�
  UCSCTL1 = DCORSEL_6;//�Զ�����
  UCSCTL2 = FLLD_1 | 380;//FLLD=1,FLLN=380,��Ƶ��Ϊ2*��380+1��*32.768=24.969MHZ
  __bic_SR_register(SCG0);
  __delay_cycles(782000);//ϵͳ�Դ��ľ�ȷ��ʱ����λ us
  while(SFRIFG1 & OFIFG)
  {
    UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);
    SFRIFG1 &= ~OFIFG;
  }
  UCSCTL4 = UCSCTL4&(~(SELS_7|SELM_7))|SELS_3|SELM_3;
  ///MCLK=24M   SMCLK=24MH   ACLK   32.768K
}



void clock_init(unsigned char Fre)//�޸���Ƶ����
{
    P5SEL |= BIT2|BIT3|BIT4|BIT5;//�����ⲿ����ʱ��

    UCSCTL6 |= XCAP_3|XT1OFF;          // XT1 ��� ����
    UCSCTL6 |= XT2DRIVE_0 | XT2OFF;     // XT2 ��� ����
//�������������ĵ�ѹ���ֵĴ���
    PMMCTL0_H = 0xA5;                                         //��PMM��Դ����
    SVSMLCTL |= SVSMLRRL_1 + SVMLE;                            //����SVML��ѹ
    PMMCTL0 =  PMMPW + PMMCOREV_3;                             //�����ں˵�ѹ
    while((PMMIFG & SVSMLDLYIFG ) == 0);                       //�ȴ��������
    PMMIFG &= ~(SVMLVLRIFG + SVMLIFG + SVSMLDLYIFG);
    if((PMMIFG & SVMLIFG) == 1)                                //�ж��ں˵�ѹ�Ƿ�������VSVML
         while((PMMIFG & SVMLVLRIFG) == 0);                    //���û�еȴ�
    SVSMLCTL &= ~SVMLE;                                        //�ص�SVMLģ��
    PMMCTL0_H = 0X00;

    __bis_SR_register(SCG0);                 //���﷨Ϊ�̶���ʽ����Ϊ�������ڵı�����λ��SCG0��ϵͳ����ģʽ�йأ���ʱ MCLK ��ͣ����
    UCSCTL0 = 0;                             //�����㣬FLL ����ʱ���üĴ���ϵͳ���Զ����ã����ù�
    UCSCTL6 = (UCSCTL6&(~(XT2OFF|XT1OFF))|XCAP_3|XT2DRIVE_0);
    UCSCTL3 = (5<<4)|(2<<0);                 // ѡ�� XTAL2 ��ʱ���ź���Ϊ�ο��ź� ���ҷ�Ƶ��1MHz
    UCSCTL4|= SELA_5;
    if(Fre < 5)
        UCSCTL1 = DCORSEL_2;
    else if(Fre<15)
        UCSCTL1 = DCORSEL_4;
    else
        UCSCTL1 = DCORSEL_7;
   UCSCTL2 = (Fre-1);
    __bic_SR_register(SCG0);
    __delay_cycles(782000);
    while (SFRIFG1 & OFIFG) {                               // Check OFIFG fault flag
      UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);           // Clear OSC flaut Flags
      SFRIFG1 &= ~OFIFG;                                    // Clear OFIFG fault flag
    }
    UCSCTL4 = UCSCTL4&(~(SELS_7|SELM_7))|SELS_3|SELM_3;
}





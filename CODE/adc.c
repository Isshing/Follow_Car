#include "adc.h"

void configure_adc(void)
{
    ADC12CTL0 = ADC12ON + ADC12SHT02; // + ADC12MSC;
    ADC12CTL1 = ADC12SHP;             // + ADC12CONSEQ_1;
    // ADC12MCTL0 = ADC12INCH_0;
    // ADC12MCTL1 = ADC12INCH_1 + ADC12EOS;
    ADC12IE = ADC12IE0; // 1;
    ADC12CTL0 |= ADC12ENC;
    P6SEL |= BIT0; // P6.0 ADC  //选引脚
}

void start_sampling(void)
{
    ADC12CTL0 |= ADC12SC;
}


#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=ADC12_VECTOR
__interrupt
#elif defined(__GNUC__)
__attribute__((interrupt(ADC12_VECTOR)))
#endif
__interrupt void ADC12_ISR(void)  //adc中断，这里写具体操作
{
    // static uint8_t cnt = 0;
    int data_plus, data_minus;
    switch (__even_in_range(ADC12IV, 34))
    {
    case 0x06:  //中断向量6


        data_plus = ADC12MEM0;
        data_minus = ADC12MEM1;

        if((data_plus - data_minus) > 372272)
        {
//            P1OUT |= 0x01;
        }
        else
        {
//            P1OUT &= ~0x01;
        }

        break;
    }
}

// 用法
// int main(void) {
//     stop_watchdog();
//

//    configure_adc();
//
//    while(1)
//    {
//        start_sampling();
//        __bis_SR_register(LPM0_bits + GIE);
//    }
//}







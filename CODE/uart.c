#include "uart.h"

int Data_USCI_A0;       // USCI_A0接收内容原始
int Data_USCI_A1;       // USCI_A1接收内容原始
int Data_USCI_A0_int;   // USCI_A0接收内容int形式
int Data_USCI_A1_int;   // USCI_A1接收内容int形式
char Data_USCI_A0_char; // USCI_A0接收内容char形式
char Data_USCI_A1_char; // USCI_A1接收内容char形式

//-------------------------------------------------------------------------------------------------------------------
//  @brief      uart串口初始化
//  @param      uart_pin        USCI_A0或USCI_A1
//  @return     void
//  @note       P3.3,4 为A0
//              P4.4,5 为A1
//-------------------------------------------------------------------------------------------------------------------
void uart_init(unsigned int uart_pin)
{
    if (uart_pin == 10) // USCI_A0
    {
        P3SEL |= BIT3 + BIT4;          // P3.3,4 = USCI_A0 TXD/RXD
        UCA0CTL1 |= UCSWRST;           // **Put state machine in reset**
        UCA0CTL1 |= UCSSEL_2;          // SMCLK
        UCA0BR0 = 9;                   // 1MHz 115200 (see User's Guide)
        UCA0BR1 = 0;                   // 1MHz 115200
        UCA0MCTL |= UCBRS_1 + UCBRF_0; // Modulation UCBRSx=1, UCBRFx=0
        UCA0CTL1 &= ~UCSWRST;          // **Initialize USCI state machine**
        UCA0IE |= UCRXIE;              // Enable USCI_A0 RX interrupt
    }
    if (uart_pin == 11) // USCI_A1
    {
        P4SEL |= BIT4 + BIT5;          // P4.4,5 = USCI_A1 TXD/RXD
        UCA1CTL1 |= UCSWRST;           // **Put state machine in reset**
        UCA1CTL1 |= UCSSEL_2;          // SMCLK
        UCA1BR0 = 9;                   // 1MHz 115200 (see User's Guide)
        UCA1BR1 = 0;                   // 1MHz 115200
        UCA1MCTL |= UCBRS_1 + UCBRF_0; // Modulation UCBRSx=1, UCBRFx=0
        UCA1CTL1 &= ~UCSWRST;          // **Initialize USCI state machine**
        UCA1IE |= UCRXIE;              // Enable USCI_A1 RX interrupt
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      uart串口接收
//  @param      uart_pin        USCI_A0USCI_A1
//  @return     void
//  @note       P3.3,4 为A0
//              P4.4,5 为A1
//
//              读取到为int类型：Data_USCI_Ax_int
//              读取到为char类型：Data_USCI_Ax_char
//-------------------------------------------------------------------------------------------------------------------
void uart_read(unsigned int uart_pin)
{
    if (uart_pin == 10) // USCI_A0
    {
        Data_USCI_A0 = UCA0RXBUF;
        Data_USCI_A0_int = Data_USCI_A0 - '0';
        Data_USCI_A0_char = Data_USCI_A0;
        //        OLED_ShowNum(15,2,Data_USCI_A0_int,3,10);
        //        OLED_ShowChar(15,3,Data_USCI_A0_char,10);
        Data_USCI_A0 = UCA0RXBUF;
    }
    if (uart_pin == 11) // USCI_A1
    {
        Data_USCI_A1 = UCA1RXBUF;
        Data_USCI_A1_int = Data_USCI_A1 - '0';
        Data_USCI_A1_char = Data_USCI_A1;
        //        OLED_ShowNum(15,2,Data_USCI_A1_int,3,10);
        //        OLED_ShowChar(15,3,Data_USCI_A1_char,10);
        Data_USCI_A1 = UCA1RXBUF;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      uart串口发送
//  @param      uart_pin        USCI_A0或USCI_A1
//  @param      text            发送内容
//  @return     void
//  @note       P3.3,4 为A0
//              P4.4,5 为A1
//-------------------------------------------------------------------------------------------------------------------
void uart_sent(unsigned int uart_pin, unsigned char text)
{
    if (uart_pin == 10) // USCI_A0
    {
        UCA0TXBUF = text;
        while (!(UCA0IFG & UCTXIFG))
            ;
    }
    if (uart_pin == 11) // USCI_A1
    {
        UCA1TXBUF = text;
        while (!(UCA1IFG & UCTXIFG))
            ;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口中断A0
//  @return     void
//  @note       P3.3,4 = USCI_A0 TXD/RXD
//              读取到Data_USCI_A0
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
{
    switch (__even_in_range(UCA0IV, 4))
    {
    case 0:
        break; // Vector 0 - no interrupt
    case 2:    // Vector 2 - RXIFG
        Data_USCI_A0 = UCA0RXBUF;
        //            uart_read(10);
        //            gyroscope_read_A0();
        //            wireless_uart_callback(UCA0RXBUF);

        //            Laser_Uart_Callback(UCA0RXBUF);

        break;

    case 4:
        break; // Vector 4 - TXIFG
    default:
        break;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      串口中断A0
//  @return     void
//  @note       P4.4,5 = USCI_A0 TXD/RXD
//              读取到Data_USCI_A1
//-------------------------------------------------------------------------------------------------------------------
#pragma vector = USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{

    switch (__even_in_range(UCA1IV, 4))
    {
    case 0:
        break; // Vector 0 - no interrupt
    case 2:    // Vector 2 - RXIFG
        while (!(UCA1IFG & UCTXIFG))
            ; // USCI_A1 TX buffer ready?
              //            uart_read(11);
              //            Data_USCI_A1=UCA1RXBUF;
              //            Laser_Uart_Callback(UCA1RXBUF);
              //            gyroscope_read_A1();
        break;
    case 4:
        break; // Vector 4 - TXIFG
    default:
        break;
    }
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      uart串口发送数组
//  @param      uart_pin        USCI_A0或USCI_A1
//  @param      *buff           要发送的数组地址
//  @param      len             发送长度
//  @return     void
//  @note       P3.3,4 为A0
//              P4.4,5 为A1
//-------------------------------------------------------------------------------------------------------------------
void uart_putbuff(unsigned int uart_pin, unsigned char *buff, unsigned long len)
{
    while (len)
    {
        uart_sent(uart_pin, *buff);
        len--;
        buff++;
    }
}

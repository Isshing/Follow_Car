#include "WIRELESS.h"

unsigned long wireless_rx_index = 0;
unsigned char wireless_rx_buffer;
unsigned char wireless_receive_buffer[WIRELESS_BUFFER_SIZE];
//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����ת����ģ���ʼ��
//  @param      NULL
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note
//-------------------------------------------------------------------------------------------------------------------
void wireless_init(void)
{
    uart_init(WIRELESS_UART);

    P2DIR &= ~(RTS_PIN);
    P2OUT &= ~(RTS_PIN);
    P2REN |= (RTS_PIN);
}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����ת����ģ�� ���ͺ���
//  @param      buff        ��Ҫ���͵����ݵ�ַ
//  @param      len         ���ͳ���
//  @return     uint32      ʣ��δ���͵��ֽ���
//  @since      v1.0
//  Sample usage:
//  @note
//-------------------------------------------------------------------------------------------------------------------
unsigned long wireless_send_buff(unsigned char *buff, unsigned long len)
{
    while(len>30)
    {
        while(P2IN & RTS_PIN);  //���RTSΪ�͵�ƽ���������������


        uart_putbuff(WIRELESS_UART, buff, 30);

        buff += 30; //��ַƫ��
        len -= 30;//����
    }


    while(P2IN & RTS_PIN);  //���RTSΪ�͵�ƽ���������������

    uart_putbuff(WIRELESS_UART, buff, len);

    return 0;

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ����ת����ģ�� �����жϺ���
//  @param      void
//  @return     void
//  @since      v1.0
//  Sample usage:
//  @note
//-------------------------------------------------------------------------------------------------------------------
void wireless_uart_callback(unsigned char data)
{
//    wireless_send_buff(&data, 1);
//    if (data == 9)
//    {
//        NormalSpeed = 20;
//    }
}







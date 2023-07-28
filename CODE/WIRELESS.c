#include "WIRELESS.h"

unsigned long wireless_rx_index = 0;
unsigned char wireless_rx_buffer;
unsigned char wireless_receive_buffer[WIRELESS_BUFFER_SIZE];
//-------------------------------------------------------------------------------------------------------------------
//  @brief      无线转串口模块初始化
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
//  @brief      无线转串口模块 发送函数
//  @param      buff        需要发送的数据地址
//  @param      len         发送长度
//  @return     uint32      剩余未发送的字节数
//  @since      v1.0
//  Sample usage:
//  @note
//-------------------------------------------------------------------------------------------------------------------
unsigned long wireless_send_buff(unsigned char *buff, unsigned long len)
{
    while(len>30)
    {
        while(P2IN & RTS_PIN);  //如果RTS为低电平，则继续发送数据


        uart_putbuff(WIRELESS_UART, buff, 30);

        buff += 30; //地址偏移
        len -= 30;//数量
    }


    while(P2IN & RTS_PIN);  //如果RTS为低电平，则继续发送数据

    uart_putbuff(WIRELESS_UART, buff, len);

    return 0;

}

//-------------------------------------------------------------------------------------------------------------------
//  @brief      无线转串口模块 串口中断函数
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







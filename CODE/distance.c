//
// #include "distance.h"
// int TOF_Rx_Count;
//
// int DataL;
// int DataH;
//
// unsigned char tx_buff[20];
////uint8   rx_buff[50];
//
////单片机向激光模块发送命令
// void my_uart_send(const unsigned char *str_send, unsigned char len)
//{
//     int i;
//     for(i=0;i<len;i++)  uart_sent(LASER_UART,str_send[i]);
// }
//
////单片机从激光模块接收数据
////void my_uart_receive(uint8 *data)
////{
////    int i;
////    int count=0;
////    IfxAsclin_Asc*  uart_handle;
////    uart_handle = uart_get_handle(uartn);
////
////    while(count == 0)    //轮询 等待有数据发送过来
////    {
////        count = IfxAsclin_Asc_getReadCount(uart_handle);
////    }
////
////    delay(1);    //加个延时 让接收完成 不然会没接收全
////    count = IfxAsclin_Asc_getReadCount(uart_handle);
////
////    for(i=0;i<count;i++)
////    {
////        data[i] = IfxAsclin_Asc_blockingRead(uart_handle);
////    }
////}
//
//
// void distance(void)
//{
//    //发送读测量数据指令
//    //读测量数据指令 51 0B 00 01 00 05 02 00 64
//    tx_buff[0] = 0x51;  /*帧头*/
//    tx_buff[1] = 0x0B;  /*MS53L1M传感器*/
//    tx_buff[2] = 0x00;  /*高位地址*/
//    tx_buff[3] = 0x01;  /*低位地址*/
//    tx_buff[4] = 0x00;  /*读数据*/
//    tx_buff[5] = 0x05;  /*功能码-测距结果*/
//    tx_buff[6] = 0x02;  /*数据长度*/
//    tx_buff[7] = 0x00;  /*CRC1*/    //这块要继续完善 写个CRC函数来计算
//    tx_buff[8] = 0x64;  /*CRC2*/
//
//    my_uart_send(tx_buff, 9);
//    delay(1);  //延时1ms, 等待发送完成
//
//}
//
// void Laser_Uart_Callback(unsigned char data)
//{
//    TOF_Rx_Count++;
//
//    if(data == 0x55) TOF_Rx_Count = 0;
//
//    if(TOF_Rx_Count == 8)
//    {
//        DataH = data;
//    }
//    else if(TOF_Rx_Count == 9)
//    {
//        DataL = data;
//        Dist = DataH*16*16+ DataL;
////        uart_sent(11, (unsigned char)Dist );
//    }
//}
//
//
//
//
//
//
//

//
//#include "distance.h"
//int TOF_Rx_Count;
//
//int DataL;
//int DataH;
//
//unsigned char tx_buff[20];
////uint8   rx_buff[50];
//
////��Ƭ���򼤹�ģ�鷢������
//void my_uart_send(const unsigned char *str_send, unsigned char len)
//{
//    int i;
//    for(i=0;i<len;i++)  uart_sent(LASER_UART,str_send[i]);
//}
//
////��Ƭ���Ӽ���ģ���������
////void my_uart_receive(uint8 *data)
////{
////    int i;
////    int count=0;
////    IfxAsclin_Asc*  uart_handle;
////    uart_handle = uart_get_handle(uartn);
////
////    while(count == 0)    //��ѯ �ȴ������ݷ��͹���
////    {
////        count = IfxAsclin_Asc_getReadCount(uart_handle);
////    }
////
////    delay(1);    //�Ӹ���ʱ �ý������ ��Ȼ��û����ȫ
////    count = IfxAsclin_Asc_getReadCount(uart_handle);
////
////    for(i=0;i<count;i++)
////    {
////        data[i] = IfxAsclin_Asc_blockingRead(uart_handle);
////    }
////}
//
//
//void distance(void)
//{
//    //���Ͷ���������ָ��
//    //����������ָ�� 51 0B 00 01 00 05 02 00 64
//    tx_buff[0] = 0x51;  /*֡ͷ*/
//    tx_buff[1] = 0x0B;  /*MS53L1M������*/
//    tx_buff[2] = 0x00;  /*��λ��ַ*/
//    tx_buff[3] = 0x01;  /*��λ��ַ*/
//    tx_buff[4] = 0x00;  /*������*/
//    tx_buff[5] = 0x05;  /*������-�����*/
//    tx_buff[6] = 0x02;  /*���ݳ���*/
//    tx_buff[7] = 0x00;  /*CRC1*/    //���Ҫ�������� д��CRC����������
//    tx_buff[8] = 0x64;  /*CRC2*/
//
//    my_uart_send(tx_buff, 9);
//    delay(1);  //��ʱ1ms, �ȴ��������
//
//}
//
//void Laser_Uart_Callback(unsigned char data)
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

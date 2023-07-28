//#include "TOF.h"
//
//unsigned char   tx_buff[20];
//unsigned char   rx_buff[20];
//unsigned char TOF_Rx_Count = 0;
//unsigned char DataH;
//unsigned char DataL;
//unsigned int Dist;
//
//int DistError = 0;
//int DistErrorIntegral = 0;
//
//float Dist_Kp = 0.055;
//float Dist_Ki = 0.001;
//float Dist_Kd = 0;
//int DistControlOut = 0;
//
//unsigned char DistControlFlag = 0;
//int NormalSpeed = 19;
//void TOFInit()
//{
//    uart_init(TOF_UART);
//}
//void MeasureStart()
//{
//    //锟斤拷锟酵讹拷锟斤拷锟斤拷锟斤拷锟斤拷指锟斤拷
//    //锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷指锟斤拷 51 0B 00 01 00 05 02 00 64
//    tx_buff[0] = 0x51;  /*帧头*/
//    tx_buff[1] = 0x0B;  /*MS53L1M锟斤拷锟斤拷锟斤拷*/
//    tx_buff[2] = 0x00;  /*锟斤拷位锟斤拷址*/
//    tx_buff[3] = 0x01;  /*锟斤拷位锟斤拷址*/
//    tx_buff[4] = 0x00;  /*锟斤拷锟斤拷锟斤拷*/
//    tx_buff[5] = 0x05;  /*锟斤拷锟斤拷锟斤拷-锟斤拷锟斤拷锟�*/
//    tx_buff[6] = 0x02;  /*锟斤拷锟捷筹拷锟斤拷*/
//    tx_buff[7] = 0x00;  /*CRC1*/    //锟斤拷锟揭拷锟斤拷锟斤拷锟斤拷锟� 写锟斤拷CRC锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷
//    tx_buff[8] = 0x64;  /*CRC2*/
//
//    uart_putbuff(TOF_UART, tx_buff, 9);
//
//    _delay_cycles(500);      //锟斤拷时500us
//}
//
//
//
//void Measure_callback(unsigned char data)
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
//
//
//        //涔嬪悗杩欓噷鏀规垚鍙橀噺
////        MOTORCTL.target_val = NormalSpeed + DistanceControl(Dist, 400);
//    }
//}
//
//int DistanceControl(unsigned int dist, unsigned int TargetDist)
//{
//	    if(DistControlFlag)
//	    {
//	        if(problem == 1)
//	        {
//	            int UFF[7]={-4,-2,-1,0,1,2,2};
//	            int EFF[8]={-370,-150,-60,-10,80,110,110,110};
//	            int Gap = Dist - TargetDist;
//
//	                if(Gap<EFF[0])
//	                {
//
//	                    DistControlOut = UFF[0];;
//	                }
//	                else if(Gap>EFF[0] && Gap<EFF[1])   DistControlOut = UFF[0];
//	                else if(Gap>EFF[1] && Gap<EFF[2])   DistControlOut = UFF[1];
//	                else if(Gap>EFF[2] && Gap<EFF[3])   DistControlOut = UFF[2];
//	                else if(Gap>EFF[3] && Gap<EFF[4])   DistControlOut = UFF[3];
//	                else if(Gap>EFF[4] && Gap<EFF[5])   DistControlOut = UFF[4];
//	                else if(Gap>EFF[5] && Gap<EFF[6])   DistControlOut = UFF[5];
//	                else if(Gap>EFF[6] && Gap<EFF[7])   DistControlOut =  UFF[6];
//	                else if(Gap>EFF[7])
//	                {
//
//	                    DistControlOut = 0;
//	                }
//
//
//	    //	        LastDistControlOut = DistControlOut;
//
//
//	                return DistControlOut;
//	        }
//	        else if(problem == 2)
//	        {
//	            int UFF[7]={-7,-4,-1,0,1,4,6};
//	            int EFF[8]={-370,-150,-60,-10,100,200,300,500};
//	            int Gap = Dist - TargetDist;
//
//	                if(Gap<EFF[0])
//	                {
//
//	                    DistControlOut = UFF[0];
//	                }
//	                else if(Gap>EFF[0] && Gap<EFF[1])   DistControlOut = UFF[0];
//	                else if(Gap>EFF[1] && Gap<EFF[2])   DistControlOut = UFF[1];
//	                else if(Gap>EFF[2] && Gap<EFF[3])   DistControlOut = UFF[2];
//	                else if(Gap>EFF[3] && Gap<EFF[4])   DistControlOut = UFF[3];
//	                else if(Gap>EFF[4] && Gap<EFF[5])   DistControlOut = UFF[4];
//	                else if(Gap>EFF[5] && Gap<EFF[6])   DistControlOut = UFF[5];
//	                else if(Gap>EFF[6] && Gap<EFF[7])   DistControlOut =  UFF[6];
//	                else if(Gap>EFF[7])
//	                {
//
//	                    DistControlOut = 0;
//	                }
//
//
//	    //          LastDistControlOut = DistControlOut;
//
//
//	                return DistControlOut;
//	        }
//	        else if(problem == 3)
//	        {
//	            int UFF[7]={-7,-4,-1,0,2,5,7};
//	            int EFF[8]={-370,-150,-60,-10,100,200,300,500};
//	            int Gap = Dist - TargetDist;
//
//	                if(Gap<EFF[0])
//	                {
//
//	                    DistControlOut = UFF[0];
//	                }
//	                else if(Gap>EFF[0] && Gap<EFF[1])   DistControlOut = UFF[0];
//	                else if(Gap>EFF[1] && Gap<EFF[2])   DistControlOut = UFF[1];
//	                else if(Gap>EFF[2] && Gap<EFF[3])   DistControlOut = UFF[2];
//	                else if(Gap>EFF[3] && Gap<EFF[4])   DistControlOut = UFF[3];
//	                else if(Gap>EFF[4] && Gap<EFF[5])   DistControlOut = UFF[4];
//	                else if(Gap>EFF[5] && Gap<EFF[6])   DistControlOut = UFF[5];
//	                else if(Gap>EFF[6] && Gap<EFF[7])   DistControlOut =  UFF[6];
//	                else if(Gap>EFF[7])
//	                {
//
//	                    DistControlOut = 0;
//	                }
//
//
//	    //          LastDistControlOut = DistControlOut;
//
//
//	                return DistControlOut;
//	        }
//	    }
//	    else
//	    {
//	        return 0;
//	    }
//
//	    return 0;
//}

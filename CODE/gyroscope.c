//#include <CODE/gyroscope.h>
//
//#define int16_t  short
//
//unsigned int Data_Gyroscope;
//int count_Gyroscope=0;
//int mode_Gyroscope;
//int n_Gyroscope,t_Gyroscope;
//int RollL,RollH,PitchL,PitchH,YawL,YawH;
//int angle_Gyroscope_value[4];
//unsigned int angle_Gyroscope[8];
//float Roll,Pitch,Yaw;
////unsigned int acc_Gyroscope[14];
////int AxL,GxL,AxH,GxH,AyL,GyL,AyH,GyH,AzL,GzL,AzH,GzH;
////int16_t Ax,Ay,Az,Gx,Gy,Gz;
////float ACCx,ACCy,ACCz,GYROx,GYROy,GYROz;
////int acc_Gyroscope_value[4];
////int gyro_value[4];
//
////-------------------------------------------------------------------------------------------------------------------
////  @brief      ����������
////  @return     void
////  Sample usage:           gyroscope();
////-------------------------------------------------------------------------------------------------------------------
//void gyroscope_init(void)
//{
//    OLED_ShowString(15,1," Angle  Acc  Gyro",15);
//    OLED_ShowString(3,2,"x:",15);
//    OLED_ShowString(3,3,"y:",15);
//    OLED_ShowString(3,4,"z:",15);
//    uart_init(10);
//
//    __bis_SR_register(GIE); // Enter LPM0, interrupts enabled
//    __no_operation(); // For debugger
//
//
//}
//
//
////-------------------------------------------------------------------------------------------------------------------
////  @brief      ��ȡ������
////  @return     void
////  Sample usage:           read_gyroscope();
////  @note                   �ڴ����ж��ж�ȡ��̬��
////-------------------------------------------------------------------------------------------------------------------
//void gyroscope_read(void)
//{
//    count_Gyroscope++;
//        if (Data_USCI_A0==0x55)
//        {
//            count_Gyroscope=0;
//            mode_Gyroscope=0;
//        }
//
//        if ((mode_Gyroscope==0)&&(count_Gyroscope==1))
//        {
//            if (Data_USCI_A0==0x01){mode_Gyroscope=1;}
//            if (Data_USCI_A0==0x03){mode_Gyroscope=2;}
//        }
//
//        if ((mode_Gyroscope==1)&&(count_Gyroscope>=3))
//        {
//            angle_Gyroscope[count_Gyroscope-2]=Data_USCI_A0;
//            if (count_Gyroscope==8)
//            {
//                mode_Gyroscope=3;
//                count_Gyroscope=0;
//                RollL=angle_Gyroscope[1];
//                RollH=angle_Gyroscope[2];
//                PitchL=angle_Gyroscope[3];
//                PitchH=angle_Gyroscope[4];
//                YawL=angle_Gyroscope[5];
//                YawH=angle_Gyroscope[6];
//                Roll= (float)((int16_t)(RollH<<8)|(RollL))/32768*180;
//                Pitch= (float)((int16_t)(PitchH<<8)|(PitchL))/32768*180;
//                Yaw= (float)((int16_t)(YawH<<8)|(YawL))/32768*180;
//                angle_Gyroscope_value[1] = (int)Roll;
//                angle_Gyroscope_value[2] = (int)Pitch;
//                angle_Gyroscope_value[3] = (int)Yaw;
//                for (t_Gyroscope=1;t_Gyroscope<=3;t_Gyroscope++)
//                {
//                    if(angle_Gyroscope_value[t_Gyroscope]<=-1)
//                    {
//                        OLED_ShowChar(15,t_Gyroscope+1,'-',15);
//                    }
//                    else
//                    {
//                        OLED_ShowChar(15,t_Gyroscope+1,' ',15);
//                    }
//                    OLED_ShowNum(20,t_Gyroscope+1,abs(angle_Gyroscope_value[t_Gyroscope]),3,15);
//                }
//            }
//        }
//
////          if ((mode_Gyroscope==2)&&(count2_Gyroscope>=3))
////          {
////              acc_Gyroscope[count2_Gyroscope-2]=Data_USCI_A0;
////              if (count2_Gyroscope==14)
////              {
////                  mode_Gyroscope=3;
////                  count2_Gyroscope=0;
////                  AxL=acc_Gyroscope[1];AxH=acc_Gyroscope[2];
////                  AyL=acc_Gyroscope[3];AyH=acc_Gyroscope[4];
////                  AzL=acc_Gyroscope[5];AzH=acc_Gyroscope[6];
////                  GxL=acc_Gyroscope[7];GxH=acc_Gyroscope[8];
////                  GyL=acc_Gyroscope[9];GyH=acc_Gyroscope[10];
////                  GzL=acc_Gyroscope[11];GzH=acc_Gyroscope[12];
////                  Ax=(int16_t)(AxH<<8)|AxL;
////                  Ay=(int16_t)(AyH<<8)|AyL;
////                  Az=(int16_t)(AzH<<8)|AzL;
////                  Gx=(int16_t)(GxH<<8)|GxL;
////                  Gy=(int16_t)(GyH<<8)|GyL;
////                  Gz=(int16_t)(GzH<<8)|GzL;
////                  ACCx=(float)Ax/32768*4*98;
////                  ACCy=(float)Ay/32768*4*98;
////                  ACCz=(float)Az/32768*4*98;
////                  GYROx=(float)Gx/32768*200;
////                  GYROy=(float)Gy/32768*200;
////                  GYROz=(float)Gz/32768*200;
////                  acc_Gyroscope_value[1]=(int)ACCx;
////                  acc_Gyroscope_value[2]=(int)ACCy;
////                  acc_Gyroscope_value[3]=(int)ACCz;
////                  gyro_value[1]=(int)GYROx;
////                  gyro_value[2]=(int)GYROy;
////                  gyro_value[3]=(int)GYROz;
////                  gyro_value[3]=0;//This hardware dosen't work at z-axis
////                  for (t_Gyroscope=1;t_Gyroscope<=3;t_Gyroscope++)
////                  {
////                      if(acc_Gyroscope_value[t_Gyroscope]<=-1)
////                      {
////                          OLED_ShowChar(55,t_Gyroscope+1,'-',15);
////                      }
////                      else
////                      {
////                          OLED_ShowChar(55,t_Gyroscope+1,' ',15);
////                      }
////                      if(gyro_value[t_Gyroscope]<=-1)
////                      {
////                          OLED_ShowChar(95,t_Gyroscope+1,'-',15);
////                      }
////                      else
////                      {
////                          OLED_ShowChar(95,t_Gyroscope+1,' ',15);
////                      }
////                      OLED_ShowNum(60,t_Gyroscope+1,abs(acc_Gyroscope_value[t_Gyroscope]),3,15);
////                      OLED_ShowNum(100,t_Gyroscope+1,abs(gyro_value[t_Gyroscope]),3,15);
////                    }
////
////                }
////            }
//}
//

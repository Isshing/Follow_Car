#include "headfile.h"

float32 nuu = 0;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; // stop watchdog timer

	init();

	while (1)
	{
		//	    OLED_Clear();
		key_switch();

		light_get();

		//        OLED_ShowNum(14,1,LINELIGHT.c_0,10,12);
		//        OLED_ShowNum(14,2,LINELIGHT.c_1,10,12);
		//        OLED_ShowNum(14,3,LINELIGHT.c_2,10,12);
		//        OLED_ShowNum(14,4,LINELIGHT.c_3,10,12);
		//        OLED_ShowNum(14,5,LINELIGHT.c_4,10,12);
		//        OLED_ShowNum(14,4,LINELIGHT.c_5,10,12);
		//        OLED_ShowNum(14,5,LINELIGHT.c_6,10,12);

		Light_Error(&LINELIGHT, &LINECTL);

		//	    if (LINECTL.line_err>=0)
		//	    {
		//	        OLED_ShowString(11,1,"+",2);
		//	        OLED_ShowNum(14,1,(int)LINECTL.line_err,10,12);
		//
		//	    }
		//	    else
		//	    {
		//            OLED_ShowString(11,1,"-",2);
		//            OLED_ShowNum(14,1,(int)Fabs(LINECTL.line_err),10,12);
		//
		//	    }
		//
		//        if (dxd>=0)
		//        {
		//
		//            OLED_ShowString(11,2,"+",2);
		//            OLED_ShowNum(14,2,(int)dxd,10,12);
		//        }
		//        else
		//        {
		//
		//            OLED_ShowString(11,2,"-",2);
		//            OLED_ShowNum(14,2,(int)Fabs(dxd),10,12);
		//        }

		//	    OLED_ShowNum(14,2,(int)Vd,10,12);

		//		OLED_ShowNum(14,1,encoder_LL,10,12);
		//		OLED_ShowNum(14,2,encoder_RR,10,12);

//		OLED_ShowNum(14, 3, Yaw_IIC, 10, 12);
//		OLED_ShowNum(14, 4, Roll_IIC, 10, 12);
//		OLED_ShowNum(14, 5, Pitch_IIC, 10, 12);

//        OLED_ShowNum(14, 3, (int)gyrox, 10, 12);
//        OLED_ShowNum(14, 4, (int)gyroy, 10, 12);
//        OLED_ShowNum(14, 5, (int)gyroz, 10, 12);
//		Data_show();
		light_clear();

		if (key1_flag)
		{
			delay_ms(1000);
			start_flag = 1;
		}
	}
}

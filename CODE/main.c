#include "headfile.h"

float32 nuu=0;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	init();

	while(1)
	{
	    key_switch();

	    light_get();
	    Light_Error(&LINELIGHT,&LINECTL);

	    light_clear();


	    if (key1_flag)
	    {
	        delay_ms(1000);
	        start_flag=1;
	    }





	    //      OLED_ShowNum(14,1,LINELIGHT.c_0,10,12);
	    //      OLED_ShowNum(14,2,LINELIGHT.c_1,10,12);
	    //      OLED_ShowNum(14,3,LINELIGHT.c_2,10,12);
	    //      OLED_ShowNum(14,4,LINELIGHT.c_3,10,12);
	    //      OLED_ShowNum(14,5,LINELIGHT.c_4,10,12);

	}


}

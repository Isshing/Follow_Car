
#include "all_init.h"


void init(void)
{
    //OLED初始化
    delay(50);
    OLED_Init();
    OLED_Clear();

    //按键初始化
    button_init();

    //编码器初始化
    encoder_init();
    light_init();
    timer_init(20,20);
    timer_init(11,20);
    motor_init(MOTOR_L_PWM,MOTOR_R_PWM);


//    gpio_init();

//    wireless_init();
//    uart_init(LASER_UART);

    Control_Init();
//    PID_LINE_SET(&LINECTL);

    __bis_SR_register(GIE); // Enter LPM0, interrupts enabled
    _EINT();

//    InitMPU6050();

}

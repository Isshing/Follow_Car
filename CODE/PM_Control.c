#include "PM_Control.h"

int SetLeft;
int SetRight;
char start_flag =0;

void Control_Init(void)
{
    Motor_Left.setpoint  = 15;  //20pwm ~ 0.75m/s
    Motor_Right.setpoint = 15;

    MOTOR.L_Max_I = 1;
    MOTOR.R_Max_I = 1;
    MOTOR.L_Bas_KP  = 2;
    MOTOR.R_Bas_KP  = 2;


}


void Speed_Control(void) //正常循线控制
{
        SetLeft  = Motor_Left.setpoint-LINECTL.out_val;
        SetRight = Motor_Right.setpoint +LINECTL.out_val;

        SetLeft=MINMAX(SetLeft,0,30);
        SetRight=MINMAX(SetRight,0,30);

        Motor_L_Control_Change_Integral(SetLeft, &Motor_Left, &MOTOR, encoder_LL);
        Motor_R_Control_Change_Integral(SetRight, &Motor_Right, &MOTOR, encoder_RR);

        run(Motor_Left.result, Motor_Right.result);
}

void Turn_Left(void)
{
    static int time =0;
    time ++;
    SetLeft =-15;
    SetRight=15;
    if (time <=15)
    {
        Motor_L_Control_Change_Integral(SetLeft, &Motor_Left, &MOTOR, encoder_LL);
        Motor_R_Control_Change_Integral(SetRight, &Motor_Right, &MOTOR, encoder_RR);

        run(Motor_Left.result, Motor_Right.result);
    }
    else
    {
        run(0, 0);
    }

}

void Turn_Right(void)
{
    static int time =0;
    time ++;
    SetLeft =10;
    SetRight=-10;
    if (time <=12)
    {
        Motor_L_Control_Change_Integral(SetLeft, &Motor_Left, &MOTOR, encoder_LL);
        Motor_R_Control_Change_Integral(SetRight, &Motor_Right, &MOTOR, encoder_RR);

        run(Motor_Left.result, Motor_Right.result);
    }
    else
    {
        run(0, 0);
    }

}

void Reback(void)
{
    SetLeft  = -Motor_Left.setpoint;
    SetRight = -Motor_Right.setpoint;

    Motor_L_Control_Change_Integral(SetLeft, &Motor_Left, &MOTOR, encoder_LL);
    Motor_R_Control_Change_Integral(SetRight, &Motor_Right, &MOTOR, encoder_RR);

    run(Motor_Left.result, Motor_Right.result);
}

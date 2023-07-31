#include "PM_Control.h"

int SetLeft;
int SetRight;
char start_flag = 0;

float kp_m = 0;
float kd_m = 0;
float fuzzy_P_out = 0;
float fuzzy_D_out = 0;
float fuzzy_I_out = 0;
float fuzzy_kp = 0;
float fuzzy_kd = 0;
float fuzzy_kp_bas = 0;
float fuzzy_ki = 0;

float DFF[7] = {-21, -14, -7, 0, 7, 14, 21};
float EFF[7] = {-36, -24, -12, 0, 12, 24, 36};

float Vd = 0;

void Control_Init(void)
{
    Motor_Left.setpoint = 15; // 20pwm ~ 0.75m/s
    Motor_Right.setpoint = 15;
    MOTOR.L_Max_I = 2;
    MOTOR.R_Max_I = 2;
    MOTOR.L_Bas_KP = 2;
    MOTOR.R_Bas_KP = 2;
    MOTOR.L_Gain_KP = 3;
    MOTOR.R_Gain_KP = 3;
    MOTOR.L_Cp = 0.2;
    MOTOR.R_Cp = 0.2;
    MOTOR.L_Ci = 0.2;
    MOTOR.R_Ci = 0.2;

    kp_m = 0.145;
    kd_m = 0.14;
    fuzzy_kp_bas = 0.02;
}

void Speed_Control(void) //
{

    //        SetLeft  = Motor_Left.setpoint+LINECTL.out_val;
    //        SetRight = Motor_Right.setpoint-LINECTL.out_val;
    SetLeft = Motor_Left.setpoint - Vd;
    SetRight = Motor_Right.setpoint + Vd;

    SetLeft = MINMAX(SetLeft, 0, 30);
    SetRight = MINMAX(SetRight, 0, 30);

    Motor_L_Control_Change_Integral(SetLeft, &Motor_Left, &MOTOR, encoder_LL);
    Motor_R_Control_Change_Integral(SetRight, &Motor_Right, &MOTOR, encoder_RR);

    run(-Motor_Left.result, -Motor_Right.result);

}

void Turn_Left(void)
{
    static int time = 0;
    time++;
    SetLeft = -15;
    SetRight = 15;
    if (time <= 15)
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
    static int time = 0;
    time++;
    SetLeft = 10;
    SetRight = -10;
    if (time <= 12)
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
    SetLeft = -Motor_Left.setpoint;
    SetRight = -Motor_Right.setpoint;

    Motor_L_Control_Change_Integral(SetLeft, &Motor_Left, &MOTOR, encoder_LL);
    Motor_R_Control_Change_Integral(SetRight, &Motor_Right, &MOTOR, encoder_RR);

    run(Motor_Left.result, Motor_Right.result);
}

float KP_Fuzzy(float E, float EC)
{

    int rule_p[7][7] =
        {
            {6, 5, 4, 4, 3, 0, 0}, //-36
            {6, 4, 3, 3, 2, 0, 0}, //-24
            {4, 3, 2, 1, 0, 1, 2}, //-12
            {2, 1, 1, 0, 1, 1, 2}, // 0
            {2, 1, 0, 1, 2, 3, 4}, // 12
            {0, 0, 2, 3, 3, 4, 6}, // 24
            {0, 1, 3, 4, 4, 5, 6}, // 36
        };

    uint8 i2;

    float UFF[7];

    for (i2 = 0; i2 < 7; i2++)
    {
        UFF[i2] = kp_m / 6 * i2;
    }

    float U = 0;
    float PF[2] = {0}, DF[2] = {0}, UF[4] = {0};

    int Pn = 0, Dn = 0, Un[4] = {0};
    float t1 = 0, t2 = 0, t3 = 0, t4 = 0, temp1 = 0, temp2 = 0;

    if (E > EFF[0] && E < EFF[6])
    {
        if (E <= EFF[1])
        {
            Pn = -2;
            PF[0] = (EFF[1] - E) / (EFF[1] - EFF[0]);
        }
        else if (E <= EFF[2])
        {
            Pn = -1;
            PF[0] = (EFF[2] - E) / (EFF[2] - EFF[1]);
        }
        else if (E <= EFF[3])
        {
            Pn = 0;
            PF[0] = (EFF[3] - E) / (EFF[3] - EFF[2]);
        }
        else if (E <= EFF[4])
        {
            Pn = 1;
            PF[0] = (EFF[4] - E) / (EFF[4] - EFF[3]);
        }
        else if (E <= EFF[5])
        {
            Pn = 2;
            PF[0] = (EFF[5] - E) / (EFF[5] - EFF[4]);
        }
        else if (E <= EFF[6])
        {
            Pn = 3;
            PF[0] = (EFF[6] - E) / (EFF[6] - EFF[5]);
        }
    }

    else if (E <= EFF[0])
    {
        Pn = -2; /*  ??? */
        PF[0] = 1;
    }
    else if (E >= EFF[6])
    {
        Pn = 3;
        PF[0] = 0;
    }

    PF[1] = 1 - PF[0];

    if (EC > DFF[0] && EC < DFF[6])
    {
        if (EC <= DFF[1])
        {
            Dn = -2;
            DF[0] = (DFF[1] - EC) / (DFF[1] - DFF[0]);
        }
        else if (EC <= DFF[2])
        {
            Dn = -1;
            DF[0] = (DFF[2] - EC) / (DFF[2] - DFF[1]);
        }
        else if (EC <= DFF[3])
        {
            Dn = 0;
            DF[0] = (DFF[3] - EC) / (DFF[3] - DFF[2]);
        }
        else if (EC <= DFF[4])
        {
            Dn = 1;
            DF[0] = (DFF[4] - EC) / (DFF[4] - DFF[3]);
        }
        else if (EC <= DFF[5])
        {
            Dn = 2;
            DF[0] = (DFF[5] - EC) / (DFF[5] - DFF[4]);
        }
        else if (EC <= DFF[6])
        {
            Dn = 3;
            DF[0] = (DFF[6] - EC) / (DFF[6] - DFF[5]);
        }
    }

    else if (EC <= DFF[0])
    {
        Dn = -2;
        DF[0] = 1;
    }
    else if (EC >= DFF[6])
    {
        Dn = 3;
        DF[0] = 0;
    }

    DF[1] = 1 - DF[0];

    /*浣跨敤璇樊鑼冨洿浼樺寲鍚庣殑瑙勫垯琛╮ule[7][7]*/
    /*杈撳嚭鍊间娇鐢�13涓毝灞炲嚱鏁�,涓績鍊肩敱UFF[7]鎸囧畾*/
    /*涓�鑸兘鏄洓涓鍒欐湁鏁�*/
    Un[0] = rule_p[Pn + 2][Dn + 2];
    Un[1] = rule_p[Pn + 3][Dn + 2];
    Un[2] = rule_p[Pn + 2][Dn + 3];
    Un[3] = rule_p[Pn + 3][Dn + 3];

    if (PF[0] <= DF[0]) // 姹傚皬
        UF[0] = PF[0];
    else
        UF[0] = DF[0];
    if (PF[1] <= DF[0])
        UF[1] = PF[1];
    else
        UF[1] = DF[0];
    if (PF[0] <= DF[1])
        UF[2] = PF[0];
    else
        UF[2] = DF[1];
    if (PF[1] <= DF[1])
        UF[3] = PF[1];
    else
        UF[3] = DF[1];
    /*鍚岄毝灞炲嚱鏁拌緭鍑鸿瑷�鍊兼眰澶�*/
    if (Un[0] == Un[1])
    {
        if (UF[0] > UF[1])
            UF[1] = 0;
        else
            UF[0] = 0;
    }
    if (Un[0] == Un[2])
    {
        if (UF[0] > UF[2])
            UF[2] = 0;
        else
            UF[0] = 0;
    }
    if (Un[0] == Un[3])
    {
        if (UF[0] > UF[3])
            UF[3] = 0;
        else
            UF[0] = 0;
    }
    if (Un[1] == Un[2])
    {
        if (UF[1] > UF[2])
            UF[2] = 0;
        else
            UF[1] = 0;
    }
    if (Un[1] == Un[3])
    {
        if (UF[1] > UF[3])
            UF[3] = 0;
        else
            UF[1] = 0;
    }
    if (Un[2] == Un[3])
    {
        if (UF[2] > UF[3])
            UF[3] = 0;
        else
            UF[2] = 0;
    }
    t1 = UF[0] * UFF[Un[0]];
    t2 = UF[1] * UFF[Un[1]];
    t3 = UF[2] * UFF[Un[2]];
    t4 = UF[3] * UFF[Un[3]];
    temp1 = t1 + t2 + t3 + t4;
    temp2 = UF[0] + UF[1] + UF[2] + UF[3];
    if (temp2 != 0)
        U = temp1 / temp2;
    else
    {
        U = 0;
    }
    //    temp1=PF[0]*UFF[Un[0]]+PF[1]*UFF[Un[1]]+PF[0]*UFF[Un[2]]+PF[1]*UFF[Un[3]]+DF[0]*UFF[Un[0]]+DF[0]*UFF[Un[1]]+DF[1]*UFF[Un[2]]+DF[0]*UFF[Un[3]];
    //    U=temp1;
    return U;
}

int rule_d[7] = {6, 5, 3, 2, 3, 5, 6};
float Kd_Fuzzy(float EC)
{
    float out = 0;
    uint8 i = 0;
    float degree_left = 0, degree_right = 0;
    uint8 degree_left_index = 0, degree_right_index = 0;

    float UFF[7];

    for (i = 0; i < 7; i++)
    {
        UFF[i] = kd_m / 6 * i;
    }

    if (EC < DFF[0])
    {
        degree_left = 1;
        degree_right = 0;
        degree_left_index = 0;
    }
    else if (EC > DFF[6])
    {
        degree_left = 1;
        degree_right = 0;
        degree_left_index = 6;
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            if (EC >= DFF[i] && EC < DFF[i + 1])
            {
                degree_left = (float)(DFF[i + 1] - EC) / (DFF[i + 1] - DFF[i]);
                degree_right = 1 - degree_left;
                degree_left_index = i;
                degree_right_index = i + 1;
                break;
            }
        }
    }

    out = UFF[rule_d[degree_left_index]] * degree_left + UFF[rule_d[degree_right_index]] * degree_right;

    return out;
}

void pid_diff(void)
{
    float E = 0, EC = 0;
    static float err_last = 0;
    //    static float integral =0;

    E = LINECTL.line_err;
    EC = LINECTL.line_err - err_last;

    float output;

    fuzzy_kp = KP_Fuzzy(E, EC) + fuzzy_kp_bas;
    fuzzy_kd = Kd_Fuzzy(EC);
    //    integral += (LINECTL.line_err + err_last) / 2.0;

    fuzzy_P_out = fuzzy_kp * E;
    fuzzy_D_out = fuzzy_kd * EC;
    //    fuzzy_I_out = fuzzy_ki *integral;

    //    fuzzy_I_out =MINMAX(fuzzy_I_out,-10,10);

    output = -(fuzzy_P_out + fuzzy_D_out);

    Vd = MINMAX(output, -30, 30);

    err_last = LINECTL.line_err;
}

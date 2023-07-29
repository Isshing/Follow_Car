#include "Light.h"

LIGHT LINELIGHT;
LineErrPID LINECTL;

char end = 2;
int line_val;
int check_corner = 0;
int corner_flag = 0;
int beeb_flag = 0;
int corner_enter = 0;
int l0_enable = 1;
int l1_enable = 1;
int l2_enable = 1;
int l3_enable = 1;
int l4_enable = 1;
int l5_enable = 1;
int l6_enable = 1;

// int l10_enable = 1;
// int l11_enable = 1;
// int l12_enable = 1;
// int l13_enable = 1;
// int l14_enable = 1;
// int l15_enable = 1;
// int l16_enable = 1;

int corner_inner_flag = 0;
int corner_outter_flag = 0;
int circle_time = 0;
int force_out = 0;

int light_posi_1[2];
int light_posi_2[2];

int apoint_times = 0;

int apoint_count = 0;
int apoint_time = 0;
// int sent4_flag = 0;
// char hold4 = 9;

float dxd = 0;

void light_init(void)
{

    P3DIR &= ~(BIT6);
    P3OUT &= ~(BIT6);
    P3REN |= (BIT6);

    P6DIR &= ~(BIT1 + BIT2 + BIT0 + BIT6);
    P6OUT &= ~(BIT1 + BIT2 + BIT0 + BIT6);
    P6REN |= (BIT1 + BIT2 + BIT0 + BIT6);

    P1DIR &= ~(BIT6);
    P1OUT &= ~(BIT6);
    P1REN |= (BIT6);

    P7DIR &= ~(BIT0);
    P7OUT &= ~(BIT0);
    P7REN |= (BIT0);
}

void light_get(void)
{
    LINELIGHT.c_0 = C_0_VAL > GET_VAL ? 1 : 0;
    LINELIGHT.c_1 = C_1_VAL > GET_VAL ? 1 : 0;
    LINELIGHT.c_2 = C_2_VAL > GET_VAL ? 1 : 0;
    LINELIGHT.c_3 = C_3_VAL > GET_VAL ? 1 : 0;
    LINELIGHT.c_4 = C_4_VAL > GET_VAL ? 1 : 0;
    LINELIGHT.c_5 = C_5_VAL > GET_VAL ? 1 : 0;
    LINELIGHT.c_6 = C_6_VAL > GET_VAL ? 1 : 0;
}

void light_clear(void)
{
    LINELIGHT.c_0 = 0;
    LINELIGHT.c_1 = 0;
    LINELIGHT.c_2 = 0;
    LINELIGHT.c_3 = 0;
    LINELIGHT.c_4 = 0;
    LINELIGHT.c_5 = 0;
    LINELIGHT.c_6 = 0;
}

void PID_LINE_SET(LineErrPID *pid)
{
    /*10*/
    //    pid->Ki = 0.01;
    //    pid->Kp = 0.085;
    //    pid->kd = 0.09;

    /*15*/
    pid->Ki = 0.01;
    pid->Kp = 0.1;
    pid->kd = 0.15;

    //    if(ProblemNo == 1)
    //    {
    //        DistControlFlag = 1;
    //        NormalSpeed = 8;
    //    }
    //    else if(ProblemNo == 2)
    //    {
    //        DistControlFlag = 0;
    //        NormalSpeed = 25;
    //
    //        pid->Kp = 0.72;
    //    }
    //    else if(ProblemNo == 3)
    //    {
    //        DistControlFlag = 1;
    //        NormalSpeed = 20;
    //
    //        pid->Kp = 0.72;
    //    }
    //    else
    //    {
    //        DistControlFlag = 1;
    //        NormalSpeed = 18;
    //
    //        pid->Kp = 0.72;
    //    }
}

void Light_Error(LIGHT *light, LineErrPID *pid)
{

    short sum = 0;     // 累加器1
    short sum2 = 0;    // 累加器2
    beeb_flag = 0;     // 貌似为蜂鸣器的标志位
    pid->line_err = 0; // 中线偏差

    light_posi_1[0] = 100;
    light_posi_1[1] = 100;

    /***************七路灰度传感器的红线判断****************
     * 灰度编号：0 1 2 3 4 5 6
     * 第3路为中间传感器
     * 判断顺序：从2开始 1 3  0 4
     * pid控制再写一下
     ****************************************************/
    // 最中间灰度不设置偏差
    if (light->c_3 == 1 && l3_enable == 1)
    {
        pid->line_err = -pid->line_err_last * 0.99;
        if (sum < 2)
        {
            light_posi_1[sum] = 3;
        }
        sum++;
        pid->intergral = 0;
    }
    if (light->c_2 == 1 && l2_enable == 1)
    {
        pid->line_err -= 8; //  偏差赋值
        if (sum < 2)
        {
            light_posi_1[sum] = 2;
        }
        sum++;
    }
    if (light->c_4 == 1 && l4_enable == 1)
    {
        pid->line_err += 16;
        if (sum < 2)
        {
            light_posi_1[sum] = 4;
        }
        sum++;
    }
    if (light->c_1 == 1 && l1_enable == 1)
    {

        pid->line_err -= 21;

        if (sum < 2)
        {
            light_posi_1[sum] = 1;
        }
        sum++;
    }
    if (light->c_5 == 1 && l5_enable == 1)
    {

        pid->line_err += 27;

        //                    if(ProblemNo == 2 || ProblemNo == 3)
        //                    {
        //                        pid->line_err += 4;
        //                    }

        if (sum < 2)
        {
            light_posi_1[sum] = 5;
        }
        sum++;
    }
    if (light->c_0 == 1 && l0_enable == 1)
    {
        pid->line_err -= 33;

        //                if(ProblemNo == 2)
        //                {
        //                    pid->line_err -= 6;
        //                }
        //
        //                if(ProblemNo == 2 || ProblemNo == 3)
        //                {
        //                    pid->line_err -= 8;
        //                }

        if (sum < 2)
        {
            light_posi_1[sum] = 0;
        }
        sum++;
    }
    if (light->c_6 == 1 && l6_enable == 1)
    {

        pid->line_err += 37;

        //                if(ProblemNo == 2 || ProblemNo == 3)
        //                {
        //                    pid->line_err -= 1;
        //                }

        if (sum < 2)
        {
            light_posi_1[sum] = 6;
        }
        sum++;
    }

    //        /*********************渚ц竟鐏板害**************************
    //         * 10鍒�16璺�
    //         */
    //        // 10鍒�16璺伆搴︿紶鎰熷櫒鐨勫垽鏂�
    //        if (light->c_13 == 1)
    //        {
    //            if (sum2 < 2)
    //            {
    //                light_posi_2[sum2] = 3;
    //            }
    //            sum2++;
    //        }
    //        if (light->c_12 == 1)
    //        {
    //            if (sum2 < 2)
    //            {
    //                light_posi_2[sum2] = 2;
    //            }
    //            sum2++;
    //        }
    //        if (light->c_14 == 1 && l4_enable == 1)
    //        {
    //            if (sum2 < 2)
    //            {
    //                light_posi_2[sum2] = 4;
    //            }
    //            sum2++;
    //        }
    //        if (light->c_11 == 1 && l1_enable == 1)
    //        {
    //            if (sum2 < 2)
    //            {
    //                light_posi_2[sum2] = 1;
    //            }
    //            sum2++;
    //        }
    //        if (light->c_15 == 1 && l5_enable == 1)
    //        {
    //            if (sum2 < 2)
    //            {
    //                light_posi_2[sum2] = 5;
    //            }
    //            sum2++;
    //        }
    //        if (light->c_10 == 1 && l0_enable == 1)
    //        {
    //            if (sum2 < 2)
    //            {
    //                light_posi_2[sum2] = 0;
    //            }
    //            sum2++;
    //        }
    //        if (light->c_16 == 1 && l6_enable == 1)
    //        {
    //            if (sum2 < 2)
    //            {
    //                light_posi_2[sum2] = 6;
    //            }
    //            sum2++;
    //        }

    //   if (force_out  >= 550)
    //   {
    //       if(corner_flag == 1 || corner_flag == 3)
    //       {
    //           corner_flag++;
    //           force_out = 0;
    //       }
    //   }

    // 灰度没有任何值，保持巡线
    if (sum == 0)
    {
        sum = 1;
        pid->line_err = pid->line_err_last;
    }

    // 进行拐点判断
    if ((sum > 1) || (sum2 > 1))
    {
        if (1)
        {

            // 判断内外圈特征
            if (((abs(light_posi_1[0] - light_posi_1[1]) > 1) && (sum == 2)) /* ||
                 ((abs(light_posi_2[0] - light_posi_2[1]) > 1) && (sum2 == 2))*/
            )
            {
                check_corner++;
                force_out = 0;
                // 连续检测到两次
                if (check_corner >= 2)
                {
                    if (corner_enter > 210)
                    {
                        beeb_flag = 1;
                        corner_flag += 1;
                        corner_enter = 0;
                    }

                    //                   pid->line_err = -pid->line_err;
                    //                      pid->line_err = 50;
                    //                  pid->line_err -= 15;
                }
            }
        }
        else
        {
            beeb_flag = 0;
        }

        // 小问选择
        //            if (problem == 1 || problem == 2)
        //            {
        if (corner_flag == 1 || corner_flag == 3)
        {
            corner_outter_flag = 1;
            corner_inner_flag = 0;
            //                    P1OUT |= BIT0;  // 璁剧疆寮曡剼涓洪珮鐢靛钩
            //                    P4OUT &= ~BIT7; // 璁剧疆寮曡剼涓轰綆鐢靛钩
        }
        if (corner_flag == 2 || corner_flag == 4)
        {
            corner_outter_flag = 1;
            corner_inner_flag = 0;
            //                    P1OUT &= ~BIT0; // 璁剧疆涓や釜寮曡剼涓洪珮鐢靛钩
            //                    P4OUT &= ~BIT7;
        }
        //            }
        //            if (problem == 3)
        //            {
        //                if (corner_flag == 1)
        //                {
        //                    corner_outter_flag = 1;
        //                    corner_inner_flag = 0;
        //                    P1OUT |= BIT0;
        //                    P4OUT &= ~BIT7;
        //                }
        //                if (corner_flag == 2)
        //                {
        //                    corner_outter_flag = 1;
        //                    corner_inner_flag = 0;
        //                    P1OUT &= ~BIT0;
        //                    P4OUT &= ~BIT7;
        //                }
        //                if (corner_flag == 3)
        //                {
        //                    corner_outter_flag = 1;
        //                    corner_inner_flag = 0;
        //                    P1OUT |= BIT0;
        //                    P4OUT &= ~BIT7;
        //                }
        //                if (corner_flag == 4)
        //                {
        //                    corner_outter_flag = 1;
        //                    corner_inner_flag = 0;
        //                    P1OUT &= ~BIT0;
        //                    P4OUT &= ~BIT7;
        //                }
        //                if (corner_flag == 5)
        //                {
        //                    corner_outter_flag = 0;
        //                    corner_inner_flag = 1;
        //                    P1OUT &= ~BIT0;
        //                    P4OUT |= BIT7;
        //                }
        //                if (corner_flag == 6)
        //                {
        //                    corner_outter_flag = 0;
        //                    corner_inner_flag = 1;
        //                    P1OUT &= ~BIT0;
        //                    P4OUT &= ~BIT7;
        //                }
        //            }

        // 连续三个传感器探测到灰度值且间隔一段时间
        //            if (((light->c_0 == 1 && light->c_1 == 1 && light->c_2 == 1) ||
        //                 (light->c_1 == 1 && light->c_2 == 1 && light->c_3 == 1) ||
        //                 (light->c_2 == 1 && light->c_3 == 1 && light->c_4 == 1) ||
        //                 (light->c_3 == 1 && light->c_4 == 1 && light->c_5 == 1) ||
        //                 (light->c_4 == 1 && light->c_5 == 1 && light->c_6 == 1)) &&
        //                (apoint_time > 1100))
        //            {
        //                apoint_time = 0;
        //
        //                beeb_flag = 1;
        //                apoint_times += 1;
        //
        //                if (problem == 1)
        //                {
        //                    problem = 0;
        //                    wireless_send_buff(&end, 1);
        //                    delay(10);
        //                    while (!(UCA1IFG & UCTXIFG))
        //                        ;
        //                    wireless_send_buff(&end, 1);
        //                    delay(10);
        //                    while (!(UCA1IFG & UCTXIFG))
        //                        ;
        //                    wireless_send_buff(&end, 1);
        //                    while (!(UCA1IFG & UCTXIFG))
        //                        ;
        //                    run_flag = 0;
        //                    run_f_l = 0;
        //                }
        //                if (problem == 2)
        //                {
        //                    if (apoint_times == 2)
        //                    {
        //                        problem = 0;
        //                        apoint_times = 0;
        //                        wireless_send_buff(&end, 1);
        //                        delay(10);
        //                        while (!(UCA1IFG & UCTXIFG))
        //                            ;
        //                        wireless_send_buff(&end, 1);
        //                        delay(10);
        //                        while (!(UCA1IFG & UCTXIFG))
        //                            ;
        //                        wireless_send_buff(&end, 1);
        //                        while (!(UCA1IFG & UCTXIFG))
        //                            ;
        //                        run_flag = 0;
        //                        run_f_l = 0;
        //                    }
        //                }
        //                if (problem == 3)
        //                {
        //                    if (apoint_times == 3)
        //                    {
        //                        problem = 0;
        //                        apoint_times = 0;
        //                        wireless_send_buff(&end, 1);
        //                        delay(10);
        //                        while (!(UCA1IFG & UCTXIFG))
        //                            ;
        //                        wireless_send_buff(&end, 1);
        //                        delay(10);
        //                        while (!(UCA1IFG & UCTXIFG))
        //                            ;
        //                        wireless_send_buff(&end, 1);
        //                        while (!(UCA1IFG & UCTXIFG))
        //                            ;
        //                        run_flag = 0;
        //                        run_f_l = 0;
        //                    }
        //                }
        //            }
    }
    //        if (problem == 3)
    //        {
    //            if (corner_flag == 3)
    //            {
    //                NormalSpeed = 15;
    //                beeb_flag = 1;
    //            }
    //            if (corner_flag == 4)
    //            {
    //                NormalSpeed = 20;
    //                if (sent4_flag == 0)
    //                {
    //                    sent4_flag = 1;
    //                    wireless_send_buff(&hold4, 1);
    //                    delay(10);
    //                    while (!(UCA1IFG & UCTXIFG))
    //                        ;
    //                }
    //                DistControlFlag = 1;
    //            }
    //            if (corner_flag == 5)
    //            {
    //                DistControlFlag = 0;
    //                NormalSpeed = 20;
    //                beeb_flag = 1;
    //            }
    //            if (corner_flag == 6)
    //            {
    //                NormalSpeed = 13;
    //            }
    //        }
    //        if ((corner_flag == 4) && (problem != 3))
    //        {
    //            //      corner_flag = 0;
    //        }
    //        if ((corner_flag == 6) && (problem == 3))
    //        {
    //            //      corner_flag = 0;
    //        }

    // 如果选择走外圈 另一侧灰度关闭
    if (corner_outter_flag != 0 && corner_enter < 95)
    {
        pid->line_err = 1;
        l0_enable = 0;
        l1_enable = 0;
        l2_enable = 0;
    }
    // 选择内圈，外部灰度关闭
    if (corner_inner_flag != 0 && corner_enter < 95)
    {
        pid->line_err = -40;
        l4_enable = 0;
        l5_enable = 0;
        l6_enable = 0;
    }
    // 转弯时使用定时器，95次转弯结束后恢复正常巡线
    if ((corner_enter >= 95) && (l0_enable * l1_enable * l2_enable * l3_enable * l4_enable * l5_enable * l6_enable == 0))
    {
        l0_enable = 1;
        l1_enable = 1;
        l2_enable = 1;
        l4_enable = 1;
        l5_enable = 1;
        l6_enable = 1;
    }

    pid->line_err = pid->line_err / sum;

    dxd = pid->line_err - pid->line_err_last;

    //        pid->intergral += (pid->line_err +pid->line_err_last)/2.0;

    //        pid->intergral = MINMAX(pid->intergral, -10, +10);
    //        pid->out_val = pid->Kp * pid->line_err + pid->Ki * pid->intergral+ pid->kd *(pid->line_err -pid->line_err_last) ;
    //        pid->out_val=MINMAX(pid->out_val, -20, 20);

    pid->line_err_last = pid->line_err;

    pid_diff();
}

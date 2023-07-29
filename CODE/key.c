#include "key.h"

int key1_status = 1;
int key2_status = 1;
int key3_status = 1;
int key4_status = 1;

int key1_last_status, key2_last_status, key3_last_status, key4_last_status;

int key1_flag, key2_flag, key3_flag, key4_flag;

void key_switch(void)
{

    key1_flag = 0;
    key2_flag = 0;
    key3_flag = 0;
    key4_flag = 0;

    key1_last_status = key1_status;
    key2_last_status = key2_status;
    //    key3_last_status = key3_status;
    //    key4_last_status = key4_status;

    key1_status = ((P1IN & BIT1) == 0);
    key2_status = ((P2IN & BIT1) == 0);
    //    key3_status = gpio_get_level(KEY3);
    //    key4_status = gpio_get_level(KEY4);

    if (key1_status && !key1_last_status)
        key1_flag = 1;
    if (key2_status && !key2_last_status)
        key2_flag = 1;
    //    if (key3_status && !key3_last_status)
    //        key3_flag = 1;
    //    if (key4_status && !key4_last_status)
    //        key4_flag = 1;
}

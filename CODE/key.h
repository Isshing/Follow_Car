#ifndef CODE_KEY_H_
#define CODE_KEY_H_

#include "headfile.h"
#include "Oled_type.h"

extern int key1_status, key2_status, key3_status, key4_status;
extern int key1_last_status, key2_last_status, key3_last_status, key4_last_status;
extern int key1_flag, key2_flag, key3_flag, key4_flag;

void key_switch(void);


#endif /* CODE_KEY_H_ */

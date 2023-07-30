#ifndef CODE_ADC_H_
#define CODE_ADC_H_

#include "headfile.h"

#define vrefp 3.3
#define vrefm 0
#define mv_to_adc12(mv) (4095 * (mv - vrefm) / (vrefp + vrefm))

void configure_adc(void);
void start_sampling(void);

#endif /* CODE_ADC_H_ */

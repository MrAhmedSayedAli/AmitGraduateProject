/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_ADC_H
#define AMIT_COURSE_ADC_H

#include "BitMath.h"
#include "hw.h"
#include "adc_types.h"

void ADC_Init(void);
int16 ADC_Read(ADC_ChannelTypes ChannelId);
t_uint16 ADC_Read16(ADC_ChannelTypes ChannelId);


#endif //AMIT_COURSE_ADC_H

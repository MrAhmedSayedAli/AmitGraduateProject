/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_TEST_LED_H
#define DIO_TEST_LED_H

#include "dio/dio.h"

void LED_ON(DIO_ChannelTypes ChannelId);
void LED_OFF(DIO_ChannelTypes ChannelId);
void LED_TOGGLE(DIO_ChannelTypes ChannelId);

#endif //DIO_TEST_LED_H

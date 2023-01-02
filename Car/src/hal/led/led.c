/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "led.h"

void LED_ON(DIO_ChannelTypes ChannelId){
    DIO_WriteChannel(ChannelId,STD_HIGH);
}

void LED_OFF(DIO_ChannelTypes ChannelId){
    DIO_WriteChannel(ChannelId,STD_LOW);
}

void LED_TOGGLE(DIO_ChannelTypes ChannelId){
    if (DIO_ReadChannel(ChannelId) == STD_HIGH){
        LED_OFF(ChannelId);
    }else{
        LED_ON(ChannelId);
    }
}

/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_BLUETOOTH_H
#define AMIT_COURSE_BLUETOOTH_H

#include "uart/uart.h"

void Bluetooth_Init();
void Bluetooth_Transmit(int8 data);
int8 Bluetooth_Receive();
void Bluetooth_TransmitString(int8 * string);

#endif //AMIT_COURSE_BLUETOOTH_H

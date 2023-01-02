/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "bluetooth.h"


void Bluetooth_Init(){
    Uart_Init();
}
void Bluetooth_Transmit(int8 data){
    Uart_Transmit(data);
}
int8 Bluetooth_Receive(){
    return Uart_Receive();
}
void Bluetooth_TransmitString(int8 * string){
    Uart_TransmitString(string);
}

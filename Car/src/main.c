/*
By : (Ahmed Elsayed Abdulrahman Ali) AND (Ismael Galal)
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/


#include "util/delay.h"

#include "dio/dio.h"
#include "timer/timer.h"

#include "lcd/lcd.h"
#include "bluetooth/bluetooth.h"

int8 motorState = 0;
int8 servoState = 0;

void carDirection(int8 dir); // 0 => ZeroDir , 1 => RightDir , 2 => LeftDir
void carState(int8 state); // 0 => Stop ,, 1 => Forward , 2 => Backward
void lcdPrint(int8 *string);



int main() {


    //LCD
    DIO_WriteDirection(DIO_ChannelA4, OUTPUT);
    DIO_WriteDirection(DIO_ChannelA5, OUTPUT);
    DIO_WriteDirection(DIO_ChannelA6, OUTPUT);
    DIO_WriteDirection(DIO_ChannelA7, OUTPUT);

    DIO_WriteDirection(DIO_ChannelB0, OUTPUT);
    DIO_WriteDirection(DIO_ChannelB1, OUTPUT);
    DIO_WriteDirection(DIO_ChannelB2, OUTPUT);
    DIO_WriteDirection(DIO_ChannelB3, OUTPUT);

    //MOTOR
    DIO_WriteDirection(DIO_ChannelC3, OUTPUT);
    DIO_WriteDirection(DIO_ChannelC4, OUTPUT);

    //SERVO
    DIO_WriteDirection(DIO_ChannelD5, OUTPUT);
    DIO_WriteDirection(DIO_ChannelD7, OUTPUT);


    //DIO_WriteChannel(DIO_ChannelC3,STD_HIGH);
    //DIO_WriteChannel(DIO_ChannelC4,STD_LOW);

    //_delay_ms(1000);

    TIMER1_INIT();
    Uart_Init();
    //LCD_INIT();
    int8 bluetoothReservedData;

    TIMER1_SetVal(3000); //0 degree
    while (1) {


//TEST SERVO
//        TIMER1_SetVal(2000);  //-90 degree
//        _delay_ms(1000);
//        TIMER1_SetVal(3000); //0 degree
//        _delay_ms(1000);
//        TIMER1_SetVal(4000);  //+90 degree
//        _delay_ms(1000);
//        continue;


        bluetoothReservedData = Bluetooth_Receive();

//TEST
//        LCD_CMD(0x01);
//        LCD_SET_POS(0, 0);
//        LCD_CHAR(bluetoothReservedData);
//        LCD_SET_POS(2, 0);

        switch (bluetoothReservedData) {
            case 'E':
                //carState(1);
                break;
            case 'D':
                carState(0);
                break;
            case 'F':
                carState(1);
                break;
            case 'B':
                carState(2);
                break;
            case 'R':
                carDirection(1);
                break;
            case 'L':
                carDirection(2);
                break;
            case 'Z':
                carDirection(0);
                break;
        }


        //_delay_ms(3);
    }
}

//========================================================================>
void lcdPrint(int8 *string) {
    //LCD_CMD(0x01);
    //LCD_SET_POS(0, 0);
    LCD_INT8_STRING(string);
}
//========================================================================>

// 0 => ZeroDir , 1 => RightDir , 2 => LeftDir
void carDirection(int8 dir) {
    if(servoState == dir) return;
    servoState = dir;
    switch (dir) {
        case 1:
            TIMER1_SetVal(4000);
            break;
        case 2:
            TIMER1_SetVal(2000);
            break;
        case 0:
            TIMER1_SetVal(3000);
            break;
    }
}

//========================================================================>
// 0 => Stop , 1 => Forward , 2 => Backward
void carState(int8 state) {
    if(motorState == state) return;
    motorState = state;
    switch (state) {
        case 1:
            DIO_WriteChannel(DIO_ChannelC3,STD_HIGH);
            DIO_WriteChannel(DIO_ChannelC4,STD_LOW);
            break;
        case 2:
            DIO_WriteChannel(DIO_ChannelC3,STD_LOW);
            DIO_WriteChannel(DIO_ChannelC4,STD_HIGH);
            break;
        case 0:
            DIO_WriteChannel(DIO_ChannelC3,STD_LOW);
            DIO_WriteChannel(DIO_ChannelC4,STD_LOW);
            break;
    }
}
//========================================================================>




/*
By : (Ahmed Elsayed Abdulrahman Ali) AND (Ismael Galal)
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/
#include "stdio.h"
#include "util/delay.h"

#include "dio/dio.h"
#include "adc/adc.h"

#include "bluetooth/bluetooth.h"

int8 potState(int16 pot,int16 min);

int main(){

    //SET FROM A0 TO A4 FOR POT ADC VALUE
    DIO_WriteDirection(DIO_ChannelA0,INPUT);
    DIO_WriteDirection(DIO_ChannelA1,INPUT);
    DIO_WriteDirection(DIO_ChannelA2,INPUT);
    DIO_WriteDirection(DIO_ChannelA3,INPUT);
    DIO_WriteDirection(DIO_ChannelA4,INPUT);

    ADC_Init();
    Uart_Init();


    int16 ADC_POT_01 = 0;
    int16 ADC_POT_02 = 0;
    int16 ADC_POT_03 = 0;
    int16 ADC_POT_04 = 0;
    int16 ADC_POT_05 = 0;


    while(1){

        //READ POT VALUES
        ADC_POT_01 = ADC_Read(DIO_ChannelA0);
        ADC_POT_02 = ADC_Read(DIO_ChannelA1);
        ADC_POT_03 = ADC_Read(DIO_ChannelA2);
        ADC_POT_04 = ADC_Read(DIO_ChannelA3);
        ADC_POT_05 = ADC_Read(DIO_ChannelA4);
        _delay_ms(5);

        //CONVERT POT VALUE TO ON OFF (1,0)
        int8 pot01 = potState(ADC_POT_01,450);
        int8 pot02 = potState(ADC_POT_02,800);
        int8 pot03 = potState(ADC_POT_03,400);
        int8 pot04 = potState(ADC_POT_04,400);
        int8 pot05 = potState(ADC_POT_05,400);

        int8 carState = 'D';

        int8 pot01Char = pot01 == 1 ? 'F' : 'D';
        int8 pot02Char = pot02 == 1 ? 'B' : 'D';

        if(pot01Char == 'F' && pot02Char == 'D'){
            carState = 'F';
        }else if(pot01Char == 'D' && pot02Char == 'B'){
            carState = 'B';
        }else{
            carState = 'D';
        }

        //--------------------->
        int8 pot03Char = pot03 == 1 ? 'R' : 'Z';
        int8 pot04Char = pot04 == 1 ? 'L' : 'Z';

        int8 carDir = 'Z';

        if(pot03Char == 'R' && pot04Char == 'Z'){
            carDir = 'R';
        }
        else if(pot03Char == 'Z' && pot04Char == 'L'){
            carDir = 'L';
        }else{
            carDir = 'Z';
        }

        Bluetooth_Transmit(carState);
        _delay_ms(1);
        Bluetooth_Transmit(carDir);

        //FINGER 5  BROKEN
        //int8 pot05Char = pot05 == 1 ? 'S' : 'S';
        //Bluetooth_Transmit(pot05Char);

        //FOR TESTING
        //int8 pot01String[20];
        //sprintf(pot01String, "( %d ) ( %d ) ( %d ) ( %d ) ( %d ) \n", ADC_POT_01,ADC_POT_02,ADC_POT_03,ADC_POT_04,ADC_POT_05);
        //sprintf(pot01String, "( %d ) ( %d ) ( %d ) ( %d ) ( %d ) \n", pot01,pot02,pot03,pot04,pot05);
        //Bluetooth_TransmitString(pot01String);

        //int8 carCase[10];
        //sprintf(carCase, "%c%c%c%c%c\n", pot01Char,pot02Char,pot03Char,pot04Char,pot05Char);
        //Bluetooth_TransmitString(carCase);

        //_delay_ms(3);
    }
}
int8 potState(int16 pot,int16 min){
    if(pot > min ){
        return 1;
    } else{
        return 0;
    }
}






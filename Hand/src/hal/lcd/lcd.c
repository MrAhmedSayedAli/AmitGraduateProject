/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/


#include "lcd.h"
//#define F_CPU 16000000UL
#include "util/delay.h"

void LCD_INIT(void){

    DIO_WriteChannel(LCD_RW,STD_LOW);
    DIO_WriteChannel(LCD_E,STD_HIGH);
    _delay_ms(20);

    LCD_CMD(0x33);
    _delay_ms(100);

    LCD_CMD(0x32);
    LCD_CMD(0x28);
    LCD_CMD(0x06);
    LCD_CMD(0x0C);
    LCD_CMD(0x01);
}
//------------------------------>

void LCD_CMD(uint8 cmd){

    uint8 portValue = 0;

    DIO_WriteChannel(LCD_RS,STD_LOW);

    portValue = DIO_ReadPort(LCD_DATA_PORT);
    portValue = (portValue & 0x0F) | (cmd & 0xF0);

    DIO_WritePort(LCD_DATA_PORT,portValue);
    DIO_WriteChannel(LCD_E,STD_LOW);
    _delay_ms(100);
    DIO_WriteChannel(LCD_E,STD_HIGH);

    _delay_ms(5);

    portValue = DIO_ReadPort(LCD_DATA_PORT);
    portValue = (portValue & 0x0F) | (cmd << 4);

    DIO_WritePort(LCD_DATA_PORT,portValue);
    DIO_WriteChannel(LCD_E,STD_LOW);
    _delay_ms(100);
    DIO_WriteChannel(LCD_E,STD_HIGH);
    _delay_ms(2);
}
//------------------------------>
void LCD_STRING(uint8 *string){
    uint8 i = 0;

    while(string[i] != '\0' ) {
        LCD_CHAR(string[i]);
        i++;
    }

}

//------------------------------>
void LCD_INT8_STRING(int8 *string){
    int8 i = 0;
    while(string[i] != '\0' ) {
        LCD_CHAR(string[i]);
        i++;
    }

}
//------------------------------>
void LCD_CHAR(uint8 data){
    uint8 portValue = 0;

    DIO_WriteChannel(LCD_RS,STD_HIGH);

    portValue = DIO_ReadPort(LCD_DATA_PORT);
    portValue = (portValue & 0x0F) | (data & 0xF0);

    DIO_WritePort(LCD_DATA_PORT,portValue);
    DIO_WriteChannel(LCD_E,STD_LOW);
    _delay_us(100);
    DIO_WriteChannel(LCD_E,STD_HIGH);

    _delay_ms(5);

    portValue = DIO_ReadPort(LCD_DATA_PORT);
    portValue = (portValue & 0x0F) | (data << 4);

    DIO_WritePort(LCD_DATA_PORT,portValue);
    DIO_WriteChannel(LCD_E,STD_LOW);
    _delay_us(100);
    DIO_WriteChannel(LCD_E,STD_HIGH);
    _delay_ms(2);
}
//------------------------------>
void LCD_SET_POS(uint8 line,uint8 pos){
    if(line == 1){
        LCD_CMD((0x80 | (pos & 0x0F)));
    }else if(line == 2){
        LCD_CMD((0xC0 | (pos & 0x0F)));
    }else{

    }
}
//------------------------------>
void LCD_POS_CHAR(uint8 line,uint8 pos,uint8 data){
    LCD_SET_POS(line,pos);
    LCD_CHAR(data);
}
//------------------------------>
void LCD_CUSTOM_CHAR(uint8 loc,uint8 *msg){
    uint8 i;
    if(loc < 8){
        LCD_CMD(0x40 + (loc*8));
        for ( i = 0; i < 8; i++) {
            LCD_CHAR(msg[i]);
        }
    }
}
//------------------------------>
/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_LCD_H
#define DIO_LCD_H

#include "dio/dio.h"

#define LCD_RS DIO_ChannelB1
#define LCD_RW DIO_ChannelB2
#define LCD_E DIO_ChannelB3
#define LCD_DATA_PORT DIO_PortA


void LCD_INIT(void);
void LCD_CMD(uint8 cmd);
void LCD_STRING(uint8 *string);
void LCD_INT8_STRING(int8 *string);
void LCD_CHAR(uint8 data);
void LCD_POS_CHAR(uint8 line,uint8 pos,uint8 data);
void LCD_SET_POS(uint8 line,uint8 pos);
void LCD_CUSTOM_CHAR(uint8 loc,uint8 *msg);
#endif //DIO_LCD_H

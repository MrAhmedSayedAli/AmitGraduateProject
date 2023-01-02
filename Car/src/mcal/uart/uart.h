/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_UART_H
#define AMIT_COURSE_UART_H

#include "hw.h"
#include "util//delay.h"
#include "BitMath.h"

#define BaudRate (9600)

//#define DoupleSpeed

#ifndef DoupleSpeed
#define MyUBRR ((F_CPU/(16UL*BaudRate))-1)
#else
#define MyUBRR ((F_CPU/(8UL*BaudRate))-1)
#endif

#define UART_UCSRA_UDRE_FLAG (5)
#define UART_UCSRA_TXC_FLAG (6)
#define UART_UCSRA_RXC_FLAG (7)

#define UART_UCSRB_RX_ENABLE (1<<4)
#define UART_UCSRB_TX_ENABLE (1<<3)

#define UART_UCSRC_5BIT_DATA (0<<1)
#define UART_UCSRC_6BIT_DATA (1<<1)
#define UART_UCSRC_7BIT_DATA (2<<1)
#define UART_UCSRC_8BIT_DATA (3<<1)
#define UART_UCSRC_SELECT_REG (1<<7)

void Uart_Init();
void Uart_Transmit(int8 data);
int8 Uart_Receive();
void Uart_TransmitString(int8 * string);

#endif //AMIT_COURSE_UART_H

/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_HW_H
#define AMIT_COURSE_HW_H
#include "STD_Types.h"

#define UART_UDR_REG (*(volatile uint8 *)0x2C)
#define UART_UCSRA_REG (*(volatile uint8 *)0x2B)
#define UART_UCSRB_REG (*(volatile uint8 *)0x2A)
#define UART_UCSRC_REG (*(volatile uint8 *)0x40)
#define UART_UBRRL_REG (*(volatile uint8 *)0x29)
#define UART_UBRRH_REG (*(volatile uint8 *)0x40)

#endif //AMIT_COURSE_HW_H

/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "uart.h"


void Uart_Init(){
    UART_UCSRB_REG = (UART_UCSRB_RX_ENABLE|UART_UCSRB_TX_ENABLE);//enable TX & RX
    UART_UCSRC_REG = (UART_UCSRC_SELECT_REG|UART_UCSRC_8BIT_DATA);//8 BIT DATA & SELECT UCSRC REG.
    UART_UBRRL_REG = MyUBRR;
    UART_UBRRH_REG = MyUBRR>>8;
}
void Uart_Transmit(int8 data){
    while(getBit(UART_UCSRA_REG,UART_UCSRA_UDRE_FLAG) == STD_LOW);
    UART_UDR_REG = data;
}
int8 Uart_Receive(){
    while(getBit(UART_UCSRA_REG,UART_UCSRA_RXC_FLAG) == STD_LOW);
    return UART_UDR_REG;
}
void Uart_TransmitString(int8 * string){
    uint8 i=0;
    while (string[i] != '\0')
    {
        Uart_Transmit(string[i]);
        i++;
    }
}
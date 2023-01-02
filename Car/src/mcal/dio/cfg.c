/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "cfg.h"
#include "dio.h"

DIO_PinCfg PinCfg[] = {
        //PORTA
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},

        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},

        //PORTB
        {INPUT,STD_LOW},//BTN
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},

        //PORTC
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_LOW},
        {OUTPUT,STD_HIGH},

        //PORTD
        {INPUT,STD_HIGH},
        {INPUT,STD_HIGH},
        {INPUT,STD_LOW},//BTN
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {OUTPUT,STD_HIGH},
        {INPUT,STD_LOW},//BTN
        {OUTPUT,STD_HIGH}
};


void dioInit(void){
    DIO_ChannelTypes count = DIO_ChannelA0;
    DIO_PortTypes Port;
    DIO_ChannelTypes BitNo;
    for (count = DIO_ChannelA0;count<PIN_COUNT;count++)
    {
        Port = count/8;
        BitNo = count%8;

        switch(Port){
            case DIO_PortA:
                if (PinCfg[count].PinDir == OUTPUT)
                {
                    setBit(DDRA_Reg,BitNo);
                }
                else{
                    clearBit(DDRA_Reg,BitNo);
                }
                break;
            case DIO_PortB:
                if (PinCfg[count].PinDir == OUTPUT)
                {
                    setBit(DDRB_Reg,BitNo);
                }
                else{
                    clearBit(DDRB_Reg,BitNo);
                }
                break;
            case DIO_PortC:
                if (PinCfg[count].PinDir == OUTPUT)
                {
                    setBit(DDRC_Reg,BitNo);
                }
                else{
                    clearBit(DDRC_Reg,BitNo);
                }
                break;
            case DIO_PortD:
                if (PinCfg[count].PinDir == OUTPUT)
                {
                    setBit(DDRD_Reg,BitNo);
                }
                else{
                    clearBit(DDRD_Reg,BitNo);
                }
                break;

            default:
                break;
        }
    }
}
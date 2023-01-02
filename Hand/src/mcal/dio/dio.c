/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/


#include "dio.h"


void DIO_WriteChannel(DIO_ChannelTypes ChannelId, STD_LevelTypes Level) {
    DIO_PortTypes Ports = ChannelId / 8;
    DIO_ChannelTypes BitNo = ChannelId % 8;
    switch (Ports) {
        case DIO_PortA:
            if (Level == STD_HIGH) {
                setBit(PORTA_Reg, BitNo);
            } else {
                clearBit(PORTA_Reg, BitNo);
            }
            break;
        case DIO_PortB:
            if (Level == STD_HIGH) {
                setBit(PORTB_Reg, BitNo);
            } else {
                clearBit(PORTB_Reg, BitNo);
            }
            break;
        case DIO_PortC:
            if (Level == STD_HIGH) {
                setBit(PORTC_Reg, BitNo);
            } else {
                clearBit(PORTC_Reg, BitNo);
            }
            break;
        case DIO_PortD:
            if (Level == STD_HIGH) {
                setBit(PORTD_Reg, BitNo);
            } else {
                clearBit(PORTD_Reg, BitNo);
            }
            break;
        default:
            break;
    }
}


void DIO_WriteDirection(DIO_ChannelTypes ChannelId,DIO_DirTypes Dir){
    DIO_PortTypes Ports = ChannelId / 8;
    DIO_ChannelTypes BitNo = ChannelId % 8;
    switch (Ports) {
        case DIO_PortA:
            if (Dir == OUTPUT) {
                setBit(DDRA_Reg, BitNo);
            } else {
                clearBit(DDRA_Reg, BitNo);
            }
            break;
        case DIO_PortB:
            if (Dir == OUTPUT) {
                setBit(DDRB_Reg, BitNo);
            } else {
                clearBit(DDRB_Reg, BitNo);
            }
            break;
        case DIO_PortC:
            if (Dir == OUTPUT) {
                setBit(DDRC_Reg, BitNo);
            } else {
                clearBit(DDRC_Reg, BitNo);
            }
            break;
        case DIO_PortD:
            if (Dir == OUTPUT) {
                setBit(DDRD_Reg, BitNo);
            } else {
                clearBit(DDRD_Reg, BitNo);
            }
            break;
        default:
            break;
    }
}


STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId) {
    DIO_PortTypes Ports = ChannelId / 8;
    DIO_ChannelTypes BitNo = ChannelId % 8;
    STD_LevelTypes BitValue = STD_LOW;
    switch (Ports) {
        case DIO_PortA:
            BitValue = getBit(PINA_Reg, BitNo);
            break;
        case DIO_PortB:
            BitValue = getBit(PINB_Reg, BitNo);
            break;
        case DIO_PortC:
            BitValue = getBit(PINC_Reg, BitNo);
            break;
        case DIO_PortD:
            BitValue = getBit(PIND_Reg, BitNo);
            break;
        default:
            break;
    }
    return BitValue;
}


uint8 DIO_ReadPort(DIO_PortTypes port) {

    switch (port) {
        case DIO_PortA:
             return PORTA_Reg;
        case DIO_PortB:
            return PORTB_Reg;
        case DIO_PortC:
            return PORTC_Reg;
        case DIO_PortD:
            return PORTD_Reg;
        default:
            return 0;
    }
}

void DIO_WritePort(DIO_PortTypes port, uint8 value) {

    switch (port) {
        case DIO_PortA:
            PORTA_Reg = value;
            break;
        case DIO_PortB:
            PORTB_Reg = value;
            break;
        case DIO_PortC:
            PORTC_Reg = value;
            break;
        case DIO_PortD:
            PORTD_Reg = value;
            break;
        default:
            return;
    }


}
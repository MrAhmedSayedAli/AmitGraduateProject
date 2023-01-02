/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "eint.h"

void Ext_INT_Enable(Ext_INT_Types INTId) {
    switch (INTId) {
        case Ext_INT0:
            setBit(GICR_REG, GICR_INT0_Bit);
            break;
        case Ext_INT1:
            setBit(GICR_REG, GICR_INT1_Bit);
            break;
        case Ext_INT2:
            setBit(GICR_REG, GICR_INT2_Bit);
            break;
    }
}

void Ext_INT_Disable(Ext_INT_Types INTId) {
    switch (INTId) {
        case Ext_INT0:
            clearBit(GICR_REG, GICR_INT0_Bit);
            break;
        case Ext_INT1:
            clearBit(GICR_REG, GICR_INT1_Bit);
            break;
        case Ext_INT2:
            clearBit(GICR_REG, GICR_INT2_Bit);
            break;
    }
}

void Ext_INT_Sncontrol(Ext_INT_Types INTId, Ext_ISC_Types mode) {
    switch (INTId) {
        case Ext_INT0:
            MCUCR_REG |= (mode << 0);
            break;
        case Ext_INT1:
            MCUCR_REG |= (mode << 2);
            break;
        case Ext_INT2:
            if (mode == Falling_Edge) {
                clearBit(MCUCSR_REG, MCUCSR_INT2_ISC2_Bit);
            } else if (mode == Rising_Edge) {
                setBit(MCUCSR_REG, MCUCSR_INT2_ISC2_Bit);
            } else {
            }
            break;
    }
}

/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "gint.h"

void Enable_GINT_AllInterrupts(void){
    setBit(SREG_REG,GINT_I_Bit);
}
void Disable_GINT_AllInterrupts(void){
    clearBit(SREG_REG,GINT_I_Bit);
}
/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_EINT_H
#define AMIT_COURSE_EINT_H

#include "BitMath.h"
#include "hw.h"
#include "types.h"

void Ext_INT_Enable(Ext_INT_Types INTId);
void Ext_INT_Disable(Ext_INT_Types INTId);
void Ext_INT_Sncontrol(Ext_INT_Types INTId,Ext_ISC_Types mode);

#endif //AMIT_COURSE_EINT_H

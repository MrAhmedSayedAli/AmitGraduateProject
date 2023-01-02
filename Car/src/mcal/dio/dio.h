/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_TEST_DIO_H
#define DIO_TEST_DIO_H

#include "BitMath.h"
#include "STD_Types.h"
#include "hw.h"
#include "types.h"
#include "cfg.h"

typedef struct
{
    DIO_DirTypes PinDir;
    STD_LevelTypes Level;

}DIO_PinCfg;

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes Level);
void DIO_WriteDirection(DIO_ChannelTypes ChannelId,DIO_DirTypes Dir);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId);

uint8 DIO_ReadPort(DIO_PortTypes port);
void DIO_WritePort(DIO_PortTypes port,uint8 data);


#endif //DIO_TEST_DIO_H

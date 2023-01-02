/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef DIO_TEST_STD_TYPES_H
#define DIO_TEST_STD_TYPES_H

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned short int t_uint16;
typedef unsigned long int uint32;

//#define NULL 0

typedef enum {
    STD_LOW = 0,
    STD_HIGH
} STD_LevelTypes;


typedef enum {
    FALSE = 0,
    TRUE
} boolean;




#endif //DIO_TEST_STD_TYPES_H

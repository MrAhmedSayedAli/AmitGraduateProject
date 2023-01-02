/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_IO_H
#define AMIT_COURSE_IO_H

#include <avr/io.h>

//PORT A
#define A0 A,0
#define A1 A,1
#define A2 A,2
#define A3 A,3
#define A4 A,4
#define A5 A,5
#define A6 A,6
#define A7 A,7

//PORT B
#define B0 B,0
#define B1 B,1
#define B2 B,2
#define B3 B,3
#define B4 B,4
#define B5 B,5
#define B6 B,6
#define B7 B,7

//PORT C
#define C0 C,0
#define C1 C,1
#define C2 C,2
#define C3 C,3
#define C4 C,4
#define C5 C,5
#define C6 C,6
#define C7 C,7

//PORT D
#define D0 D,0
#define D1 D,1
#define D2 D,2
#define D3 D,3
#define D4 D,4
#define D5 D,5
#define D6 D,6
#define D7 D,7



//Macros to edit PORT, DDR and PIN
#define PinMode(x, y)   (y ?_SET(DDR, x) : _CLEAR(DDR, x))
#define PinModeToggle(x)    (_TOGGLE(DDR, x))

#define DigitalWrite(x,y)   (y ? _SET(PORT, x) : _CLEAR(PORT, x))
#define DigitalRead(x)  (_GET(PIN, x))

#define DigitalLevelToggle(x)   ( _TOGGLE(PORT, x))

//General use bit manipulating commands
#define BitSet(x, y)    (x |= (1UL<<y))
#define BitClear(x, y)  (x &= (~(1UL<<y)))
#define BitToggle(x, y) (x ^= (1UL<<y))
#define BitCheck(x, y)  (x & (1UL<<y) ? 1 : 0)

//Access PORT, DDR and PIN
#define PORT(port)  (_PORT(port))
#define DDR(port)   (_DDR(port))
#define PIN(port)   (_PIN(port))

#define _PORT(port) (PORT## port)
#define _DDR(port)  (DDR## port)
#define _PIN(port)  (PIN## port)

#define _SET(type, port, bit)    (BitSet((type##port),bit))
#define _CLEAR(type, port, bit)    (BitClear((type##port),bit))
#define _TOGGLE(type, port, bit)    (BitToggle((type##port),bit))
#define _GET(type, port, bit)    (BitCheck((type##port), bit))



//Definitions
#define INPUT        0
#define OUTPUT        !INPUT
#define LOW            0
#define HIGH        !LOW
#define FALSE        0
#define TRUE        !FALSE

#endif //AMIT_COURSE_IO_H

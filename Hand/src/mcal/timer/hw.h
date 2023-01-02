/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_HW_H
#define AMIT_COURSE_HW_H

#include "STD_Types.h"

//TIMER ZERO
#define TIMER0_TCCR0_REG   (* (volatile uint8 *) (0x53))
#define TIMER0_TCNT0_REG   (* (volatile uint8 *) (0x52))
#define TIMER0_OCR0_REG    (* (volatile uint8 *) (0x5C))
#define TIMER0_TIMSK_REG   (* (volatile uint8 *) (0x59))
#define TIMER0_TIFR_REG    (* (volatile uint8 *) (0x58))

#define TIMER1_TIMSK_REG       (*((volatile uint8*)0x59))
#define TIMER1_TIFR_REG        (*((volatile uint8*)0x58))
#define TIMER1_TCCR1A_REG      (*((volatile uint8*)0x4F))
#define TIMER1_TCCR1B_REG      (*((volatile uint8*)0x4E))

#define TIMER1_TCNT1H_REG      (*((volatile uint8*)0x4D))
#define TIMER1_TCNT1L_REG      (*((volatile uint8*)0x4C))

#define TIMER1_ICR1H_REG      (*((volatile uint8*)0x47))
#define TIMER1_ICR1L_REG      (*((volatile uint16*)0x46))

#define TIMER1_TCCR2_REG      (*((volatile uint8*)0x45))



#define TIMER1_TCCR1A_COM1A1 7
#define TIMER1_TCCR1A_COM1A0 6
#define TIMER1_TCCR1A_WGM11  1
#define TIMER1_TCCR1A_WGM10  0

#define TIMER1_TCCR1B_WGM13 4
#define TIMER1_TCCR1B_WGM12 3
#define TIMER1_TCCR1B_CS12  2
#define TIMER1_TCCR1B_CS11  1
#define TIMER1_TCCR1B_CS10  0


#define TIMER1_TCNT1_REG      *((volatile uint16*)0x4C)
#define TIMER1_OCR1A_REG      *((volatile uint16*)0x4A)
#define TIMER1_OCR1B_REG      *((volatile uint16*)0x48)
#define TIMER1_ICR_REG        *((volatile uint16*)0x46)





#endif //AMIT_COURSE_HW_H

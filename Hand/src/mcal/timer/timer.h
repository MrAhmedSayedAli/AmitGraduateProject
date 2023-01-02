/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#ifndef AMIT_COURSE_TIMER_H
#define AMIT_COURSE_TIMER_H

#include "STD_Types.h"

/************************************************************
 * 			TIMER0 OPERATION MODES							*
 ************************************************************/
#define TIMER0_MODE_NONE            		(0)
#define TIMER0_MODE_INTERVAL             	(1)
#define TIMER0_MODE_CTC          			(2)
#define TIMER0_MODE_FAST_PWM        		(3)
#define TIMER0_MODE_PWM_PHASE_CORRECT		(4)
/*
 * TIMER0_MODE_NONE
 * TIMER0_MODE_INTERVAL
 * TIMER0_MODE_CTC
 * TIMER0_MODE_FAST_PWM
 * TIMER0_MODE_PWM_PHASE_CORRECT
 */
#define TIMER_OPERATION_MODE TIMER0_MODE_CTC

/***************************************************/
/*	TIMER0 Operation Modes	*/
#define TIMER0_INTERVAL_MODE				((uint8)0<<3)
#define TIMER0_CTC_MODE						((uint8)1<<3)
#define TIMER0_PWM_FAST						((uint8)9<<3)
#define TIMER0_PWM_PHASE_CORRECT			((uint8)8<<3)

/*	TIMER0 Clock Select Prescaler	*/
#define TIMER0_CS_DISABLED					((uint8)0<<0)	/* Timer0 Stopped */
#define TIMER0_CS_NO_PRESCALER				((uint8)1<<0)
#define TIMER0_CS_8_PRESCALER				((uint8)2<<0)
#define TIMER0_CS_64_PRESCALER				((uint8)3<<0)
#define TIMER0_CS_256_PRESCALER				((uint8)4<<0)
#define TIMER0_CS_1024_PRESCALER			((uint8)5<<0)
#define TIMER0_CS_External_FAILING_EDGE		((uint8)6<<0)
#define TIMER0_CS_External_RISING_EDGE		((uint8)7<<0)

/*	CTC Modes	*/
#define CTC_OC0_DISCONNECTED				((uint8)0<<4)
#define CTC_OC0_TOGGLE						((uint8)1<<4)
#define CTC_OC0_LOW							((uint8)2<<4)
#define CTC_OC0_HIGH						((uint8)3<<4)

/*	Fast PWM Modes	*/
#define PWM_FAST_OC0_DISCONNECTED			((uint8)0<<4)
#define PWM_FAST_OC0_NON_INVERTED			((uint8)2<<4)
#define PWM_FAST_OC0_INVERTED				((uint8)3<<4)

/*	Phase Correct PWM Modes	*/
#define PWM_PHASE_CORRECT_OC0_DISCONNECTED	((uint8)0<<4)
#define PWM_PHASE_CORRECT_OC0_NON_INVERTED	((uint8)2<<4)
#define PWM_PHASE_CORRECT_OC0_INVERTED		((uint8)3<<4)

/*	Timer0 Interrupt Enable	Bits */
#define TIMER0_INTERVAL_INT_ENABLE_BIT_NO		(0)
#define TIMER0_CTC_INT_ENABLE_BIT_NO			(1)

/*	Timer0 Top Value	*/
#define TIMER0_TOP 			(255u)
/***************************************************/

void TIMER0_INIT(void);
void TIMER0_SetCompareMatchValue(uint8 compareMatchValue);

void TIMER0_StartTimer(uint8 prescaler);
void TIMER0_StopTimer(void);

void TIMER0_SetPreLoad(uint8 value);
uint8 TIMER0_GetPreload(void);

void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_PWM(uint8 freq, uint8 dutyCycle);



void TIMER1_INIT(void);

void TIMER1_SetVal(uint16 val);

void TIMER1_PMW_INIT(void);
void TIMER1_PMW_START(void);
void TIMER1_PMW(uint16 val);

void TIMER2_INIT(void);

//TIMER1




#endif //AMIT_COURSE_TIMER_H

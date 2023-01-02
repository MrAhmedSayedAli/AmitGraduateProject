/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/

#include "timer.h"
#include "hw.h"
#include "BitMath.h"

void TIMER0_INIT(void) {
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
    TIMER0_TCCR0_REG|= TIMER0_INTERVAL_MODE;
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
    //TIMER0_TCCR0_REG |= TIMER0_CTC_MODE;
    // Select Mode = CTC Mode
    clearBit(TIMER0_TCCR0_REG,6);
    setBit(TIMER0_TCCR0_REG,3);

    // Enable CTC Interrupt
    setBit(TIMER0_TIMSK_REG,1);

    // Select Prescaler Value = 64
    setBit(TIMER0_TCCR0_REG,0);
    setBit(TIMER0_TCCR0_REG,1);
    clearBit(TIMER0_TCCR0_REG,2);

#elif (TIMER_OPERATION_MODE == TIMER0_MODE_FAST_PWM)
    TIMER0_TCCR0_REG|= TIMER0_PWM_FAST;
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_PWM_PHASE_CORRECT)
    TIMER0_TCCR0_REG|= TIMER0_PWM_PHASE_CORRECT;
#else
#error "You Shall Define Timer Operation Mode In Timer0_Cfg.h"
#endif
}

//=====================================>
void TIMER0_SetCompareMatchValue(uint8 compareMatchValue){
    TIMER0_OCR0_REG = compareMatchValue;
}
//=====================================>
void TIMER0_StartTimer(uint8 prescaler) {
    TIMER0_TCCR0_REG |= prescaler;
}

//------------------------------------->
void TIMER0_StopTimer(void) {
    TIMER0_TCCR0_REG &= 0xF8; // 1111 1000
}

//=====================================>
void TIMER0_SetPreLoad(uint8 value) {
    TIMER0_TCNT0_REG = value;
}

//------------------------------------->
uint8 TIMER0_GetPreload(void) {
    return TIMER0_TCNT0_REG;
}

//=====================================>
void TIMER0_EnableInterrupt(void) {
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
    setBit(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
    setBit(TIMER0_TIMSK_REG, TIMER0_CTC_INT_ENABLE_BIT_NO);
#endif
}

//------------------------------------->
void TIMER0_DisableInterrupt(void) {
#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
    clearBit(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
    clearBit(TIMER0_TIMSK_REG, TIMER0_CTC_INT_ENABLE_BIT_NO);
#endif
}

//------------------------------------->
void TIMER0_PWM(uint8 freq, uint8 dutyCycle) {
    uint16 result = 0;
    result = (dutyCycle * TIMER0_TOP) / 100;
    TIMER0_OCR0_REG = result;
}
//========================================================================>
void TIMER1_INIT(void){

    setBit(TIMER1_TCCR1A_REG,TIMER1_TCCR1A_COM1A1);
    clearBit(TIMER1_TCCR1A_REG,TIMER1_TCCR1A_COM1A0);

    clearBit(TIMER1_TCCR1A_REG,TIMER1_TCCR1A_WGM10);
    setBit(TIMER1_TCCR1A_REG,TIMER1_TCCR1A_WGM11);
    setBit(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_WGM12);
    setBit(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_WGM13);


    TIMER1_ICR_REG = 40000;
    TIMER1_OCR1A_REG = 2000;

    clearBit(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_CS10);
    setBit(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_CS11);
    clearBit(TIMER1_TCCR1B_REG,TIMER1_TCCR1B_CS12);
}

//-------------------------------------->
void TIMER1_PMW_INIT(void){


    // Select Mode = Fast PWM Mode(14)
    clearBit(TIMER1_TCCR1A_REG,0);
    setBit(TIMER1_TCCR1A_REG,1);
    setBit(TIMER1_TCCR1B_REG,3);
    setBit(TIMER1_TCCR1B_REG,4);

    // Select Non Inverting Mode
    clearBit(TIMER1_TCCR1A_REG,6);
    setBit(TIMER1_TCCR1A_REG,7);

    // ICR1 >> period time = 20ms >> freq. = 50HZ
    TIMER1_ICR1L_REG = 4999;


}
//-------------------------------------->
void TIMER1_PMW_START(void){
    // Select Prescaler Value = 64
    setBit(TIMER1_TCCR1B_REG,0);
    setBit(TIMER1_TCCR1B_REG,1);
    clearBit(TIMER1_TCCR1B_REG,2);
}
//-------------------------------------->
void TIMER1_PMW(uint16 val){
    TIMER1_TCCR1B_REG = val;
}
//-------------------------------------->
void TIMER1_SetVal(uint16 val){
    TIMER1_OCR1A_REG = val;
}
//-------------------------------------->
void TIMER2_INIT(void){
    //TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
}
//-------------------------------------->
//-------------------------------------->
//-------------------------------------->
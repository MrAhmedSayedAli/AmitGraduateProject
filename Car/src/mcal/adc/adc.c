/*
By : Ahmed Elsayed Abdulrahman Ali
Email : mrahmedsayedali@gmail.com
github : https://github.com/MrAhmedSayedAli
*/
#include "avr/io.h"
#include "adc.h"
#include "util/delay.h"

void ADC_Init(void){
    setBit(ADMUX_Reg,ADCMUX_REFS1_Bit);//Internal Vref
    setBit(ADMUX_Reg,ADCMUX_REFS0_Bit);
    setBit(ADCSRA_Reg,ADCSRA_ADPS0_Bit);//F_CPU/128
    setBit(ADCSRA_Reg,ADCSRA_ADPS1_Bit);
    setBit(ADCSRA_Reg,ADCSRA_ADPS2_Bit);
    setBit(ADCSRA_Reg,ADCSRA_ADEN_Bit);//Enable ADC
}
int16 ADC_Read(ADC_ChannelTypes ChannelId){
    int16 temp = 0;
    ADMUX_Reg = (ADMUX_Reg & 0xE0) | (ChannelId & 0x1F);
    setBit(ADCSRA_Reg,ADCSRA_ADSC_Bit);
    while(getBit(ADCSRA_Reg,ADCSRA_ADIF_Bit) == 0);//wait finish conversion
    setBit(ADCSRA_Reg,ADCSRA_ADIF_Bit);//clear the flag
    temp = ADCL_Reg;
    temp |= (ADCH_Reg << 8);
    _delay_ms(1);
    return temp;
}

uint16 ADC_Read16(ADC_ChannelTypes ChannelId){

    uint16 temp = 0;
    ADMUX_Reg = (ADMUX_Reg & 0xE0) | (ChannelId & 0x1F);
    setBit(ADCSRA_Reg,ADCSRA_ADSC_Bit);
    while(getBit(ADCSRA_Reg,ADCSRA_ADIF_Bit) == 0);//wait finish conversion
    setBit(ADCSRA_Reg,ADCSRA_ADIF_Bit);//clear the flag
    temp = ADCL_Reg;
    temp |= (ADCH_Reg << 8);
    _delay_ms(1);
    return temp;


}



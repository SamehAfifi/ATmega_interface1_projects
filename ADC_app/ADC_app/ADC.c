/*
 * CFile1.c
 *
 * Created: 4/29/2017 4:35:28 PM
 *  Author: safifi
 */

#include "ADC.h"

void ADC0_init(){
	ADMUX = 0x40;// 0x00
	ADCSRA = 0b10000111;
}

uint16_t ADC0_read(){
	ADCSRA |= 1<<6; //
	while(READBIT(ADCSRA,6));
	return (ADCL+ (ADCH << 8));
}

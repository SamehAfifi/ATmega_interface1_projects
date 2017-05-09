/*
 * TIMER0.c
 *
 * Created: 4/22/2017 12:04:30 AM
 *  Author: safifi
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>
#include "timers.h"
#define F_CPU 8000000UL
#include<util/delay.h>
extern uint64_t t1 ;
extern uint64_t t2 ;
#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((Reg >> BIT) & 1)

int main(void)
{
	SETBIT(DDRD,7);
	SETBIT(DDRD,6);
	//timer0_init();
	timer0_init_ocr();
	//timer2_init_oc2();
    while(1)
    {
		if (timer0_ms_ocr() > 1000)
		{
			TOGBIT(PORTD,7);
			//t1 = 0;
			t2 = 0;
		}
        //TODO:: Please write your application code 
    }
}
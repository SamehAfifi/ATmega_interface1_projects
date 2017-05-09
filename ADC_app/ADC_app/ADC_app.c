/*
 * ADC_app.c
 *
 * Created: 4/29/2017 4:34:53 PM
 *  Author: safifi
 */ 

#include "ADC.h"
#include "lcd.h"

int main(void)
{
	ADC0_init();
	lcd_init();
    while(1)
    {
		lcd_write_number(ADC0_read());
		_delay_ms(1000);
		lcd_write_cmd(clear);
		lcd_write_cmd(0xc0);
		
    }
}
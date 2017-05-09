/*
 * keypad_app.c
 *
 * Created: 4/28/2017 10:30:58 PM
 *  Author: safifi
 */ 

#include "keypad.h"
#include "lcd.h"
#include "std_macros.h"
int main(void)
{
	keypad_init();
	lcd_init();
    while(1)
    {
		
		if (keypad_click() != -1) 
		{
			lcd_write_cmd(0x01); //clear
			lcd_write_cmd(0xc4); // 2nd_line+4
			lcd_write_char(keypad_click());
			_delay_ms(200);
		}
    }
}
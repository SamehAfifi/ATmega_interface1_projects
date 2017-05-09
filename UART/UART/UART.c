/*
 * UART.c
 *
 * Created: 4/25/2017 8:27:20 AM
 *  Author: safifi
 */ 


#include "lcd.h"
#include "UART_.h"

int main(void)
{
	lcd_init();
	Uart_init(9600);
    int i = 0;
    while(1)
    {
		Uart_Write(i++);
		if (Uart_available())
		{
			lcd_write_cmd(0x01);
			lcd_write_cmd(0xc0);
			lcd_write_number(Uart_Read());	
		}
		_delay_ms(1000);
    }
}
/*
 * I2C_app.c
 *
 * Created: 4/25/2017 8:59:57 AM
 *  Author: safifi
 */ 


#include "I2C.h"
#include "lcd.h"
#include "std_macros.h"

int main(void)
{
	I2C_Slave_Init(0x50);
	lcd_init();
    while(1)
    {
		if (I2C_Slave_avialable())
		{
			lcd_write_cmd(clear);
			lcd_write_cmd(0xc0);
			uint8_t data = I2C_read_ack();
			lcd_write_number(data);
		}					
    }
}
/*
int main(void)
{
	I2C_init();
    while(1)
    {
		I2C_start(0x50);
		I2C_write(k++);
		I2C_stop();
	}
}	
*/

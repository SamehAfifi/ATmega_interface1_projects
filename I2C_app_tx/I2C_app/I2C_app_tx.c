/*
 * I2C_app.c
 *
 * Created: 4/25/2017 8:59:57 AM
 *  Author: safifi
 */ 


#include "I2C.h"
#include "std_macros.h"

int main(void)
{
	I2C_init();
	uint8_t i = 0;
    while(1)
    {
	    I2C_start(0x50);
	    I2C_write(i++);
	    I2C_stop();
	    _delay_ms(1000);
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

/*
 * app.c
 *
 * Created: 5/6/2017 12:55:05 PM
 *  Author: safifi
 */ 


#include "std_macros.h"
#include "lcd.h"
#include "I2C.h"
#include "ADC.h"
#include "PWM.h"
#include "UART.h"
#define ADC_PWM 0
#define uart 0
int main(void)
{
	I2C_Slave_Init(0x50); //slave
//	I2C_init();//master
	uint8_t i = 0;
	Uart_init(9600);
	lcd_init();
	PWM1_OCR1A_init();
	PWM1_OCR1B_init();
	ADC0_init();
	lcd_write_cmd(0x80);
	lcd_write_txt((uint8_t*)"ADC_value = ");
    while(1)
    {
/*
		//master write
		I2C_start(0x50);
		I2C_write(i++);
		I2C_stop();
		_delay_ms(1000);
*/
		
		//slave read
		if (I2C_Slave_avialable())
		{
			lcd_write_cmd(nd_line);
			lcd_write_txt("      ");
			lcd_write_cmd(nd_line);
			lcd_write_number(I2C_read_ack());
		}

		#if ADC_PWM == 1
			lcd_write_cmd(nd_line);
			lcd_write_txt("      ");
			lcd_write_cmd(nd_line);
			uint16_t adc_data = (((float)(ADC_update_value())/((float)1023))) * 100;
			lcd_write_number(adc_data);
			PWM1_OCR1A_SET_DUTY(adc_data);
			PWM1_OCR1B_SET_DUTY(adc_data);
			_delay_ms(100);
		#endif
		#if uart == 1
			Uart_Write(i++);
			_delay_ms(1000);
			lcd_write_cmd(nd_line);
			lcd_write_txt("      ");
			lcd_write_cmd(nd_line);
			lcd_write_number(Uart_Read());
		#endif
    }
}
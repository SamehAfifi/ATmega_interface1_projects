/*
 * SVEn_seg.c
 *
 * Created: 5/6/2017 11:49:54 AM
 *  Author: safifi
 */ 
#include "std_macros.h"
#include "seven_seg.h"
int main(void)
{
	seven_seg_init();
	uint16_t counter =0;
	uint8_t i;
	i = 0;
	
    while(1)
    {
		for(counter = 0 ; counter <500;counter++){
			seven_seg_update(i);
		}		
		i++;
    }
}
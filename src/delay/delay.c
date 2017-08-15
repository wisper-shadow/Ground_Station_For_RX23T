#include "delay.h"

void delay_ms(unsigned int t)//delay_time>t ms,fcpu=10MHZ
{
	unsigned char i,j;
	while(t--)
	{
		for(i=0;i<100;i++)
			for(j = 0; j< 100; j++)
			{
				;
			}
	}
}
void delay_us(unsigned int t)//delay_time>t us,fcpu=10MHZ
{
	unsigned char i;
	while(t--)
	{
		for(i=0;i<10;i++)
		{
			;
		}
	}
}

/*
 * GccApplication1.c
 *
 * Created: 31-Mar-20 12:09:30 AM
 * Author : shimo
 */ 
#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
int i = 0;
int j = 0;

int main(void)
{
	DDRC = 0b1111;
	DDRD = 0b1111;
    while (1) 
    {
		for (i=0; i<10; i++)
		{
			PORTD = i;
			for (j=0; j<10; j++)
			{
				PORTC = j;
				_delay_ms (200);
			}
			
		}
		
		for (i=9; i>=0; i--)
		{
			PORTD = i;
			for (j=9; j>=0; j--)
			{
				PORTC = j;
				_delay_ms (200);
			}
		}
		
    }
	}



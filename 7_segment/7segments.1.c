/*
 * GccApplication1.c
 *
 * Created: 02-Apr-20 10:27:36 PM
 * Author : shimo
 */ 
#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
int i = 0;
int S1 =0;
int S2 =0;

int main(void)
{
	DDRC = 0xFF;		//all pins are output
    while (1) 
    {
		for (i=0; i<=100; i++)
		{
			S1 = i % 10;
			S2 = i / 10;
			PORTC = S1 | (S2<<4);
			_delay_ms (200);
			
		}
    }
}


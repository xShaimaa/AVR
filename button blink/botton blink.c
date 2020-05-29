/*
 * GccApplication1.c
 *
 * Created: 30-Mar-20 9:26:25 PM
 * Author : shimo
 */ 
#define  F_CPU 4000000
#include <avr/io.h>


int main(void)
{
	DDRC |=(1<<1); 
    while (1) 
    {
		if (PINC &=(1<<0))
		{
			PORTC |=(1<<1);	
		} 
		else
		{
			PORTC &=~ (1<<1);
		}
    }
}


/*
 * GccApplication1.c
 *
 * Created: 30-Mar-20 6:38:07 AM
 * Author : shimo
 */ 
#define F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>
#define RED 1
#define YELLOW 2
#define GREEN 3

int main(void)
{
	DDRC |=(0b111<<RED);
	
    while (1) 
    {
		PORTC |= (1<<RED);
		_delay_ms(500);
		PORTC &= ~(1<<RED);
		PORTC |=(1<<YELLOW);
		_delay_ms(500);
		PORTC &= ~(1<<YELLOW);
		PORTC |=(1<<GREEN);
		_delay_ms(500);
		PORTC &= ~(1<<GREEN);
    }
}


/*
 * GccApplication1.c
 *
 * Created: 30-Mar-20 6:27:53 AM
 * Author : shimo
 */ 
#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LED 1

int main(void)
{
	DDRC |= (1<<LED);
    while (1) 
    {
		PORTC |= (1<<LED);
		_delay_ms(500);
		PORTC &= ~(1<<LED);
		_delay_ms(500);
    }
}


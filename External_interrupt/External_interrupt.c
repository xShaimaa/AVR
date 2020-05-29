/*
 * interrupt.c
 *
 * Created: 12-Apr-20 1:12:30 AM
 * Author : shimoo
 */ 

#include <avr/io.h>
#include "avr/interrupt.h"
#define  F_CPU 4000000UL

int main(void)
{
	DDRC |= ((1<<1) | (1<<2) | (1<<3));					//setting pins C1, C2, C3 as output
	PORTD |= (1<<2) | (1<<3);							// pull up activated for buttons on D2 and D3 "external interrupt"
	PORTB |= (1<<2);									// pull up activated for button on B2 "external interrupt"
 	sei ();												//setting the I bit in SREG register	
	GICR |= ((1<<INT0) | (1<<INT1) | (1<<INT2));		//enabling all external interrupt pins
	MCUCR |= ((1<<ISC01) | (1<<ISC11));					//setting the interrupt sense control bit to falling edge 
	MCUCR &= ~((1<<ISC00) | (1<<ISC10));
	MCUCSR &= ~(1<<ISC2);
    while (1) 
    {
    }
}

//ISR for external interrupt INT0 on D2
ISR (INT0_vect){
	PORTC ^= (1<<1);
	
}

//ISR for external interrupt INT1 on D3
ISR (INT1_vect){
	PORTC ^= (1<<2);
	
}

//ISR for external interrupt INT2 on B2
ISR (INT2_vect){
	PORTC ^= (1<<3);
	
}

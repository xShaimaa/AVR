/*
 * timer-generating delays.c
 *
 * Created: 23-Apr-20 11:48:28 PM
 * Author : shimo
 */ 

#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 8000000UL		 
#endif
//XTAL = 8M Hz, clock cycle = 0.125 micro sec
//prescaler = 1:256, cycle = 0.125*256 = 32 micro sec
//to generate 1 sec delay, 1/32 micro = 31250 tick
//timer1 overflows every 65000 tick, so, use CTC mode
 #include "avr/interrupt.h"

void timer1_delay();

int main(void)
{
	DDRD |= (1<<1) ;					//configure led as output on pin 1 port D
	TCNT1 = (65536-31250);							//setting TCNT1 register to zero
	//TCCR1A |= (1<<WGM12);				//enable timer1 mode 4, normal mode
	TCCR1B |= (1<<CS12);				//set the prescalar to 256
	sei ();	
	TIMSK |= (1<<TOIE1);
    while (1) 
    {
// 		timer1_delay();
    }
}

/*void timer1_delay(){
	TCNT1 = 0;							//setting TCNT1 register to zero
	TCCR1A |= (1<<WGM12);				//enable timer1 mode 4, CTC
	TCCR1B |= (1<<CS12);				//set the prescalar to 256
	OCR1A = 31250;						//to make 1 sec time delay
	if (TIFR & (1<<OCF1A)) {			//when timer1 overflow flag is set
		PORTD ^= (1<<1);
		TIFR |= (1<<OCF1A);					//clear timer1 overflow flag
		TCNT1 = 0;
	}
}*/

/*void timer1_delay(){
	if (TIFR & (1<<TOV1)) {			//when timer1 overflow flag is set
		PORTD ^= (1<<1);
		TIFR |= (1<<TOV1);					//clear timer1 overflow flag
		TCNT1 = (65536-31250);
	}
}*/

ISR (TIMER1_OVF_vect){
		PORTD ^= (1<<1);
		//TIFR |= (1<<TOV1);					//clear timer1 overflow flag
		TCNT1 = (65536-31250);
	
	
}
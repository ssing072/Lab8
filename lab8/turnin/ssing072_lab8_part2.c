/*	Author: ssing072
 *  Partner(s) Name: Neha Gupt
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ACD_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}


//PART 1 and 2
int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTC = 0x00;
	ACD_init();
    while (1) 
    {
		unsigned short out = ADC;
		unsigned char b_out = (char)out;
		unsigned char d_out = (char)(out >> 8);
		PORTB = b_out;
		PORTD = d_out;	
    }
	return 1;
}

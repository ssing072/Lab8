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
int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTC = 0x00;
	unsigned short max = 200;
	ACD_init();
	while (1)
	{
		unsigned short out = ADC;
		if(out <= 0){
			PORTB = 0x00;
		}
		else if(out >= max){
			PORTB = 0xFF;
		} 
		else if (out >= 175) {
			PORTB = 0x7F;
		}
		else if (out >= 150) {
			PORTB = 0x3F;
		}
		else if (out >= 125) {
			PORTB = 0x1F;
		}
		else if (out >= 100) {
			PORTB = 0x0F;
		}
		else if (out >= 75) {
			PORTB = 0x07;
		}
		else if (out >= 50) {
			PORTB = 0x03;
		}
		else if (out < 50) {
			PORTB = 0x01;
		}
	}
	return 1;
}

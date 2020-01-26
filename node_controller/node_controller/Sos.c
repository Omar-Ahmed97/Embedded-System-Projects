/*
 * Sos.c
 *
 * Created: 26/01/2020 03:14:45 م
 *  Author: Omar
 */ 

#include "Sos.h"


void Timer0_init(){
	//Timer0 1ms initialize
	
	cli();//stop interrupts
	
	//set timer0 interrupt at 1kHz
	TCCR0A = 0;// set entire TCCR0A register to 0
	TCCR0B = 0;// same for TCCR0B
	TCNT0  = 0;//initialize counter value to 0
	
	// set compare match register for 1khz increments
	OCR0A = 249;// = (16*10^6) / (2000*64) - 1 (must be <256)
	// turn on CTC mode
	TCCR0A |= (1 << WGM01);
	// Set CS01 and CS00 bits for 64 prescalar
	TCCR0B |= (1 << CS01) | (1 << CS00);
	// enable timer compare interrupt
	TIMSK0 |= (1 << OCIE0A);

	sei(); //allow interrupts
	
}

ISR(TIMER0_COMPA_vect){  //timer0 interrupt 1kHz
	
	tick4_ms++;    //take an event every 4 Milli seconds
	
	UP();			//check up switch pressed 
	DOWN();			//check down switch pressed 
	OK(HIGH);			// OK button has pressed
	
	if( 4 == tick4_ms){

		disp_off();  // turn off the display
		switch (current_digit)
		{
			case 1 :
				SEG1_on();
				break;
			
			case 2:
				SEG2_on();
				break;
			
			case 3:
				SEG3_on();
				break;
			
		}
		
		current_digit = (current_digit % 3) + 1;
		tick4_ms = 0; //reset Delay
		
	}
	
}
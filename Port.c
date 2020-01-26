/*
 * Port.c
 *
 * Created: 26/01/2020 07:13:44 م
 *  Author: Omar
 */ 

#include "Port.h"
void port_init(){

	/* 7Segment Connected Pins Segment.C*/
	//DATA PINS
	for ( char i=2 ; i< 8 ; i++)  // 2 to 7 of PORTD
	{
		SET_BIT(DDRD, i);
	}

	SET_BIT(DDRB, PINB0);   //first bit of PORTB

	// CONTROL PINS

	SET_BIT(DDRB, PINB1);  //DIG1
	SET_BIT(DDRC, PINC3);  //DIG2
	SET_BIT(DDRC, PINC4);  //DIG3


	/* SWITCHES (UP , DOWN , OK )  SWITCHE.C*/

	RESET_BIT(DDRC, PINC0);		// UP
	SET_BIT(PORTC, PINC0);		// enable internal pull_up resistor
	RESET_BIT(DDRC, PINC1);		 //DOWN
	SET_BIT(PORTC, PINC1);		// enable internal pull_up resistor
	RESET_BIT(DDRC, PINC2);		//OK
	SET_BIT(PORTC, PINC2);		// enable internal pull_up resistor


	/* SPI PINS (SS , MISO , MOSI ,SCL)   SPI.C*/
	RESET_BIT(DDRB, PINB2);  //INPUT SS
	RESET_BIT(DDRB, PINB3);    //INPUT MOSI
	RESET_BIT(DDRB, PINB5);    //INPUT SCL

	SET_BIT(DDRB, PINB4);    //OUTPUT MISO

}
/*
 * Switch.c
 *
 * Created: 26/01/2020 03:05:19 م
 *  Author: Omar
 */ 

#include"Switch.h" 

static volatile char sw1Debounce =0;     //State of switch to prevent debounce
 volatile char sw1UP_Pressed = 0;

static volatile char sw2Debounce =0;     //State of switch to prevent debounce
 volatile char sw2DOWN_Pressed = 0;

static volatile char sw3Debounce =0;     //State of switch to prevent debounce
 volatile char sw3OK_Pressed = 0;


void UP(){
	if(READ_BIT(PINC, Sw1)== LOW){
		
		if(100 == sw1Debounce){
			sw1Debounce = 0;
			sw1UP_Pressed = 1;

		}
		else {
			sw1Debounce++;
		}
		
	}
	else{
		sw1Debounce = 0;
	}
	
}

void DOWN(){
	
	if(READ_BIT(PINC, Sw2)== LOW){
		
		if(100 == sw2Debounce){
			sw2Debounce = 0;
			sw2DOWN_Pressed = 1;	
		}
		else {
			sw2Debounce++;
		}
		
	}
	else{
		sw2Debounce = 0;
	}
}

void OK( ){
	if(READ_BIT(PINC, Sw3)== LOW){
		
		if(100 == sw3Debounce){
			sw3Debounce = 0;
			sw3OK_Pressed = 1;
		
		}
		else {
			sw3Debounce++;
		}
		
	}
	else{
		sw3Debounce = 0;
	}
}

void UP_pressed(volatile unsigned int* count , int val){
	if(sw1UP_Pressed)
	{
		(*count)+=val;
		sw1UP_Pressed = 0;
	}
}

void DOWN_pressed(volatile unsigned int* count , int val){
	if(sw2DOWN_Pressed)
	{
		(*count)-=val;
		sw2DOWN_Pressed = 0;
	}
}

void OK_pressed(volatile char* SEL , char st){
	if(sw3OK_Pressed)
	{
		(*SEL)= st;
		sw3OK_Pressed = 0;
	}
}


/*
 * Switch.h
 *
 * Created: 26/01/2020 03:04:45 م
 *  Author: Omar
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "main.h"
#include "Port.h"




void UP();
void DOWN();
void OK( );
void UP_pressed(volatile unsigned int* count , int val);
void DOWN_pressed(volatile unsigned int* count , int val);
void OK_pressed(volatile char* SEL , char st);
#endif /* SWITCH_H_ */
/*
 * Segments.h
 *
 * Created: 25/01/2020 07:13:48 م
 *  Author: Omar
 */ 


#ifndef SEGMENTS_H_
#define SEGMENTS_H_

#include "main.h"
#include "Port.h"



// codes for displaying on 7segments
 
#define A 10
#define b 11
#define C 12
#define d 13
#define E 14
#define F 15
#define G 16
#define H 17
#define h 18
#define i 19
#define L 20
#define n 21
#define o 22
#define p 23
#define q 24
#define r 25
#define s 26
#define t 27
#define U 28
#define v 29
#define y 30
#define Z 31
#define M 32


volatile char s1,s2,s3;    // position of character in tables

void disp(unsigned char number);
void disp_off();
void SEG1_on();
void SEG2_on();
void SEG3_on();
#endif /* SEGMENTS_H_ */
/*
 * Port.h
 *
 * Created: 25/01/2020 04:00:35 م
 *  Author: Omar
 */ 


#ifndef PORT_H_
#define PORT_H_
#include "main.h"

// connected pins to 7Segment

#define SegA PIND2
#define SegB PIND3
#define SegC PIND4
#define SegD PIND5
#define SegE PIND6
#define SegF PIND7
#define SegG PINB0

//connected pins to 7Segment Enable
#define Dig1 PINB1 // [!][!][x]
#define Dig2 PINC3 // [!][x][!]
#define Dig3 PINC4// [x][!][!]

// connected to (up , down , ok)
#define Sw1 PINC0
#define Sw2 PINC1
#define Sw3 PINC2

void port_init();
#endif /* PORT_H_ */
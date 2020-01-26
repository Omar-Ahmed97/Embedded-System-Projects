/*
 * Sos.h
 *
 * Created: 26/01/2020 03:14:26 م
 *  Author: Omar
 */ 


#ifndef SOS_H_
#define SOS_H_

#include "main.h"
#include "Port.h"


static volatile char tick4_ms = 0;
static volatile char current_digit = 1;  //determine which segments on

void Timer0_init();

#endif /* SOS_H_ */
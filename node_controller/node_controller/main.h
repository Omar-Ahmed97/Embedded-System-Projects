/*
 * main.h
 *
 * Created: 25/01/2020 03:47:56 م
 *  Author: Omar
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#define LOW 0
#define HIGH 1

#define MAX_NUM_ITEMS 8

#define SET_BIT(ADDRESS, BIT) (ADDRESS |= (1<<BIT))
#define RESET_BIT(ADDRESS, BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS, BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS, BIT) ((ADDRESS & (1<<BIT))>>BIT)

#endif /* MAIN_H_ */
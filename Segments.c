/*
 * Segments.c
 *
 * Created: 25/01/2020 07:13:24 م
 *  Author: Omar
 */ 

#include "Segments.h"
void disp(unsigned char number)
{
	switch (number)
	{
		case 0:  // print 0
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		
		case 1:  // print 1
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		
		case 2:  // print 2
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		
		case 3:  // print 3
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		
		case 4:  // print 4
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		
		case 5:  // print 5
		SET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		
		case 6:  // print 6
		SET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		
		case 7:  // print 7
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		
		case 8:  // print 8
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		
		case 9:  // print 9
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case A:  // print 9
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case b:  // print 9
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case C:  // print 9
		SET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		case d:  // print 9
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case E:  // print 9
		SET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case F:  // print 9
		SET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case G:  // print 9
		SET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		case H:  // print 9
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case h:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case i:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		case L:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		case n:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case o:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;

		case p:  // print 9
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTD, SegG);
		break;

		case q:  // print 9
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case r:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case s:  // print 9
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case t:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case U:  // print 9
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		case v:  // print 9
		RESET_BIT(PORTD, SegA);
		RESET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		case y:  // print 9
		RESET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		RESET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case Z:  // print 9
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		RESET_BIT(PORTD, SegC);
		SET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		RESET_BIT(PORTD, SegF);
		SET_BIT(PORTB, SegG);
		break;
		case M:  // print 9
		SET_BIT(PORTD, SegA);
		SET_BIT(PORTD, SegB);
		SET_BIT(PORTD, SegC);
		RESET_BIT(PORTD, SegD);
		SET_BIT(PORTD, SegE);
		SET_BIT(PORTD, SegF);
		RESET_BIT(PORTB, SegG);
		break;
		
	}
}
void disp_off()
{
	RESET_BIT(PORTB, Dig1);
	RESET_BIT(PORTC, Dig2);
	RESET_BIT(PORTC, Dig3);
}

void SEG1_on(){
	disp(s1);   // prepare to display digit 1 (most left)
	SET_BIT(PORTB , Dig1);  // turn on digit 1
}
void SEG2_on(){
	disp(s2);   // prepare to display digit 1 (most left)
	SET_BIT(PORTC , Dig2);  // turn on digit 1
}
void SEG3_on(){
	disp(s3);   // prepare to display digit 1 (most left)
	SET_BIT(PORTC , Dig3);  // turn on digit 1
}


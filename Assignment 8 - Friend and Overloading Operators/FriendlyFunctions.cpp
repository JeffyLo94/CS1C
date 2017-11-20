/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #8 : Friend Functions and Overloaded Operators
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/14/2014
*******************************************************************************/

#include "StudentClass.h"

// Friend Functions
bool isEqual(const Student& studOne, const Student& studTwo)
{
	return studOne.id == studTwo.id;
}




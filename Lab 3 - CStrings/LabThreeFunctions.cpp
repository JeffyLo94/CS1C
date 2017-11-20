/*******************************************************************************
*	AUTHOR	 : Jeffrey Lo
*	STU ID#	 : 374780
*	LAB # 3  : C-Strings
*	CLASS    : CS1C
*	SECTION  : 6-10p T-Th
*	DUE DATE : 8/28/2014
*******************************************************************************/


#include "LabThree.h"

//Concatenation w/ c-string
void CharStrCat( char destination[], const char source[])
{
	int destSize = 0;
	int sourceSize = 0;

	while(destination[destSize] != '\0')
	{
		destSize++;
	}
	while(source[sourceSize] != '\0')
	{
		destination[destSize] = source[sourceSize];
		sourceSize++;
		destination++;
	}
}


//Concatenation w/ pointers
void CharStrCatPtr( char *ptrOne, char *ptrTwo)
{

	while(*ptrOne != '\0')
	{
		ptrOne++;
	}
	while(*ptrTwo!= '\0')
	{
		*ptrOne = *ptrTwo;
		ptrOne++;
		ptrTwo++;
	}
}

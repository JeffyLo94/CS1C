/*******************************************************************************
*	AUTHOR	 : Jeffrey Lo
*	STU ID#	 : 374780
*	LAB # 3  : C-Strings
*	CLASS    : CS1C
*	SECTION  : 6-10p T-Th
*	DUE DATE : 8/28/2014
*******************************************************************************/


#ifndef LABTHREE_H_
#define LABTHREE_H_

#include <string> // USED ONLY FOR OUTPUT HEADER FUNCTION
#include <iomanip>
#include <iostream>
using namespace std;

// N A M E S P A C E
namespace JeffreyLo
{
	// G L O B A L   C O N S T A N T S
	const string NAME 		= "Jeffrey Lo";
	const string CLASS 		= "CS1C";
	const string SECTION	= "T-Th 6:00p - 9:50p";
	const int    AS_NUM 	= 3;
	const string AS_NAME	= "C-Strings";
	const char   AS_TYPE	= 'L';
}

// FUNCTION OutputHeader
void OutputHeader(const string NAME,	// Holds the value of the name(s)
				  	  	  	  	  	  	// being output
				  const string CLASS,	// Holds the class
				  const string SECTION, // Holds the time and day of class
				  const int LAB_NUM,    // Holds the lab number
				  const string LAB_NAME,// Holds the lab name
				  char asType,			// Either L(lab), or A(assign)
				  ostream& out); 		// Used for output

// FUNCTION CharStrCat
void CharStrCat( char destination[], const char source[] );

void CharStrCatPtr( char *ptrOne, char *ptrTwo);


#endif /* LABTHREE_H_ */

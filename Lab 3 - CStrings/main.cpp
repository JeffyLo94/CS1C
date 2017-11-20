/*******************************************************************************
*	AUTHOR	 : Jeffrey Lo
*	STU ID#	 : 374780
*	LAB # 3  : C-Strings
*	CLASS    : CS1C
*	SECTION  : 6-10p T-Th
*	DUE DATE : 8/28/2014
*******************************************************************************/

#include "LabThree.h"
using namespace JeffreyLo;


/*******************************************************************************
 * C-Strings Concatenation
 * ----------------------------------------------------------------------------
 * This program performs two functions of concatenation, one of which uses
 * pointers.
 ******************************************************************************/
int main()
{
	char s1[] = "Test";
	char d1[100] = "Hello";

	char s2[] = "Hello";
	char d2[100] = "World";

	char *ptrOne;
	char *ptrTwo;

	ptrOne = d2;
	ptrTwo = s2;

	// Outputs Header
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	//CharStrCat - Concatenation w/ no pointer
	CharStrCat(d1,s1);

	//CharStrCatPtr - Concatenation with pointers
	CharStrCatPtr(ptrOne,ptrTwo);

	cout << left;
	cout << setw(30) << "Concatenation w/ No Pointer: " << d1 << endl;
	cout << setw(30) << "Concatenation w/ Pointer function: " << ptrOne << endl;
	cout << right;

	return 0;
}


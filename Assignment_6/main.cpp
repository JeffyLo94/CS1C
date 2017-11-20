/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #6 : Dynamic Array
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/30/2014
*******************************************************************************/

#include "AssignSix.h"
#include "DynArray.h"
using namespace JeffreyLo;

int main(int argc, char ** argv)
{
	const int MAX = 10;

	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	DynArray myDynamicAr(10);

	//Processing - changing array elements
	for(int index = 0; index < MAX; index++)
	{
		myDynamicAr.Store(index*10, index);
	}

	//Processing - printing array elements
	for(int index = 0; index < MAX; index++)
	{
		cout << index << " " << myDynamicAr.ValueAt(index) << endl;
	}

	//Processing - invoking CopyFrom method
	DynArray myOtherAr(5);
	myOtherAr.CopyFrom( myDynamicAr );

	//Processing - printing array elements
	for(int index = 0; index < MAX; index++)
	{
		cout << index << " " << myOtherAr.ValueAt(index) << endl;
	}

	//Processing - Checking outof bounds error message
	cout << endl;
	myOtherAr.Store(MAX, MAX+1);
	myDynamicAr.ValueAt(MAX + 1);

	//Output - prints two additional arguments if available
	if(argc > 1)
	{
		cout << endl << endl << *(argv+1) << " " << *(argv+2) << endl;
		cout << *(*(argv+1)+1) << " " << *(*(argv+2)+1) << endl << endl;
	}
	return 0;
}



/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	LAB # 7   : Pointers
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/4/2014
*******************************************************************************/



#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// G L O B A L   C O N S T A N T S
	/**************************************************************************
	 * Used for OutputHeader
	 * -----------------------------------------------------------------------
	 * NAME		-	Programmer Name
	 * CLASS	-	Class Name
	 * Section	-	Section Time
	 * AS_NUM	-	Assignment Number
	 * AS_NAME	-	Assignment Name
	 * AS_TYPE	-	Assignment Type
	 **************************************************************************/
	const string NAME 		= "Jeffrey Lo";
	const string CLASS 		= "CS1C";
	const string SECTION	= "T-Th 6:00p - 9:50p";
	const int    AS_NUM 	= 7;
	const string AS_NAME	= "Pointer Exercise";
	const char   AS_TYPE	= 'L';

	// Output - Header
	cout << left;
	cout << "**************************************************\n";
	cout << "* Programmed by : " << NAME << "\n";
	cout << "* " << setw(14) << "Student ID" << ": 374780";
	cout << "\n* " << setw(14) << CLASS << ": " << SECTION;
	if (toupper(AS_TYPE) == 'L')
	{
		cout << "\n* LAB #" << setw(9);
	}
	else
	{
		cout << "\n* ASSIGNMENT #" << setw(2);
	}
	cout << AS_NUM << ": " << AS_NAME;
	cout << "\n**************************************************\n";
	cout << right;

	cout << endl;

	/////// PART 1 ///////////////////////////////////////////

	int *int_ptr1;
	int *int_ptr2;

	int int_var = 100;

	//point int_ptr1 to int_var
	int_ptr1 = &int_var;

	//allocate memory from the heap (dynamically) and point int_ptr2 at it
	//store the value 200 in this memory
	int_ptr2 	= new int;
	*int_ptr2	= 200;

	cout << left
		 << setw(10) << "int_var: "   << int_var << endl
		 << setw(10) << "*int_ptr1: " << *int_ptr1 << endl
		 << setw(10) << "*int_ptr2: " << *int_ptr2 << endl
		 << endl;

	 //add 100 to the values pointed to by both int pointers
	*int_ptr1 += 100;
	*int_ptr2 += 100;

	 cout << setw(10) << "int_var: " << int_var << endl
		  << setw(10) << "*int_ptr1: " << *int_ptr1 << endl
		  << setw(10) << "*int_ptr2: " << *int_ptr2 << endl
		  << endl;

	 //delete all dynamically allocated memory in Part 1
	 delete int_ptr2;



	 /////// PART 2 ///////////////////////////////////////////

	 //dynamically allocate new memory from the heap for all 3 pointers
	 int_ptr1 = new int;
	 int_ptr2 = new int;
	 int *int_ptr3 = 0;
	 int_ptr3 = new int;

	 *int_ptr1 = 400;
	 *int_ptr2 = 500;
	 *int_ptr3 = 600;

	 cout << setw(10) << "int_var: " << int_var << endl
		  << setw(10) << "*int_ptr1: " << *int_ptr1 << endl
		  << setw(10) << "*int_ptr2: " << *int_ptr2 << endl
		  << setw(10) << "*int_ptr3: " << *int_ptr3 << endl
		  << endl;

	 //point all pointers to the same memory location
	 //  (the one pointed to by int_ptr1)
	 //make sure you don't leave allocated memory floating around
	 delete int_ptr2;
	 delete int_ptr3;
	 int_ptr2 = int_ptr1;
	 int_ptr3 = int_ptr2;

	 cout << setw(10) << "*int_ptr1: " << *int_ptr1 << endl
		  << setw(10) << "*int_ptr2: " << *int_ptr2 << endl
		  << setw(10) << "*int_ptr3: " << *int_ptr3 << endl
		  << endl;

	 //delete all dynamically allocated memory in part2
	 delete int_ptr1;

	 return 0;
}

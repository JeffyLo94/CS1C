/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #4 : Pointers
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/16/2014
*******************************************************************************/

#include "AssignFour.h"

int GetInt(const string PROMPT)
{
	// DECLARATIONS
	// Variables
	int           inputInt; // CALC - The integer entered by the user
	bool          invalid;  // CALC - Checks whether the integer that was
				            //        input is valid

	// Will loop until the user enters an INTEGER between the upper and
	// lower bounds
	do
	{
		invalid = false;
		cout << PROMPT;
		// If the user inputs anything besides a number,  they will receive
		// an error message and will have to re-enter their input
		if(!(cin >> inputInt))
		{
			cout << endl;
			cout << "**** Please input a NUMBER ****\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			invalid = true;
		}

		if(invalid)
		{
			cout << endl;
		}
	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << endl;

	return inputInt;
}

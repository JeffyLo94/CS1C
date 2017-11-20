/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*******************************************************************************/

#include "CheckYes.h"

/*******************************************************************************
 * FUNCTION CheckYes
 * ---------------------------------------------------------------------------
 *		This function takes in a string and checks if user really wants that
 *	string to be input.
 *	-> RETURNS: true or false
 ******************************************************************************/
bool CheckYes(string someName)
{
	bool isYes;
	bool invalid;
	char userInput;

	do
	{
		isYes 	= false;
		invalid = false;
		cout << "Are you sure " << someName << " is the name? (y/n) ";

		if(!(cin.get(userInput)))
		{
			cout << "\n****Please input y or n *****\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			invalid = true;
		}

		if(toupper(userInput) == 'Y')
		{
			isYes = true;
		}
	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return isYes;
}

/*******************************************************************************
 * FUNCTION CheckYes
 * ---------------------------------------------------------------------------
 *		This function takes in a int and checks if user really wants that
 *	integer to be input.
 *	-> RETURNS: true or false
 ******************************************************************************/
bool CheckYes(int someInt)
{
	bool isYes;
	bool invalid;
	char userInput;

	do
	{
		isYes 	= false;
		invalid = false;
		cout << "Are you sure it is " << someInt <<"? (y/n) ";

		if(!(cin.get(userInput)))
		{
			cout << "\n****Please input y or n *****\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			invalid = true;
		}

		if(toupper(userInput) == 'Y')
		{
			isYes = true;
		}
	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return isYes;
}


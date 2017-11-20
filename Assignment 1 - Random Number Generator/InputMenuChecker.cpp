/************************************************************************
 * Name    		: Jeffrey Lo
 * Date			: 8/24/2014
 * Course	  	: CS1C
 * Assignment 	: 1
 ************************************************************************/

#include "AssignOne.h"
#include <math.h>
using namespace AssignOne;

/**************************************************************************
 * FUNCTION GetAndCheckOneInt
 *------------------------------------------------------------------------
 *  This function retrieves the command that the user would like to run
 *  - returns inputInt -> The command the user would like to execute
 *------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		PROMPT     : String to prompt user with - Must be pre-defined
 * 		UP_BOUND   : Upper bound to check against input
 * 					 - Must be pre-defined
 * 		LOW_BOUND  : Lower bound to check against input
 * 					 - Must be pre-defined
 * POST-CONDITIONS
 * 		inputInt   : The number that the user entered is returned to main
 *************************************************************************/
int GetAndCheckOneInt(const string PROMPT,   // OUT  - String to prompt
											 //        user
					  const int    UP_BOUND, // CALC - Highest number the
											 //        input can be
					  const int    LOW_BOUND)// CALC - Lowest number the
											 //        input can be
{
	// DECLARATIONS
	// Variables
	int           inputInt; // CALC - The integer entered by the user
	bool          invalid;  // CALC - Checks whether the integer that was
				            //        input is valid
	string        errorMsg; // OUT  - First part of error message
	string        errorMsg2;// OUT  - Second part of error message

	// INITIALIZATIONS
	errorMsg  = "**** The number ";
	errorMsg2 = " is an invalid entry";

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
			cout << "**** Please input a NUMBER between "
				 << LOW_BOUND << " and "
				 << UP_BOUND  << " ****\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			invalid = true;
		}
		// If the user enters an integer that is not between the upper and
		// lower bounds, they will be given an error message and be asked
		// to re-enter their input
		else if(inputInt < LOW_BOUND || inputInt > UP_BOUND)
		{
			cout << endl;
			ErrorWordWrapping(errorMsg,
							  errorMsg2,
							  inputInt,
							  cout);

			cout << "**** Please input a number between "
				 << LOW_BOUND << " and "
				 << UP_BOUND  << " ****\n";
			invalid = true;
		}

		if(invalid)
		{
			cout << endl;
			// Displays the option menu
			DisplayMenu(cout); // OUT - Output stream
		}
	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << endl;

	return inputInt;
}


/**************************************************************************
 * FUNCTION ErrorWordWrapping
 *_________________________________________________________________________
 *  This function properly adjusts the error message if the user enters
 *  an extremely large number
 *  - returns nothing -> Formats the error message output
 *_________________________________________________________________________
 * PRE-CONDITIONS
 * 		errorMsg    : First part of error message - Must be predefined
 * 		errorMsg2   : Second part of error message - Must be predefined
 * 		inputInt    : Integer input by the user - Must be predefined
 *
 * POST-CONDITIONS
 * 		Outputs the error message with the proper formatting.
 *************************************************************************/
void ErrorWordWrapping(string   errorMsg, // OUT && CALC - First part of
										  // 			   error
					   string   errorMsg2,// OUT && CALC - Second part of
										  //  			   error
					   int      inputInt, // CALC        - Number entered
										  //               by user
					   ostream& os)       // OUT         - Output stream
{
	// Constants
	// MAX_LENGTH : Maximum amount of characters allowed per line
	const int MAX_LENGTH = 43;

	// Variables
	int    lineSize1;   // CALC - Length of the first error message
	int    lineSize2;   // CALC - Length of the second error message
	int    lineSizeFull;// CALC - Length of the whole message
	int    inputLength; // CALC - Length of the command issued by the user
	int    spaceLeft;   // CALC - Amount of space left in the line
	int    index;		// CALC - Used to add to the line
	string lineStr;		// CALC - String to add to the line
	int    lineStrSize;	// CALC - Length of the string to be added
	int    letterCount;	// CALC - Amount of letters added to the string

	// INITIALIZATIONS
	letterCount  = 0;
	inputLength  = 0;
	lineSize1    = errorMsg.size();
	lineSize2    = errorMsg2.size();
	lineSizeFull = 0;

	// Calculates the length of the command input by the user
	if(inputInt != 0)
	{
		inputLength = floor(log10(abs(inputInt))) + 1;
	}
	else
	{
		inputLength = 1;
	}

	lineSizeFull = lineSize1 + inputLength + lineSize2;

	if(lineSizeFull > MAX_LENGTH)
	{
		spaceLeft = MAX_LENGTH - (lineSize1 + inputLength);
		// Loops until the line runs out of space
		for(index = 0; index < spaceLeft; index++)
		{
			if(errorMsg2[index] != ' ')
			{
				lineStr = lineStr + errorMsg2[index];
				letterCount++;
			}
			else
			{
				lineStrSize = lineStr.size();
				if(lineSize1 + inputLength + lineStrSize + 1
				   > 40)
				{
					os << errorMsg << inputInt << ' ' << endl;
					os << errorMsg2.substr(++letterCount,
										   lineSize2 - letterCount)
					   << endl;
				}
				else
				{
					os << errorMsg << inputInt << ' ' << lineStr
					   << endl;
					os << errorMsg2.substr(++letterCount,
										   lineSize2 - letterCount)
					   << endl;
				}
			}
		}
	}
	else
	{
		// Changes the formatting for a command less than 0 being entered
		if(inputInt < 0)
		{
			os << errorMsg << inputInt << errorMsg2
			   << right    << setw(12 - inputLength - 1) << " ****\n";
		}
		else
		{
			os << errorMsg << inputInt << errorMsg2
			   << right    << setw(12 - inputLength) << " ****\n";
		}
	}
}

/**************************************************************************
 * FUNCTION DisplayMenu
 *------------------------------------------------------------------------
 *  This function will display the menu options.
 *  - returns nothing -> Will display the menu options
 *------------------------------------------------------------------------
 * PRE-CONDITION
 *		none
 * POST-CONDITIONS
 * 		Will display the menu options.
 *************************************************************************/
void DisplayMenu(ostream& os) // OUT - Output stream
{
	// Constants
	const int OUT_SIZE = 9;  // Holds the setw size

	// Output - Outputs the menu
	os << left;
	os << "Random Number Menu:\n";
	os << SUM_DIGITS 	  << setw(OUT_SIZE) << "-Sum the Digits\n";
	os << TRIP_NUM  	  << setw(OUT_SIZE) << "-Triple the Number\n";
	os << REVERSE_NUM     << setw(OUT_SIZE) << "-Reverse the Digits\n";
	os << RUN_ARRAY       << setw(OUT_SIZE) << "-Generate and Execute "
	   << "an Array\n";
	os << EXIT			  << setw(OUT_SIZE) << "-Exit Program\n";
	os << right;
}


/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	LAB # 5   : Inheritance - Cylinders
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/4/2014
*******************************************************************************/

#include "LabFive.h"
/*******************************************************************************
 * FUNCTION OutputHeader
 * ----------------------------------------------------------------------------
 * This function will output the header information to the console
 * ----------------------------------------------------------------------------
 * 	POST-CONDITIONS
 * 		Outputs Header to ostream specified in parameter
 ******************************************************************************/
void OutputHeader(const string NAME,	// Holds the value of the name(s)
				  	  	  	  	  	  	// being output
				  const string CLASS,	// Holds the class
				  const string SECTION, // Holds the time and day of class
				  const int LAB_NUM,    // Holds the lab number
				  const string LAB_NAME,// Holds the lab name
				  char asType,			// Either L(lab), or A(assign)
				  ostream& out)			// Used for output
{
	out << left;
	out << "**************************************************\n";
	out << "* Programmed by : " << NAME << "\n";
	out << "* " << setw(14) << "Student ID" << ": 374780";
	out << "\n* " << setw(14) << CLASS << ": " << SECTION;
	if (toupper(asType) == 'L')
	{
		out << "\n* LAB #" << setw(9);
	}
	else
	{
		out << "\n* ASSIGNMENT #" << setw(2);
	}
	out << LAB_NUM << ": " << LAB_NAME;
	out << "\n**************************************************\n";
	out << right;
}

/*******************************************************************************
 * FUNCTION DisplayMenu
 * ----------------------------------------------------------------------------
 * 		This function will display a menu
 ******************************************************************************/
void DisplayMenu(ostream& os)
{
	cout << left;
	cout << "Menu Options:\n";
	cout << SET_DIMENSIONS	<< ". Set Cylinder Dimensions\n"
		 << VOLUME 			<< ". Calculate Volume\n"
		 << SURF_AREA		<< ". Calculate Surface Area\n"
		 << GET_DIMENSIONS	<< ". Get Cylinder Dimensions\n"
		 << EXIT			<< ". Exit Program\n";
	cout << right;
}

/*******************************************************************************
 * FUNCTION GetInput
 * ----------------------------------------------------------------------------
 * 		This function will get and check an input based on the display menu
 ******************************************************************************/
int GetInput(const int UP_BOUND, const int LOW_BOUND)
{
	int 	inCommand;
	bool	invalid;

	do{
		invalid = false;

		DisplayMenu(cout);

		cout << "Please input command from menu: ";

		if(!(cin >> inCommand))
		{
			cout << endl;
			cout << "**** Please input a NUMBER between "
				 << LOW_BOUND << " and "
				 << UP_BOUND  << " ****\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			invalid = true;
		}
		else if(inCommand < LOW_BOUND || inCommand > UP_BOUND)
				{
					cout << "\nThe number " << inCommand
						 << " is an invalid entry.\n";
					cout << "**** Please input a number between "
						 << LOW_BOUND << " and "
						 << UP_BOUND  << " ****\n\n";
					invalid = true;
				}
	}while(invalid);

	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << endl;

	return inCommand;
}

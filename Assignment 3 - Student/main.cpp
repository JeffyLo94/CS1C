/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #3 : Students
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/9/2014
*******************************************************************************/

#include "AssignThree.h"
#include "CS1CStudent.h"
using namespace JeffreyLo;

int main()
{
	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	CS1CStudent csStudent("Alberto Pujols", 668899, "949-665-1234", 35,
			 'M', FRESHMAN, 3.3, true, 778899, 5, 12, 2016);
	Student 	someStudent("Mike Trout", 778899, "949-555-1234", 22, 'M', FRESHMAN, 4.0);
	char		input;
	int			studOutCount = 0;
	string		someName;
	int			someAge;
	string		somePhone;
	int			someId;
	bool		pythonKnow;
	int			someScore;
	int			month;
	int			day;
	int			year;

	//Generate Students

	cout << "Generating Student w/ overloaded constructor: Mike Trout... \n\n";


	cout << "Student Info: " << endl;
	someStudent.PrintAll(cout);

	//Loops through other student iterations and changes the student class
	while(studOutCount < 3)
	{
		do{
			cout << "\nChange Student? (y/n): ";
			cin.get(input);
			cin.ignore(1000,'\n');
			if(toupper(input) != 'Y' && toupper(input) != 'N')
			{
				cout << "Please input Y or N\n";
			}
		}while(toupper(input) != 'Y' && toupper(input) != 'N');

		if(toupper(input) == 'Y')
		{
			switch(studOutCount)
			{
			case 0:
				cout << "\n\nGenerating Student: Miguel Cabrera... \n\n";
				someStudent.SetAll("Miguel Cabrera", 456789, "248-555-5555", 29,
								   'M', SOPHOMORE, 3.33);

				cout << "Student Info: " << endl;
				someStudent.PrintAll(cout);
				break;
			case 1:
				cout << "\n\nGenerating Student: Bill O'Reilly... \n\n";
				someStudent.SetAll("Bill O'Reilly", 87654, "703-703-1234", 57,
								   'M', SOPHOMORE, 3.8);

				cout << "Student Info: " << endl;
				someStudent.PrintAll(cout);

				break;
			case 2:
				cout << "\n\nGenerating Student: Oprah Winfrey... \n\n";
				someStudent.SetAll("Oprah Winfrey", 777744, "213-555-6789", 50,
								   'F', FRESHMAN, 3.23);

				cout << "Student Info: " << endl;
				someStudent.PrintAll(cout);
				break;
			}
		}
		studOutCount++;

	}

	//Generate CS Students

	cout << "\n\nProceeding to CS1C Students (enter to continue): ";
	cin.ignore(1000,'\n');


	//Generates with overloaded
	cout << "\n\nGenerating CS Student w/ overloaded constructor: "
		 << "Alberto Pujols... \n\n";


	cout << "Student Info: " << endl;
	csStudent.PrintAll(cout);

	studOutCount = 0;

	//Loops through other student iterations and changes the csStudent class
	while(studOutCount < 2)
	{
		do{
			cout << "\nChange CS Student? (y/n): ";
			cin.get(input);
			cin.ignore(1000,'\n');
			if(toupper(input) != 'Y' && toupper(input) != 'N')
			{
				cout << "Please input Y or N\n";
			}
		}while(toupper(input) != 'Y' && toupper(input) != 'N');

		if(toupper(input) == 'Y')
		{
			switch(studOutCount)
			{
			case 0:
				cout << "\n\nGenerating CS Student: Clayton Kershaw... \n\n";
				csStudent.SetAll("Clayton Kershaw", 156789, "248-555-6543", 29,
								   'M', SOPHOMORE, 2.5, false, 456789,
								   5, 11, 2015);

				cout << "Student Info: " << endl;
				csStudent.PrintAll(cout);
				break;
			case 1:
				cout << "\n\nGenerating CS Student: Jim Rome... \n\n";
				csStudent.SetAll("Jim Rome", 87654, "703-703-7654", 40,
								   'M', SOPHOMORE, 3.2, true, 87654,
								   5, 11, 2015);

				cout << "Student Info: " << endl;
				csStudent.PrintAll(cout);

				break;
			}
			studOutCount++;
		}
	}


	// Testing Setter Methods

	cout << "\n\nProceeding to Test Changing data members... \n\n";

	cout << "Before Changes:\n";
	csStudent.PrintAll(cout);

	for(int count = 0; count < 7; count++)
	{
		switch(count)
		{
		case 0: cout << "\nChange Name: ";
				getline(cin, someName);
				csStudent.SetName(someName);
				break;
		case 1: cout << "Change Age: ";
				cin >> someAge;
				cin.ignore(1000, '\n');
				csStudent.SetAge(someAge);
				break;
		case 2: cout << "Change Phone: ";
				getline(cin, somePhone);
				csStudent.SetPhone(somePhone);
				break;
		case 3: cout << "Change Student ID: ";
				cin >> someId;
				cin.ignore(1000, '\n');
				csStudent.SetId(someId);
				break;
		case 4: cout << "Change Total Score: ";
				cin >> someScore;
				cin.ignore(1000, '\n');
				csStudent.SetTotScore(someScore);
				break;
		case 5:
				do{
					cout << "Does student know python? (y/n):";
					cin.get(input);
					cin.ignore(1000,'\n');
					if(toupper(input) != 'Y' && toupper(input) != 'N')
					{
						cout << "Please input Y or N\n";
					}
				}while(toupper(input) != 'Y' && toupper(input) != 'N');

				if(toupper(input) == 'Y')
				{
					pythonKnow = true;
				}
				else
				{
					pythonKnow = false;
				}
				csStudent.SetKnowPython(pythonKnow);
				break;
		case 6: cout << "Change Grad Date:\n";
				cout << "Input Month: ";
				cin >> month;
				cout << "Input Day: ";
				cin >> day;
				cout << "Input Year:";
				cin >> year;
				csStudent.SetGradDate(month, day, year);
				break;
		}
	}

	cout << "\n\nAfter Changes:\n";
	csStudent.PrintAll(cout);

	cout << "\n\nTesting Complete";
	return 0;
}

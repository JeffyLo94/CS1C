/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #7 : Virtual Functions
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/9/2014
*******************************************************************************/

#include "AssignSeven.h"
#include "MathStudent.h"
#include "CS1CStudent.h"
using namespace JeffreyLo;

//P R O T O T Y P E S
void CallPrint(Student& someStud);

int main()
{
	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	cout << "Creating Math Student..." << endl;
	MathStudent mathStudent("Joe Calculus", 668888, "949-555-1234", 23, 'M',
							FRESHMAN, 3.3, "1234 Main", "Laguna Niguel", "CA",
							92677);
	cout << "Creating CS1C Student..." << endl;
	CS1CStudent csStudent("Alberto Pujols", 668899, "949-665-1234", 35,
						  'M', FRESHMAN, 3.3, true, 778899, 5, 12, 2016);
	cout << "Creating Student..." << endl;
	Student 	regStudent("Mike Trout", 778899, "949-555-1234", 22, 'M',
							FRESHMAN, 4.0);
	cout << "Printing math student..." << endl;
	CallPrint(mathStudent);
	cout << "Printing cs student..." << endl;
	CallPrint(csStudent);
	cout << "Printing normal student..." << endl;
	CallPrint(regStudent);

	cout << "Testing Finished!" << endl;
	return 0;
}

// F U N C T I O N S
void CallPrint(Student& someStud)
{
	cout << "PrintAll Called\n";
	someStud.PrintAll(cout);
	cout << endl;
}

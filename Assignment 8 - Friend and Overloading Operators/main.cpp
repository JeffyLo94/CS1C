/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #8 : Friend Functions and Overloaded Operators
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/14/2014
*******************************************************************************/

#include "AssignEight.h"
#include "MathStudent.h"
#include "CS1CStudent.h"
using namespace JeffreyLo;

//P R O T O T Y P E S
void CallPrint(Student& someStud);
void TestEquality(const Student& objectOne, const Student& objectTwo);

int main()
{
	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	cout << "Creating Math Student..." << endl;
	MathStudent mathStudent("Joe Calculus", 668888, "949-555-1234", 23, 'M',
							FRESHMAN, 3.3, "1234 Main", "Laguna Niguel", "CA",
							92677);
	cout << "Creating 1st CS1C Student..." << endl;
	CS1CStudent csStudent("Alberto Pujols", 668899, "949-665-1234", 35,
						  'M', FRESHMAN, 3.3, true, 778899, 5, 12, 2016);
	cout << "Creating 2nd CS1C Student..." << endl;
	CS1CStudent csStudentTwo("Alberta Pujols", 123456, "949-665-1234", 35,
						  'M', FRESHMAN, 3.3, true, 778899, 5, 12, 2016);
	cout << "Creating Student..." << endl;
	Student 	regStudent("Mike Trout", 778899, "949-555-1234", 22, 'M',
							FRESHMAN, 4.0);

	// Friend Function Test
	cout << "\nTesting Friend Function:\n";
	cout << "Are CS and Math Student Equal? ";
	TestEquality(csStudent, mathStudent);

	cout << "Changing ID of Math Student to 668899..." << endl;
	mathStudent.SetId(668899);

	cout << "Are CS and Math Student Equal now? ";
	TestEquality(csStudent, mathStudent);

	// Testing Overloaded Equality Operator
	cout << "\nTesting Equality Operator:\n";
	cout << "Are both CS Students' Ids equal? ";
	cout << (csStudent == csStudentTwo?
				"Equal\n" : "Unequal\n");

	cout << "Changing ID of 2nd CS student 668899..." << endl;
	csStudentTwo.SetId(668899);

	cout << "Are both CS Students equal now? ";
	cout << (csStudent == csStudentTwo?
				"Equal\n" : "Unequal\n");

	// Testing Addition Method
	cout << "\nTesting Addition Method:\n";
	cout << "Current CS Student One Age: " << csStudent.GetAge() << endl;
	csStudent.AddAge(5);
	cout << "Adding to age by 5: " << csStudent.GetAge() << endl;

	// Testing Addition Operator Overload;
	cout << "\nTesting Addition Operator:\n";
	cout << "Current CS Student Two Age: " << csStudentTwo.GetAge() << endl;
	csStudentTwo + 5 ;
	cout << "Adding to age by 5: " << csStudentTwo.GetAge() << endl;

	cout << "\nTesting Finished!" << endl;
	return 0;
}

// F U N C T I O N S
void CallPrint(Student& someStud)
{
	cout << "PrintAll Called\n";
	someStud.PrintAll(cout);
	cout << endl;
}

void TestEquality(const Student& objectOne, const Student& objectTwo)
{
	(isEqual(objectOne,objectTwo)?
			cout << "True" << endl :
			cout << "False" << endl);
}

/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #5 : Math Students
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/23/2014
*******************************************************************************/

#include "AssignFive.h"
#include "MathStudent.h"
using namespace JeffreyLo;

//P R O T O T Y P E S
MathStudent PassByCopy(MathStudent someStudent);
MathStudent& PassByRef(MathStudent &someStudent);

int main()
{
	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	cout << "Creating Student 1:" << endl << endl;
	MathStudent Student1("Joe Calculus", 668888, "949-555-1234", 23, 'M',
						 FRESHMAN, 3.3, "1234 Main", "Laguna Niguel", "CA",
						 92677);
	Student1.PrintAll(cout);
	cout << endl << endl << endl;

//	cout << "Creating Student 2:" << endl << endl;
//	MathStudent Student2("Mary Algebra", 777777, "248-555-1234", 23, 'M',
//						 SOPHOMORE, 3.5, "3333 Marguerite", "Mission Viejo",
//						 "CA", 92646);
//	Student2.PrintAll(cout);
//	cout << endl << endl;

	cout << "Student2 created with Initialization Construct:" << endl;
	MathStudent Student2 = Student1;
	Student2.PrintAll(cout);
	cout << endl << endl << endl;

	cout << "Student 1 changed with SetAll method..." << endl << endl;
	Student1.SetAll("Mary Algebra", 777777, "248-555-1234", 23, 'M',
					 SOPHOMORE, 3.5, "3333 Marguerite", "Mission Viejo",
					 "CA", 92646);

	cout << "Outputting Student 1 and Student 2 to prove copy constructor was"
		 << " a deep copy:" << endl << endl;
	cout << "Student1:" << endl;
	Student1.PrintAll(cout);
	cout << endl << "Student2:" << endl;
	Student2.PrintAll(cout);
	cout << endl << endl << endl;

	cout << "Student3 created w/ Default Constructor: " << endl;
	MathStudent Student3;
	Student3.PrintAll(cout);
	cout << endl;

	cout << "Student3 modified with deep copy method using Student1: " << endl;
	Student3.copyFrom(Student1);
	Student3.PrintAll(cout);
	cout << endl << endl << endl;

	cout << "Testing Passing and Returning by Copy Methods with student3"
		 << endl << endl;
	PassByCopy(Student3);
	cout << endl;
	PassByRef(Student3);
	cout << endl;
	cout << "Showing Student 3 remains unchanged: " << endl;
	Student3.PrintAll(cout);
	cout << endl << endl;


	cout << "Testing Finished!" << endl;
	return 0;
}

// F U N C T I O N S
MathStudent PassByCopy(MathStudent someStudent)
{
	cout << "Passing and Returning by copy" << endl;
	return someStudent;
}

MathStudent& PassByRef(MathStudent& someStudent)
{
	cout << "Passing and Returning by reference" << endl;
	return someStudent;
}

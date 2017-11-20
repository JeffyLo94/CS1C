/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #5 : Math Students
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/23/2014
*******************************************************************************/

#include "MathStudent.h"

//Default Constructor
MathStudent::MathStudent(): address(NULL), city(NULL), state(NULL), zipCode(0)
{
	cout << "Default Constructor Called" << endl;
}

//Overloaded Constructor
MathStudent::MathStudent(string 	studName,
						 int 		studId,
						 string 	studPhone,
						 int 		studAge,
						 char 		studGend,
						 studClass 	studGrade,
						 double 	studGpa,
						 string 		studAddress,
						 string 		studCity,
						 string 		studState,
						 int 		studZip)
{
	cout << "Overloaded Constructor Called" << endl;
	SetAll(studName, studId, studPhone, studAge, studGend, studGrade,
		   studGpa, studAddress, studCity, studState, studZip);
}

//Deconstructor
MathStudent::~MathStudent()
{
	cout << "Deconstructor Called" << endl;
	delete [] address;
	delete [] city;
	delete [] state;
}

//Copy Constructor
MathStudent::MathStudent(const MathStudent &someMathStud)
{
	address = NULL;
	city = NULL;
	state = NULL;
	SetAll(someMathStud.GetName(), someMathStud.GetId(),
		   someMathStud.GetPhone(), someMathStud.GetAge(),
		   someMathStud.GetGender(), someMathStud.GetClass(),
		   someMathStud.GetGpa(), someMathStud.GetAddress(),
		   someMathStud.GetCity(), someMathStud.GetState(),
		   someMathStud.GetZip());
	cout << "Copy Constructor Called" << endl;
}

//Mutators
void MathStudent::copyFrom(MathStudent someMathStud)
{
//	delete [] address;
//	delete [] city;
//	delete [] state;
	SetAll(someMathStud.GetName(), someMathStud.GetId(),
		   someMathStud.GetPhone(), someMathStud.GetAge(),
		   someMathStud.GetGender(), someMathStud.GetClass(),
		   someMathStud.GetGpa(), someMathStud.GetAddress(),
		   someMathStud.GetCity(), someMathStud.GetState(),
		   someMathStud.GetZip());
}

void MathStudent::SetAll(string 	studName,
						 int 		studId,
						 string 	studPhone,
						 int 		studAge,
						 char 		studGend,
						 studClass 	studGrade,
						 double 	studGpa,
						 string 		studAddress,
						 string 		studCity,
						 string 		studState,
						 int 		studZip)
{
	Student::SetAll(studName, studId, studPhone, studAge,
					studGend, studGrade, studGpa);
	SetAddress(studAddress);
	SetCity(studCity);
	SetState(studState);
	SetZip(studZip);
}

void MathStudent::SetAddress(string studAddress)
{
	if(address != NULL)
		delete [] address;

	address = new char[studAddress.length()+1];
//	cout << strlen(studAddress)+1;
	strcpy(address, studAddress.c_str());
}

void MathStudent::SetCity(string studCity)
{
	if(city != NULL)
		delete [] city;

	city = new char[studCity.length()+1];
	strcpy(city, studCity.c_str());
}

void MathStudent::SetState(string studState)
{
	if(state != NULL)
		delete [] state;

	state = new char[studState.length()+1];
	strcpy(state, studState.c_str());
}

void MathStudent::SetZip(int studZip)
{
	zipCode = studZip;
}


// Accessors
void MathStudent::PrintAll(ostream& os) const
{
	Student::PrintAll(os);
	os << left;
	if(address != NULL)
		os << setw(20) << "Student Address:"	<< address	<< endl;
	else
		os << setw(20) << "Student Address:"	<< "Unknown"<< endl;
	if(city != NULL)
		os << setw(20) << "Student City: " 		<< city 	<< endl;
	else
		os << setw(20) << "Student City: " 		<< "Unknown"<< endl;
	if(state != NULL)
		os << setw(20) << "Student State: "		<< state	<< endl;
	else
		os << setw(20) << "Student State: "		<< "Unknown"<< endl;
	os << setw(20) << "Student ZipCode " 	<< zipCode	<< endl;
	os << right;
}

char* MathStudent::GetAddress() const
{
	return address;
}

char* MathStudent::GetCity() const
{
	return city;
}

char* MathStudent::GetState() const
{
	return state;
}

int MathStudent::GetZip() const
{
	return zipCode;
}

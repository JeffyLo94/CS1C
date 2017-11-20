/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #3 : Students
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/9/2014
*******************************************************************************/

#include "StudentClass.h"

// Default Constructor
Student::Student()
{
	name	 = " ";
	id		 = 0;
	phoneNum = "000-000-0000";
	age		 = 0;
	gender	 = 'U';
	grade	 = UNKNOWN;
	gpa		 = 0.0;
}

// Non-Default Constructor
Student::Student(string 	studName,
				 int 		studId,
				 string 	studPhone,
				 int 		studAge,
				 char 		studGend,
				 studClass 	studGrade,
				 double 	studGpa)
{
	SetAll(studName, studId, studPhone, studAge, studGend, studGrade, studGpa);
}

// Destructor
Student::~Student()
{
}

// M U T A T O R S

void Student::SetAll(string 	studName,
					 int 		studId,
					 string 	studPhone,
					 int 		studAge,
					 char 		studGend,
					 studClass 	studGrade,
					 double 	studGpa)
{
	SetName(studName);
	SetId(studId);
	SetPhone(studPhone);
	SetAge(studAge);
	SetGender(studGend);
	SetClass(studGrade);
	SetGpa(studGpa);
}

void Student::SetName(string studName)
{
	name = studName;
}

void Student::SetId(int studId)
{
	id = studId;
}

void Student::SetPhone(string studPhone)
{
	phoneNum = studPhone;
}

void Student::SetAge(int studAge)
{
	age = studAge;
}

void Student::SetGender(char studGender)
{
	if(toupper(studGender) == 'M' || toupper(studGender) == 'F')
	{
		gender = toupper(studGender);
	}
	else
	{
		gender = 'U';
	}
}

void Student::SetClass(studClass studGrade)
{
	grade = studGrade;
}

void Student::SetGpa(double studGpa)
{
	gpa = studGpa;
}

// A C C E S S O R S
string Student::GetName() const
{
	return name;
}

int Student::GetId() const
{
	return id;
}

string Student::GetPhone() const
{
	return phoneNum;
}

int Student::GetAge() const
{
	return age;
}

char Student::GetGender() const
{
	return gender;
}

studClass Student::GetClass() const
{
	return grade;
}

double Student::GetGpa() const
{
	return gpa;
}

void Student::PrintAll(ostream& os) const
{
	os << left;
	os << setw(20) << "Student Name: "		<< name 	<< endl;
	os << setw(20) << "Student ID: "		<< id 		<< endl;
	os << setw(20) << "Student Phone: "		<< phoneNum << endl;
	os << setw(20) << "Student Age: "		<< age 		<< endl;
	os << setw(20) << "Student Gender: ";
	if (toupper(gender) != 'M' && toupper(gender) != 'F')
	{
		os << "Undefined" 	<< endl;
	}
	else if (toupper(gender) == 'M')
	{
		os << "Male" << endl;
	}
	else
	{
		os << "Female" << endl;
	}
	os << setw(20) << "Student Standing: ";
	switch(grade)
	{
		case FRESHMAN: 	os << "Freshman";
						break;
		case SOPHOMORE:	os << "Sophomore";
						break;
		case JUNIOR:	os << "Junior";
						break;
		case SENIOR:	os << "Senior";
						break;
		case UNKNOWN:
		default:		os << "Unknown Grade";
	}
	os << endl;
	os << setw(20) << "Student GPA: "		<< fixed 	<< setprecision(2)
	   << gpa 	   << endl;
	os << right;
}

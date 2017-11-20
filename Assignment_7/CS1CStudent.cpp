/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #7 : Virtual Functions
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/9/2014
*******************************************************************************/
#include "CS1CStudent.h"

//Constructor
CS1CStudent::CS1CStudent() : knowsPython(false), totScore(0)
{
}

//Overloaded Constructor
CS1CStudent::CS1CStudent(string 	studName,
						 int 		studId,
						 string 	studPhone,
						 int 		studAge,
						 char 		studGend,
						 studClass 	studGrade,
						 double 	studGpa,
						 bool		python,
						 int		studScores,
						 int		gradMonth,
						 int		gradDay,
						 int		gradYear)
{
	SetAll(studName, studId, studPhone, studAge, studGend, studGrade, studGpa,
		   python, studScores, gradMonth, gradDay, gradYear);
}

//Destructor
CS1CStudent::~CS1CStudent()
{
}

// M U T A T O R S

void CS1CStudent::SetAll(string 	studName,
						 int 		studId,
						 string 	studPhone,
						 int 		studAge,
						 char 		studGend,
						 studClass 	studGrade,
						 double 	studGpa,
						 bool		hasPython,
						 int		studScores,
						 int		gradMonth,
						 int		gradDay,
						 int		gradYear)
{
	Student::SetAll(studName, studId, studPhone, studAge,
					studGend, studGrade, studGpa);
	SetKnowPython(hasPython);
	SetTotScore(studScores);
	SetGradDate(gradMonth, gradDay, gradYear);
}

void CS1CStudent::SetKnowPython(bool hasPython)
{
	knowsPython = hasPython;
}

void CS1CStudent::SetTotScore(int studScores)
{
	totScore = studScores;
}

void CS1CStudent::SetGradDate(int gradMonth,
							  int gradDay,
							  int gradYear)
{
	gradDate.SetAll(gradMonth, gradDay, gradYear);
}

// A C C E S S O R S

bool CS1CStudent::GetKnowPython() const
{
	return knowsPython;
}

int CS1CStudent::GetTotScore() const
{
	return totScore;
}

string CS1CStudent::GetGradDate() const
{
	return gradDate.ToString();
}

void CS1CStudent::PrintAll(ostream& os) const
{
	Student::PrintAll(os);
	os << left;
	os << setw(20) << "Assignment Score: "	<< totScore << endl;
	os << setw(20) << "Python Knowledge: ";
	if(knowsPython)
	{
		os << "Yes" << endl;
	}
	else
	{
		os << "No" << endl;
	}
	os << setw(20) << "Graduation Date: "	<< GetGradDate() << endl;
	os << right;
}

/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #7 : Virtual Functions
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/9/2014
*******************************************************************************/

#ifndef MATHSTUDENT_H_
#define MATHSTUDENT_H_

#include "StudentClass.h"
#include <iostream>

class MathStudent : public Student
{
public:
	MathStudent();
	MathStudent(string 		studName,
				int 		studId,
				string 		studPhone,
				int 		studAge,
				char 		studGend,
				studClass 	studGrade,
				double 	  	studGpa,
				string 		studAddress,
				string 		studCity,
				string 		studState,
				int 		studZip); // constructor
	~MathStudent();
	MathStudent(const MathStudent &someMathStud);//copy constructor

	//Mutators
	void copyFrom(MathStudent someMathStud); // deep copy operation
	void SetAll(string 		studName,
				int 		studId,
				string 		studPhone,
				int 		studAge,
				char 		studGend,
				studClass 	studGrade,
				double 	  	studGpa,
				string 		studAddress,
				string 		studCity,
				string 		studState,
				int 		studZip);
	void SetAddress(string studAddress);
	void SetCity(string studCity);
	void SetState(string studState);
	void SetZip(int studZip);

	//Accessors
	void PrintAll(ostream & os)	const;
	char* GetAddress()	const;
	char* GetCity()		const;
	char* GetState()	const;
	int   GetZip()		const;


private:
	char* address;
	char* city;
	char* state;
	int	  zipCode;
};



#endif /* MATHSTUDENT_H_ */

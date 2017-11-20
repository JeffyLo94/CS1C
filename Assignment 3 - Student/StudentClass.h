/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #3 : Students
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/9/2014
*******************************************************************************/

#ifndef STUDENTCLASS_H_
#define STUDENTCLASS_H_

#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

// E N U M S
enum studClass
{
	UNKNOWN,
	FRESHMAN,
	SOPHOMORE,
	JUNIOR,
	SENIOR
};


// O B J E C T S
class Student
{
	public:
		Student();
		Student(string 		studName,
				int 		studId,
				string 		studPhone,
				int 		studAge,
				char 		studGend,
				studClass 	studGrade,
				double 	  	studGpa);
		~Student();

		//Mutators
		void SetAll(string 		studName,
					int 		studId,
					string 		studPhone,
					int 		studAge,
					char 		studGend,
					studClass 	studGrade,
					double 	  	studGpa);
		void SetName(string studName);
		void SetId(int studId);
		void SetPhone(string studPhone);
		void SetAge(int studAge);
		void SetGender(char studGend);
		void SetClass(studClass studGrade);
		void SetGpa(double studGpa);

		//Accessors
		string 		GetName() 				const;
		int			GetId()					const;
		string		GetPhone()				const;
		int			GetAge()				const;
		char		GetGender()				const;
		studClass	GetClass()				const;
		double		GetGpa()				const;
		void		PrintAll(ostream& os)	const;

	private:
		string 		name;
		int			id;
		string		phoneNum;
		int			age;
		char		gender;
		studClass	grade;
		double		gpa;
};



#endif /* STUDENTCLASS_H_ */

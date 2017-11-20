/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #3 : Students
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/9/2014
*******************************************************************************/

#ifndef CS1CSTUDENT_H_
#define CS1CSTUDENT_H_

#include "StudentClass.h"
#include "Date.h"

class CS1CStudent : public Student
{
	public:
		CS1CStudent();
		CS1CStudent(string 		studName,
					int 		studId,
					string 		studPhone,
					int 		studAge,
					char 		studGend,
					studClass 	studGrade,
					double 	  	studGpa,
					bool		python,
					int			studScores,
					int			gradMonth,
					int			gradDay,
					int			gradYear);
		~CS1CStudent();

		//Mutators
		void SetAll(string 		studName,
					int 		studId,
					string 		studPhone,
					int 		studAge,
					char 		studGend,
					studClass 	studGrade,
					double 	  	studGpa,
					bool		hasPython,
					int			studScores,
					int			gradMonth,
					int			gradDay,
					int			gradYear);
		void SetKnowPython(bool hasPython);
		void SetTotScore(int studScores);
		void SetGradDate(int gradMonth,
						 int gradDay,
						 int gradYear);

		//Accessors
		bool 	GetKnowPython()			const;
		int		GetTotScore()			const;
		string	GetGradDate()			const;
		void	PrintAll(ostream& os)	const;

	private:
		bool 	knowsPython;
		int		totScore;
		Date 	gradDate;
};



#endif /* CS1CSTUDENT_H_*/

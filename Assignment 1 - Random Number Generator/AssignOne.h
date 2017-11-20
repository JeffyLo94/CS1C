/************************************************************************
 * Name    		: Jeffrey Lo
 * Date			: 8/24/2014
 * Course	  	: CS1C
 * Assignment 	: 1
 ************************************************************************/

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <sstream>
#include <fstream>
#include <limits>
using namespace std;

// N A M E S P A C E S
namespace AssignOne
{
	// G L O B A L  C O N S T A N T S
	const int AR_SIZE = 10;
	const int UP_BOUND = 4;
	const int LOW_BOUND = 0;

	// T Y P E D E F S  &  E N U M S
	//RandArrayType - an array of 10 elements to hold 10 random values
	typedef int RandArrayType[AR_SIZE];

	//menuOptions - Enum for the menu options
	enum menuOptions
	{
		EXIT,
		SUM_DIGITS,
		TRIP_NUM,
		REVERSE_NUM,
		RUN_ARRAY
	};
}

// F U N C T I O N S
/**********************************************************************
 * FUNCTION ReadArray
 * -------------------------------------------------------------------
 *  Reads a integers from a specifed file and stores the numbers into
 *  an array
 *********************************************************************/
void ReadArray(string fileName,
			   AssignOne::RandArrayType targetAr,
			   const int ARRAY_SIZE);

/**********************************************************************
 * FUNCTION InsertionSort - Sorts an array with insertion algorithm
 *********************************************************************/
void InsertionSort(AssignOne::RandArrayType targetAr,
				   const int ARRAY_SIZE);

/**********************************************************************
 * FUNCTION PrintArray - prints array to output stream
 *********************************************************************/
void PrintArray(ostream& outArea,
				AssignOne::RandArrayType targetAr,
				const int ARRAY_SIZE);

/**********************************************************************
 * FUNCTION PrintToFile - Prints array to a file specified
 *********************************************************************/
void PrintToFile(string fileName,
				 AssignOne::RandArrayType targetAr,
				 const int ARRAY_SIZE);

/**********************************************************************
 * FUNCTION CreateArray
 *--------------------------------------------------------------------
 *  This function will create an array of 10 random numbers
 *--------------------------------------------------------------------
 *********************************************************************/
void CreateArray(AssignOne::RandArrayType targetAr,
		   	   	 const int ARRAY_SIZE);

/**********************************************************************
 * FUNCTION GetAndCheckOneInt
 *---------------------------------------------------------------------
 *  This function retrieves the command that the user would like to run
 *  - returns inputInt -> The command the user would like to execute
 *---------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		PROMPT     : String to prompt user with - Must be pre-defined
 * 		UP_BOUND   : Upper bound to check against input
 * 					 - Must be pre-defined
 * 		LOW_BOUND  : Lower bound to check against input
 * 					 - Must be pre-defined
 * POST-CONDITIONS
 * 		inputInt   : The number that the user entered is returned to
 * 		 main
 *********************************************************************/
int GetAndCheckOneInt(const string PROMPT,    // OUT - String to prompt
											  //        user
					  const int    UP_BOUND,  // CALC - Highest number
											  //       the input can be
					  const int    LOW_BOUND);// CALC - Lowest number
											  //       the input can be

/**********************************************************************
 * FUNCTION ErrorWordWrapping
 *--------------------------------------------------------------------
 *  This function properly adjusts the error message if the user enters
 *  an extremely large number
 *  - returns nothing -> Formats the error message output
 *--------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		errorMsg    : First part of error message - Must be predefined
 * 		errorMsg2   : Second part of error message - Must be predefined
 * 		inputInt    : Integer input by the user - Must be predefined
 *
 * POST-CONDITIONS
 * 		Outputs the error message with the proper formatting.
 *********************************************************************/
void ErrorWordWrapping(string   errorMsg, // OUT && CALC - First part
										  // 			   of error
					   string   errorMsg2,// OUT && CALC - Second part
										  //  			    of error
					   int      inputInt, // CALC        - Number entered
										  //               by user
					   ostream& os);       // OUT         - Output stream

/**********************************************************************
 * FUNCTION DisplayMenu
 *--------------------------------------------------------------------
 *  This function will display the menu options.
 *  - returns nothing -> Will display the menu options
 *--------------------------------------------------------------------
 * PRE-CONDITION
 *		none
 * POST-CONDITIONS
 * 		Will display the menu options.
 *********************************************************************/
void DisplayMenu(ostream& os); // OUT - Output stream

// O B J E C T S
/*********************************************************************
 * OBJECT RandNum
 * ------------------------------------------------------------------
 * Object containing all attributes and methods to influence the
 * random number. Methods include setters and getters for generating
 * the random value, reversing the value, and summing the digits
 ********************************************************************/
class RandNum
{
	public:
		// Constructor & Destructor
		RandNum();
		~RandNum();

		// Setters
		void   SetAll();
		void   SetRandNum();
		void   SetString(int origValue);
		void   SetDigits();
		void   SetReverseNum();

		//Getters
		int    GetRandNum() 	const;
		string GetRandNumStr()  const;
		int    GetReverseNum()  const;
		int    GetDigitSum() 	const;
		int    GetTriple() 	const;

	private:
		int 	value; 		//Holds the random number value
		string 	valueStr;	//Holds the random number as a string
		int		reverse;	//Holds the random number reversed
		int 	hundsDigit;	//Holds the hundreds place digit
		int		tensDigit;	//Holds the tens place digit
		int		onesDigit;	//Holds the ones place digit
};

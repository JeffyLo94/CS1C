/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #7 : Virtual Functions
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/9/2014
*******************************************************************************/

#include "Date.h"

//Constructors

/**************************************************************************
* Method Date
*--------------------------------------------------------------------------
*	This method is the default constructor.
* RETURNS: nothing
* -> Initializes data in Date object
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		None
*
* POST-CONDITIONS
* 		Date object attributes will be updated with default values
**************************************************************************/
Date::Date()
{
	//Processing - initializing object attributes to default values
	month = 0;
	day   = 0;
	year  = 0;
}

/**************************************************************************
* Method Date
*--------------------------------------------------------------------------
*	This method is another constructor that will initialize the Date object
*	attributes to the parameter values passed in
* RETURNS: nothing
* -> sets variables in method to a value
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		newMonth   : the new month must be predefined
* 		newDay	   : the new day must be predefined
* 		newYear	   : the new year must be predefined
*
* POST-CONDITIONS
* 		Date object attributes will be updated with values defined in the
* 		passed parameters
**************************************************************************/
Date::Date(int newMonth, //IN - month value to update to
		   int newDay,   //IN - day value to update to
		   int newYear)  //IN - year value to update to
{
	//Processing - initializing object attributes to defined values
	SetAll(newMonth, newDay, newYear);
}

/**************************************************************************
* Method Destructor
*--------------------------------------------------------------------------
*	This method is the destructor.
* RETURNS: nothing
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		The date object must first have been instantiated
*
* POST-CONDITIONS
* 		Date object will be destructed
**************************************************************************/
Date::~Date()
{
}


// M U T A T O R S
/**************************************************************************
* Method SetAll
*--------------------------------------------------------------------------
*	This method sets all the month, day, and year data in the date object
* RETURNS: nothing
* -> sets variables in method to a value
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		newMonth   : the new month must be predefined
* 		newDay	   : the new day must be predefined
* 		newYear	   : the new year must be predefined
*
* POST-CONDITIONS
* 		Date object attributes will be updated with values defined in the
* 		passed parameters
**************************************************************************/
void Date::SetAll(int newMonth, //IN - month value to update to
				  int newDay,   //IN - day value to update to
				  int newYear)  //IN - year value to update to
{
		month = newMonth;
		day   = newDay;
		year  = newYear;
}


// A C C E S S O R S

/**************************************************************************
* Method GetMonth
*--------------------------------------------------------------------------
*	This method gets the month integer from the object
* RETURNS: the month integer
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		The attributes in the Date object must be predefined
*
* POST-CONDITIONS
* 		The Date object's month integer value is returned
**************************************************************************/
int Date::GetMonth() const
{
	return month;
}

/**************************************************************************
* Method GetDay
*--------------------------------------------------------------------------
*	This method gets the Day integer from the object
* RETURNS: the day integer
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		The attributes in the Date object must be predefined
*
* POST-CONDITIONS
* 		The Date object's day integer value is returned
**************************************************************************/
int Date::GetDay() const
{
	return day;
}

/**************************************************************************
* Method GetYear
*--------------------------------------------------------------------------
*	This method gets the Year integer from the object
* RETURNS: the year integer
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		The attributes in the Date object must be predefined
*
* POST-CONDITIONS
* 		The Date object's year integer value is returned
**************************************************************************/
int Date::GetYear() const
{
	return year;
}

/**************************************************************************
* Method ToString
*--------------------------------------------------------------------------
*	This method converts the date attributes into a string
* RETURNS: string with formated date info
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		The attributes in the Date object must be predefined
*
* POST-CONDITIONS
* 		The string with date information will be returned
**************************************************************************/
string Date::ToString() const
{
	ostringstream oss;

	// Processing - Formats month section based on its integer
	if (month < 10)
	{
		oss << 0 << month << "/";
	}
	else
	{
		oss << month << "/";
	}

	//Processing - Formats day section based on its integer
	if (day < 10)
	{
		oss << 0 << day << "/";
	}
	else
	{
		oss << day << "/";
	}

	//Processing - Formats year section based on its integer
	if (year > 999)
	{
		oss << year;
	}
	else if (year > 99)
	{
		oss << 0 << year;
	}
	else if(year > 9)
	{
		oss << 0 << 0 << year;
	}
	else if(year >= 0)
	{
		oss << 0 << 0 << 0 << year;
	}

	return oss.str();
}

/**************************************************************************
* Method Print
*--------------------------------------------------------------------------
*	This method outputs the date info
* RETURNS: nothing
* -> date information is output to console
*--------------------------------------------------------------------------
* PRE-CONDITIONS
* 		The attributes in the Date object must be predefined
*
* POST-CONDITIONS
* 		None, date data is output
**************************************************************************/
void Date::Print() const
{
	cout << ToString();
}

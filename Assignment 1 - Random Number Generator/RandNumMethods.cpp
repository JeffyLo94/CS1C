/************************************************************************
 * Name    		: Jeffrey Lo
 * Date			: 8/24/2014
 * Course	  	: CS1C
 * Assignment 	: 1
 ************************************************************************/

#include "AssignOne.h"

//Constructor
RandNum::RandNum()
{
	SetAll();
}

//Destructor
RandNum::~RandNum()
{
}

// SetAll - initializes random number object and all its attributes
void RandNum::SetAll()
{
	SetRandNum();
	SetString(value);
	SetDigits();
	SetReverseNum();
}

// SetRandNum - Generates a random number
void RandNum::SetRandNum()
{
	srand(time(NULL));

	value = rand()% 900 + 100;
}

// SetString - creates the integer into a string
void RandNum::SetString(int origValue)
{
	ostringstream oss;

	oss << origValue;

	valueStr = oss.str();
}

// SetDigits - Sets the individual digits of the three digit number
void RandNum::SetDigits()
{
	hundsDigit = value/100;
	tensDigit  = (value/10)-((hundsDigit)*10);
	onesDigit  = value - (((hundsDigit)*100)+((tensDigit)*10));
}

// SetsReverseNum - Reverses the integer
void RandNum::SetReverseNum()
{
	reverse = (onesDigit*100)+(tensDigit*10)+(hundsDigit);
}

// GetRandNum - Gets and Returns the random number value
int RandNum::GetRandNum() const
{
	return value;
}

// GetRandNumStr - Gets and Returns the random number value in string form
string RandNum::GetRandNumStr() const
{
	return valueStr;
}

// GetReverseNum - Gets and Returns the random number value in reverse
int RandNum::GetReverseNum() const
{
	return reverse;
}

// GetDigitSum - Calc and returns the sum of the random number's digits
int RandNum::GetDigitSum() const
{
	return (hundsDigit + tensDigit + onesDigit);
}

// GetTriple - Calculates and returns the random number tripled
int RandNum::GetTriple() const
{
	return value*3;
}


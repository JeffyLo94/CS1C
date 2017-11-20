/************************************************************************
 * Name    		: Jeffrey Lo
 * Date			: 8/24/2014
 * Course	  	: CS1C
 * Assignment 	: 1
 ************************************************************************/


#include "AssignOne.h"
using namespace AssignOne;

/**********************************************************************
 * ReadArray
 * -------------------------------------------------------------------
 *  Reads a integers from a specifed file and stores the numbers into
 *  an array
 * -------------------------------------------------------------------
 *********************************************************************/
void ReadArray(string fileName,
			   RandArrayType targetAr,
			   const int ARRAY_SIZE)
{
	ifstream inFile;
	int		 index;

	inFile.open(fileName.c_str());

	while(inFile)
	{
		for(index = 0; index < ARRAY_SIZE; index++)
		{
			inFile >> targetAr[index];
			inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	inFile.close();
}

/**********************************************************************
 * InsertionSort - Sorts an array with insertion algorithm
 *********************************************************************/
void InsertionSort(RandArrayType targetAr,
			   	   const int ARRAY_SIZE)
{
	 int index;
	 int count;
	 int temp;

	 for(count = 1; count < ARRAY_SIZE; count++)
	 {
		temp = targetAr[count];
		index = count - 1;
		while( (index >= 0) && (targetAr[index] < temp))
		{
			targetAr[index+1] = targetAr[index];
			 index--;
		}
		targetAr[index+1] = temp;
	 }
}

/**********************************************************************
 * PrintArray - prints array to output stream
 *********************************************************************/
void PrintArray(ostream& outArea,
				RandArrayType targetAr,
				const int ARRAY_SIZE)
{
	int index;
	for(index = 0; index < ARRAY_SIZE; index++)
	{
		outArea << targetAr[index] << endl;
	}
}

/**********************************************************************
 * PrintToFile
 * -------------------------------------------------------------------
 *	Prints array to a file specified
 *********************************************************************/
void PrintToFile(string fileName,
				RandArrayType targetAr,
				const int ARRAY_SIZE)
{
	ofstream outFile;

	outFile.open(fileName.c_str());

	PrintArray(outFile, targetAr, ARRAY_SIZE);

	outFile.close();
}

/**********************************************************************
 * FUNCTION CreateArray
 *--------------------------------------------------------------------
 *  This function will create an array of 10 random numbers
 *--------------------------------------------------------------------
 *********************************************************************/
void CreateArray(AssignOne::RandArrayType targetAr,
		   	   	 const int ARRAY_SIZE)
{
	int index;
	int value;
	srand(time(NULL));

	for(index = 0; index < ARRAY_SIZE; index++)
	{
		value = rand()% 900 + 100;
		targetAr[index] = value;
	}
}

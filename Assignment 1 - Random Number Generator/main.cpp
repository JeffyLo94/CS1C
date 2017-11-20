/************************************************************************
 * Name    		: Jeffrey Lo
 * Date			: 8/19/2014
 * Course	  	: CS1C
 * Assignment 	: 1
 ************************************************************************/

#include "AssignOne.h"
using namespace AssignOne;

/**************************************************************************
 * Assignment One - Random Numbers
 * -----------------------------------------------------------------------
 * This program generates a random number for the user and allows the user
 * to sum the digits of the number, triple the number, and reverse the
 * digits of the number. The program also allows the user to generate a 10
 * element random number array, and then writes the array to a file, sorts
 *************************************************************************/
int main()
{
	//Variable List
	int userInput;
	RandNum newRand;
	RandArrayType randArray;
	RandArrayType fileArray;
	string outputFile = "output.txt";

	cout << "Name:   Jeffrey Lo" << endl;
	cout << "Date:   8/24/2014" << endl;
	cout << "Class:  CS1C" << endl;
	cout << "Welcome to Assignment 1: Random Number!" << endl << endl;

	cout << "Press ENTER to generate your random number: ";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout << "Your number is: " << newRand.GetRandNum() << endl << endl;

	//DisplayMenu - Displays the menu
	DisplayMenu(cout);
	//GetAndCheckOneInt - Gets and checks the user input
	userInput = GetAndCheckOneInt("Enter a Command: ",
								  UP_BOUND,
								  LOW_BOUND);

	//PROCESSING - Checks user input to see if user wants to exit
	while(userInput != EXIT &&
		 (userInput <= UP_BOUND && userInput >= LOW_BOUND))
	{
		switch(userInput)
		{
			// Performs the user command to sum the digits
			case SUM_DIGITS: cout << "The sum of the digits in the number "
								  << newRand.GetRandNum()
								  << " is: " << newRand.GetDigitSum()
								  << endl   << endl;
							 break;
			// Performs the user command to triple the number
			case TRIP_NUM:	 cout << "The tripled value of the number "
								  << newRand.GetRandNum()
								  << " is: " << newRand.GetTriple()
								  << endl   << endl;
							 break;
			// Performs the user command to reverse
			case REVERSE_NUM:cout << "The reverse of the number "
					  	  	  	  << newRand.GetRandNum()
					  	  	  	  << " is: " << newRand.GetReverseNum()
					  	  	  	  << endl   << endl;
				break;
			case RUN_ARRAY:  //CreateArray - Creates an array of 10 random
							 // 			 integers
							 CreateArray(randArray, AR_SIZE);

							 //InsertionSort - Sorts the array
							 cout << "\nPress ENTER to sort array: ";
							 cin.ignore(numeric_limits<streamsize>::max(),
										'\n');
							 InsertionSort(randArray, AR_SIZE);

							 //Output - Prints out sorted array
							 cout << "\nYour sorted array is: "
								  << endl;
							 PrintArray(cout, randArray, AR_SIZE);

							 //PrintToFile - Prints array to a file
							 cout << "Array has been printed to file..."
								  << outputFile << endl << endl;
							 PrintToFile(outputFile, randArray, AR_SIZE);

							 //ReadArray - Reads array from file
							 cout << "\nPress ENTER to read array from file: ";
							 cin.ignore(numeric_limits<streamsize>::max(),
									    '\n');
							 ReadArray(outputFile, fileArray, AR_SIZE);

							 //Output - Prints out array
							 cout << "\nYour array of 10 random numbers is: "
								  << endl;
							 PrintArray(cout, randArray, AR_SIZE);
							 cout << endl;
							 break;

			default: cout << "error undefined input\n";
		}

		DisplayMenu(cout);
		userInput = GetAndCheckOneInt("Enter a Command: ",
									  UP_BOUND,
									  LOW_BOUND);
	}

	cout << "Thank you for running!\n :D";
	return 0;
}

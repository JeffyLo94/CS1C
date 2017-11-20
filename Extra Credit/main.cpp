/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN EC : Extra Credit
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/7/2014
*******************************************************************************/

#include "ECHeader.h"
#include "DynStrArray.h"
using namespace JeffreyLo;

/* Extra Credit
 * @Input -	 Input.txt containing "The rain in Spain falls mainly in the plain"
 * @Output - prints sorted array of pointers and sorted array of pointers
 * 			 without duplicates
 * @Author - Jeffrey Lo
 */
int main()
{
	//OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	const string FILENAME = "input.txt";

	ifstream	inFile;
	string		tempStr;
	int			size;
	int			index = 0;

	cout << "Opening File..." << endl;
	inFile.open(FILENAME.c_str());

	cout << "Finding Size..." << endl;
	size = FindNumWords(inFile, FILENAME);

	DynStrArray testAr(size);

	cout << "Reading File..." << endl;
	while(!inFile.eof())
	{
		getline(inFile, tempStr, ' ');
//		cout << "The String: " << tempStr << endl;
		testAr.Store(tempStr, index);
		index++;
	}
	cout << "Finished Reading..." << endl;

	inFile.close();

	cout << "Sorting..." << endl;
	testAr.SortArray();

	cout << "Printing Array: \n";
	testAr.PrintArray(cout);

	cout << "\nPrinting without Duplicates: \n";
	testAr.PrintNoDupe(cout);

	return 0;
}


int FindNumWords( ifstream& inFile, const string FILENAME )
{
	int numWords = 0;
	string tempStr;


	while(!inFile.eof())
	{
		getline(inFile, tempStr, ' ');
		numWords++;
	}

	inFile.clear();
	inFile.seekg(0,ios::beg);

	return numWords;
}

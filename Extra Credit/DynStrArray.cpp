/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN EC : Extra Credit
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/7/2014
*******************************************************************************/


#include "DynStrArray.h"

//Constructor
DynStrArray::DynStrArray( int arSize )
{
	int i;
	if ( arSize < 1 ) {
		cerr << "DynStrArray constructor - invalid size: "
			  << arSize << endl;
		exit(1);
	}

	strAr = new  string[arSize] ;	  // allocate memory

	size = arSize;

	for (i = 0; i < size;  i++)
		strAr[i] = "";
}

// Destructor
// POST: Memory for dynamic array deallocated
DynStrArray::~DynStrArray( )
{
	delete [ ] strAr;
}

// M U T A T O R S

void DynStrArray::Store(string inStr, int index)
{
	if ( index < 0 || index >= size ) {
		cout << "Store - invalid index : " << index << endl;
	}
	else
	{
		strAr[index] = inStr;
	}
}

void DynStrArray::SortArray()
{
	int outer;
	int inner;
	string tempStr;
	string tempLower;
	string lowerCase[size];
	//Processing - Converting string array to lower case strings
	for(int index = 0; index < size; index++)
	{
		lowerCase[index] = strAr[index];
		transform(lowerCase[index].begin(), lowerCase[index].end(),
				  lowerCase[index].begin(), ::tolower);
	}
	// Processing - Insertion Sort (sorts both lower case and strAr_
	for (outer = 1; outer < size; outer++)
	{
		inner = outer;
		while (inner > 0 && lowerCase[inner - 1] > lowerCase[inner])
		{
			tempLower = lowerCase[inner];
			lowerCase[inner] = lowerCase[inner - 1];
			lowerCase[inner - 1] = tempLower;
			tempStr = strAr[inner];
			strAr[inner] = strAr[inner - 1];
			strAr[inner - 1] = tempStr;
			inner--;
		}
	}
}


// A C C E S S O R S

string DynStrArray::ValueAt(int index) const
{
	if ( index < 0 || index >= size ) {
		cout << "ValueAt - invalid index : " << index << endl;
	}

	return strAr[index];
}

int DynStrArray::Search(string someStr, string someAr[])
{
	int indexFound = -1;
	int high  = size-1;
	int low   = 0;
	int mid;

	while( high >= low)
	{
		mid = (high + low) / 2;
		if (someStr < someAr[mid] )
			high = mid-1;
		else if ( someStr > someAr[mid])
			low = mid+1;
		else
		{
			indexFound = mid;
			break;
		}
	}
	return indexFound;
}


void DynStrArray::PrintArray(ostream& out) const
{
	for(int index = 0; index < size; index++)
	{
		out << strAr[index] << endl;
	}
}

void DynStrArray::PrintNoDupe(ostream& out)
{
	int index;
	int newIndex = 0;
	int newSize = size;
	string temp[size];

	string lowerCase[size];
	//Processing - Converting string array to lower case strings
	for(int index = 0; index < size; index++)
	{
		lowerCase[index] = strAr[index];
		transform(lowerCase[index].begin(), lowerCase[index].end(),
				  lowerCase[index].begin(), ::tolower);
	}

	for(index = 0; index < size; index++)
	{
		temp[newIndex] = lowerCase[index];
		if((index+1 < size) && temp[newIndex] == lowerCase[index+1])
		{
			index++;
			newSize--;
		}
		newIndex++;
	}

	for(index = 0; index < newSize; index++)
	{
		out << temp[index] << endl;
	}
}

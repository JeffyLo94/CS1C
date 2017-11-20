/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN EC : Extra Credit
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/7/2014
*******************************************************************************/

#ifndef DYNSTRARRAY_H_
#define DYNSTRARRAY_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

class DynStrArray
{
	public:
		DynStrArray(int arSize);
		~DynStrArray();

		//Mutators
		// Store - Stores string into dynamic ptr array
		void Store(string inStr, int index);
		// SortArray - Sorts array via insertion sort algorithm
		void SortArray();

		//Accessors
		string	ValueAt(int index) 			const;
		void 	PrintArray(ostream& out)	const;
		void	PrintNoDupe(ostream& out);
		// Search - Searches array for string via binary search
		int Search(string someStr, string someAr[]);

	private:
		string *strAr;
		int		size;
};


#endif /* DYNSTRARRAY_H_ */

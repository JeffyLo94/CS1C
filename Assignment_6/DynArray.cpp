/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #6 : Dynamic Array
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/30/2014
*******************************************************************************/

#include "DynArray.h"
#include <iostream>
using namespace std;
#include <cstdlib>

DynArray::DynArray( /* in */  int arrSize )
// Constructor.
// PRE:  arrSize is assigned
// POST:  IF arrSize >= 1 && enough memory THEN Array of size arrSize
//			is created with all elements == 0  ELSE error message.
{
	int i;
	if ( arrSize < 1 ) {
		cerr << "DynArray constructor - invalid size: "
			  << arrSize << endl;
		exit(1);
	}

	arr = new  int[arrSize] ;	  // allocate memory

	size = arrSize;

	for (i = 0; i < size;  i++)
		arr[i] = 0;
}

void  DynArray::Store ( /* in */ int val,  /* in */ int i )
// PRE:  val and i are assigned
// POST: IF 0 <= i < size of this array THEN
// 	   arr[i] == val
// 	   ELSE error message.
 {

	if ( i < 0 || i >= size ) {
		cout << "Store - invalid index : " << i << endl;
	}

	arr[i] = val ;

}

int  DynArray::ValueAt ( /* in */ int i )  const
// PRE:  i is assigned.
// POST: IF 0 <= i < size THEN
// 	   FCTVAL == arr[i]
// 	   ELSE halt with error message.
{
	if ( i < 0 || i >= size ) {
		cout << "ValueAt - invalid index : " << i << endl;
	}

	return  arr[i];
}

DynArray::~DynArray( )
// Destructor.
// POST: Memory for dynamic array deallocated.
{
	delete [ ] arr ;
}

DynArray::DynArray( const DynArray& otherArr )
// Copy constructor
// Implicitly called for deep copy in initializations.
// POST:  If room on free store THEN
// 	new array of size otherArr.size is created
// 	on free store && arr == its base address
//     && size == otherArr.size
// 	&& arr[0..size-1] == otherArr.arr[0..size-1]
// 	ELSE error message.
{
	int i ;
	size = otherArr.size ;
	arr = new  int[size] ;	  // allocate memory for copy

	for ( i = 0; i< size ; i++ )
		arr[i] = otherArr.arr[i] ;        // copies array

}

void  DynArray::CopyFrom ( /* in */ DynArray  otherArr )
// Creates a deep copy of otherArr.
// POST:  Array pointed to by arr@entry deallocated
//   &&  IF room on free store
//	  THEN new array is created on free store
//	      && arr == its base address
//	      && size == otherArr.size
//	      && arr[0..size-1] == otherArr[0..size-1]
//        ELSE halts with error message.
{
	int i ;
 	cout << "copyfrom function is called" << endl;
	delete [ ]  arr ;			// delete current array
	size = otherArr.size ;
	arr = new int [size] ;		// allocate new array
		for ( i = 0; i< size ; i++ )    // deep copy array
		arr[i] = otherArr.arr[i] ;
}



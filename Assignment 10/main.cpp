/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #10 : Exceptions
*	CLASS      : CS1C
*	SECTION    : 6-10p T-Th
*	DUE DATE   : 10/27/2014
*******************************************************************************/


#include "AssignTen.h"
#include "QueueArray.h"
#include <cassert>
using namespace JeffreyLo;

int main()
{
	const int QUEUE_SIZE = 10;
	int index;

	OutputHeader(NAME,CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	cout << "Creating array with size of 10...\n";
	QueueArray<int> testQueue(QUEUE_SIZE);

	cout << "Checking Assert (size of Queue is zero),\n\tif passes program will"
		<<" attempt to dequeue\n";
	assert (testQueue.size() == 0);

	cout << "\nTrying to dequeue an empty queue...\n";
	testQueue.dequeue();

	cout << "\nFilling Queue...\n";
	for(index = 0; index < QUEUE_SIZE; index++){
		testQueue.enqueue(index+1);
	}

	cout << "Checking Full:";
	cout << (testQueue.isFull()?"True":"Full") << endl;

	cout << "Trying to Enqueue a full queue...\n";
	testQueue.enqueue(index+1);

	cout << "Checking Assert (size of Queue is greater than zero),\n"
		 << "\tif fails program will terminate.\n" << endl;
	assert (testQueue.size() == 0);

	return 0;
}

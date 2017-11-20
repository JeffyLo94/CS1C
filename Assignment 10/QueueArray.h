/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #9 : Queues
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/14/2014
*******************************************************************************/

#ifndef QUEUEARRAY_H_
#define QUEUEARRAY_H_

#include <iostream>
#include <cstdlib>
using namespace std;


template <class qType>
class QueueArray
{
	public:
		QueueArray(int maxSize);
		~QueueArray();

		// Mutators
		void 	enqueue(qType someType);
		qType 	dequeue();

		// Accessors
		qType 	front();
		int 	size();
		bool 	isEmpty();
		bool 	isFull();
		void 	print(ostream& os);
	private:
		int capacity;
		int increment;
		qType* theQueue;
};


// Constructor
template <class qType>
QueueArray<qType>::QueueArray(int maxSize)
{
	capacity = maxSize;
	increment = 0;


	if ( capacity < 1 ) {
		cerr << "DynArray constructor - invalid size: "
			  << maxSize << endl;
		exit(1);
	}


	theQueue = new qType[capacity] ;	  // allocate memory

}

// Destructor
template <class qType>
QueueArray<qType>::~QueueArray()
{
}

// Mutators
template <class qType>
void QueueArray<qType>::enqueue(qType someType)
{
	int testIndex = increment+1;
	try{
		if(testIndex > capacity)
		{
			throw testIndex;
		}

		theQueue[increment++] = someType;
	}
	catch(int err){
		cout << "The Queue is FULL, cannot add to queue\n";
	}
}
template <class qType>
qType QueueArray<qType>::dequeue()
{
	qType dequeued;
	bool goodDequeue = false;
	try{
		if(isEmpty()){
			throw goodDequeue;
		}

		dequeued = theQueue[0];

		for(int index = 0; index <= capacity - 2; index++)
		{
			theQueue[index] = theQueue[index+1];
		}

		increment--;
		goodDequeue = true;
	}
	catch(bool err){
		cout << "The Queue is EMPTY, cannot dequeue\n";
		dequeued = NULL;
	}
	return dequeued;
}

// Accessors
template <class qType>
qType QueueArray<qType>::front()
{

	return theQueue[0];
}

template <class qType>
int QueueArray<qType>::size()
{
	return increment;
}

template <class qType>
bool QueueArray<qType>::isEmpty()
{
	return increment == 0;
}

template <class qType>
bool QueueArray<qType>::isFull()
{
	return (increment == capacity);
}

template <class qType>
void QueueArray<qType>::print(ostream& os)
{
	int index;
	for(index = 0; index < increment; index++)
	{
		os << "\t" << theQueue[index] << endl;
	}
}



#endif /* QUEUEARRAY_H_ */

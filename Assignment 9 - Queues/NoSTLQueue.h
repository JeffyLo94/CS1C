/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #9 : Queues
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/14/2014
*******************************************************************************/

#ifndef NOSTLQUEUE_H_
#define NOSTLQUEUE_H_

#include <iostream>
#include <cstdlib>
using namespace std;


template <class qType>
class NoSTLQueue
{
	public:
		NoSTLQueue(int maxSize);
		~NoSTLQueue();

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
NoSTLQueue<qType>::NoSTLQueue(int maxSize)
{
	capacity = maxSize;
	increment = 0;

	int i;
	if ( capacity < 1 ) {
		cerr << "DynArray constructor - invalid size: "
			  << maxSize << endl;
		std::exit(1);
	}

	theQueue = new qType[capacity] ;	  // allocate memory

}

// Destructor
template <class qType>
NoSTLQueue<qType>::~NoSTLQueue()
{
}

// Mutators
template <class qType>
void NoSTLQueue<qType>::enqueue(qType someType)
{
	if(!isFull())
	{
		theQueue[increment++] = someType;
	}
	else
	{
		cout << "The Queue is FULL\n";
	}
}
template <class qType>
qType NoSTLQueue<qType>::dequeue()
{
	qType dequeued;
	if(!isEmpty())
	{
		dequeued = theQueue[0];

		for(int index = 0; index <= capacity - 2; index++)
		{
			theQueue[index] = theQueue[index+1];
		}

		increment--;

	}
	else
	{
		cout << "The Queue is EMPTY\n";
	}
	return dequeued;
}

// Accessors
template <class qType>
qType NoSTLQueue<qType>::front()
{

	return theQueue[0];
}

template <class qType>
int NoSTLQueue<qType>::size()
{
	return increment;
}

template <class qType>
bool NoSTLQueue<qType>::isEmpty()
{
	return increment == 0;
}

template <class qType>
bool NoSTLQueue<qType>::isFull()
{
	return (increment == capacity);
}

template <class qType>
void NoSTLQueue<qType>::print(ostream& os)
{
	int index;
	for(index = 0; index < increment; index++)
	{
		os << "\t" << theQueue[index] << endl;
	}
}



#endif /* NOSTLQUEUE_H_ */

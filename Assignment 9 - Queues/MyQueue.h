/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #9 : Queues
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/14/2014
*******************************************************************************/


#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <queue>
#include <iostream>
using namespace std;

template <class qType>
class MyQueue
{
	public:
		MyQueue(int maxSize);
		~MyQueue();

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
		queue<qType> theQueue;
		int capacity;
		int increment;
};

// Constructor
template <class qType>
MyQueue<qType>::MyQueue(int maxSize)
{
	capacity = maxSize;
	increment = 0;
}

// Destructor
template <class qType>
MyQueue<qType>::~MyQueue()
{
}

// Mutators
template <class qType>
void MyQueue<qType>::enqueue(qType someType)
{
	if(!isFull())
	{
		theQueue.push(someType);
		increment++;
	}
	else
	{
		cout << "The Queue is FULL\n";
	}
}
template <class qType>
qType MyQueue<qType>::dequeue()
{
	if(!isEmpty())
	{
		qType deQueued = theQueue.front();
		theQueue.pop();
		increment--;
		return deQueued;
	}
	else
	{
		cout << "The Queue is EMPTY\n";
	}
}

// Accessors
template <class qType>
qType MyQueue<qType>::front()
{
	return theQueue.front();
}

template <class qType>
int MyQueue<qType>::size()
{
	return theQueue.size();
}

template <class qType>
bool MyQueue<qType>::isEmpty()
{
	return theQueue.empty();
}

template <class qType>
bool MyQueue<qType>::isFull()
{
	return (size() == capacity);
}

template <class qType>
void MyQueue<qType>::print(ostream& os)
{
	if(increment > 0)
	{
		qType temp = theQueue.front();
		os << "\t"<< temp << endl;
		theQueue.pop();
		theQueue.push(temp);
		increment--;
		print(os);
	}
	else
	{
		increment = theQueue.size();
	}
}

#endif /* MYQUEUE_H_ */

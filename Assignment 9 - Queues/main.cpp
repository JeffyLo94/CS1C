/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #9 : Queues
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 10/14/2014
*******************************************************************************/

#include "AssignNine.h"
#include "MyQueue.h"
#include "NoSTLQueue.h"
#include <queue>
#include <sstream>
using namespace JeffreyLo;

//P R O T O T Y P E S
template <class qType>
void testEmpty(NoSTLQueue<qType>& arQueue);
template <class qType>
void testFull(NoSTLQueue<qType>& arQueue);
template <class qType>
void testEmpty(MyQueue<qType>& someQueue);
template <class qType>
void testFull(MyQueue<qType>& someQueue);

int main()
{
	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	const int MAX = 10;
	int index;
	double dblIndex;
	ostringstream oss;
	string testStr;
	MyQueue<string> 	strQueue(MAX);
	MyQueue<int>		intQueue(MAX);
	MyQueue<double> 	dblQueue(MAX);
	NoSTLQueue<string>  str1Queue(MAX);
	NoSTLQueue<int>		int1Queue(MAX);
	NoSTLQueue<double> 	dbl1Queue(MAX);

/*************************NON-STL BASED TESTING BEGINS*************************/
	cout << "\n\nTESTING NON-STL QUEUE\n\n";

	cout << "String Test\n";
	cout << "Adding 6 things to queue..." << endl;
	for(index = 0; index < 6; index++)
	{
		oss << "String " << index+1;
		testStr = oss.str();
		oss.str("");
		oss.clear();
		str1Queue.enqueue(testStr);
	}
	cout << "Printing Queue:" << endl;
	str1Queue.print(cout);

	cout << "Deleting 4 things from Queue..." << endl;
	for(index = 0; index < 4; index++)
	{
		cout << "\tDequeuing: " << str1Queue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	str1Queue.print(cout);

	cout << "Adding 5 things to queue..." << endl;
	for(index = 6; index < 11; index++)
	{
		oss << "String " << index+1;
		testStr = oss.str();
		oss.str("");
		oss.clear();
		str1Queue.enqueue(testStr);
	}
	cout << "Printing Queue:" << endl;
	str1Queue.print(cout);

	cout << "Deleting 3 things from Queue..." << endl;
	for(index = 0; index < 3; index++)
	{
		cout << "\tDequeuing: " << str1Queue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	str1Queue.print(cout);

	//Int Test
	cout << "\nInteger Test\n";
	cout << "Adding 6 integers to queue..." << endl;
	for(index = 0; index < 6; index++)
	{
		int1Queue.enqueue(index);
	}
	cout << "Printing Queue:" << endl;
	int1Queue.print(cout);

	cout << "Deleting 4 integers from Queue..." << endl;
	for(index = 0; index < 4; index++)
	{
		cout << "\tDequeuing: " << int1Queue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	int1Queue.print(cout);

	cout << "Adding 5 integers to queue..." << endl;
	for(index = 6; index < 11; index++)
	{
		int1Queue.enqueue(index);
	}
	cout << "Printing Queue:" << endl;
	int1Queue.print(cout);

	cout << "Deleting 3 integers from Queue..." << endl;
	for(index = 0; index < 3; index++)
	{
		cout << "\tDequeuing: " << int1Queue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	int1Queue.print(cout);

	//Double Test
	cout << "\nDouble Test\n";
	cout << "Adding 6 doubles to queue..." << endl;
	for(dblIndex = 0.5; dblIndex < 6.5; dblIndex++)
	{
		dbl1Queue.enqueue(dblIndex);
	}
	cout << "Printing Queue:" << endl;
	dbl1Queue.print(cout);

	cout << "Deleting 4 doubles from Queue..." << endl;
	for(dblIndex = 0.0; dblIndex < 4.0; dblIndex++)
	{
		cout << "\tDequeuing: " << dbl1Queue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	dbl1Queue.print(cout);

	cout << "Adding 5 double to queue..." << endl;
	for(dblIndex = 6.5; dblIndex < 11.5; dblIndex++)
	{
		dbl1Queue.enqueue(dblIndex);
	}
	cout << "Printing Queue:" << endl;
	dbl1Queue.print(cout);

	cout << "Deleting 3 doubles from Queue..." << endl;
	for(dblIndex = 0; dblIndex < 3; dblIndex++)
	{
		cout << "\tDequeuing: " << dbl1Queue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	dbl1Queue.print(cout);
	cout << endl << endl;

	//OTHER Tests
	testEmpty(int1Queue);
	cout << "Emptying Queue...\n";
	index = 0;
	while(index < int1Queue.size())
	{
		int1Queue.dequeue();
	}
	testEmpty(int1Queue);
	cout << "Test Dequeuing empty Queue:\n";
	int1Queue.dequeue();

	cout << "Filling Queue...\n";
	while(!int1Queue.isFull())
	{
		for(index = 0; index < MAX; index++)
		{
			int1Queue.enqueue(index);
		}
	}
	testFull(int1Queue);
	cout << "Front is: " << int1Queue.front() << endl;
	cout << "Printing: " << endl;
	int1Queue.print(cout);
	cout << "Test Enqueuing full Queue:\n";
	int1Queue.enqueue(MAX+1);

/**************************STL BASED TESTING BEGINS****************************/
	cout << "\n\nTESTING STL BASED QUEUE\n\n";

	//String Test
	cout << "String Test\n";
	cout << "Adding 6 things to queue..." << endl;
	for(index = 0; index < 6; index++)
	{
		oss << "String " << index+1;
		testStr = oss.str();
		oss.str("");
		oss.clear();
		strQueue.enqueue(testStr);
	}
	cout << "Printing Queue:" << endl;
	strQueue.print(cout);

	cout << "Deleting 4 things from Queue..." << endl;
	for(index = 0; index < 4; index++)
	{
		cout << "\tDequeuing: " << strQueue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	strQueue.print(cout);

	cout << "Adding 5 things to queue..." << endl;
	for(index = 6; index < 11; index++)
	{
		oss << "String " << index+1;
		testStr = oss.str();
		oss.str("");
		oss.clear();
		strQueue.enqueue(testStr);
	}
	cout << "Printing Queue:" << endl;
	strQueue.print(cout);

	cout << "Deleting 3 things from Queue..." << endl;
	for(index = 0; index < 3; index++)
	{
		cout << "\tDequeuing: " << strQueue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	strQueue.print(cout);

	//Int Test
	cout << "\nInteger Test\n";
	cout << "Adding 6 integers to queue..." << endl;
	for(index = 0; index < 6; index++)
	{
		intQueue.enqueue(index);
	}
	cout << "Printing Queue:" << endl;
	intQueue.print(cout);

	cout << "Deleting 4 integers from Queue..." << endl;
	for(index = 0; index < 4; index++)
	{
		cout << "\tDequeuing: " << intQueue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	intQueue.print(cout);

	cout << "Adding 5 integers to queue..." << endl;
	for(index = 6; index < 11; index++)
	{
		intQueue.enqueue(index);
	}
	cout << "Printing Queue:" << endl;
	intQueue.print(cout);

	cout << "Deleting 3 integers from Queue..." << endl;
	for(index = 0; index < 3; index++)
	{
		cout << "\tDequeuing: " << intQueue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	intQueue.print(cout);

	//Double Test
	cout << "\nDouble Test\n";
	cout << "Adding 6 doubles to queue..." << endl;
	for(dblIndex = 0.5; dblIndex < 6.5; dblIndex++)
	{
		dblQueue.enqueue(dblIndex);
	}
	cout << "Printing Queue:" << endl;
	dblQueue.print(cout);

	cout << "Deleting 4 doubles from Queue..." << endl;
	for(dblIndex = 0.0; dblIndex < 4.0; dblIndex++)
	{
		cout << "\tDequeuing: " << dblQueue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	dblQueue.print(cout);

	cout << "Adding 5 double to queue..." << endl;
	for(dblIndex = 6.5; dblIndex < 11.5; dblIndex++)
	{
		dblQueue.enqueue(dblIndex);
	}
	cout << "Printing Queue:" << endl;
	dblQueue.print(cout);

	cout << "Deleting 3 doubles from Queue..." << endl;
	for(dblIndex = 0; dblIndex < 3; dblIndex++)
	{
		cout << "\tDequeuing: " << dblQueue.dequeue() << endl;
	}
	cout << "Printing Queue:" <<endl;
	dblQueue.print(cout);
	cout << endl << endl;

	// OTHER TESTS
	testEmpty(intQueue);
	cout << "Emptying Queue...\n";
	index = 0;
	while(index < intQueue.size())
	{
		intQueue.dequeue();
	}
	testEmpty(intQueue);
	cout << "Test Dequeuing empty Queue:\n";
	intQueue.dequeue();

	cout << "Filling Queue...\n";
	while(!intQueue.isFull())
	{
		for(index = 0; index < MAX; index++)
		{
			intQueue.enqueue(index);
		}
	}
	testFull(intQueue);
	cout << "Front is: " << intQueue.front() << endl;
	cout << "Printing: " << endl;
	intQueue.print(cout);
	cout << "Test Enqueuing full Queue:\n";
	intQueue.enqueue(MAX+1);


	//Test END
	cout << "\nTesting Finished!" << endl;
	return 0;
}

// F U N C T I O N S
template <class qType>
void testEmpty(MyQueue<qType>& someQueue)
{
	if(someQueue.isEmpty())
	{
		cout << "Integer Queue is Empty\n";
	}
	else
	{
		cout << "Integer Queue is Not Empty\n";
	}
}

template <class qType>
void testEmpty(NoSTLQueue<qType>& someQueue)
{
	if(someQueue.isEmpty())
	{
		cout << "Integer Queue is Empty\n";
	}
	else
	{
		cout << "Integer Queue is Not Empty\n";
	}
}

template <class qType>
void testFull(MyQueue<qType>& someQueue)
{
	if(someQueue.isFull())
	{
		cout << "Integer Queue is Full\n";
	}
	else
	{
		cout << "Integer Queue is Not Full\n";
	}
}

template <class qType>
void testFull(NoSTLQueue<qType>& someQueue)
{
	if(someQueue.isFull())
	{
		cout << "Integer Queue is Full\n";
	}
	else
	{
		cout << "Integer Queue is Not Full\n";
	}
}

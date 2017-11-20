/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN #4 : Pointers
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/16/2014
*******************************************************************************/

#include "AssignFour.h"
#include "CheckYes.h"
using namespace JeffreyLo;

int main()
{
	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	// Constants
	const int COL_ONE 	= 20;
	const int COL_TWO 	= 20;
	const int COL_THREE = 20;

	// Variable List
	int		index;
	int		maxCandidates;
	string	nameBuffer;
	int		votesBuffer;
	int		totalVotes;
	ostringstream oss;
	bool	votesCheck;
	bool	nameCheck;
	int		winnerIndex;
	int		mostVotes;

	string*	candidateNames	= NULL;
	int*	votesReceived	= NULL;

	maxCandidates = GetInt("Input number of candidates: ");

	candidateNames 	= new string[maxCandidates];
	votesReceived	= new int[maxCandidates];
	totalVotes		= 0;
	mostVotes		= 0;

	//NOT FINISHED - add alternate route if false
	//NOT FINISHED - Figure out what happens if CheckYes has an integer input
	for(index = 0; index < maxCandidates; index++)
	{

		do
		{
			cout << "Please input candidates name: ";
			getline(cin, nameBuffer);
			cout << endl;
			nameCheck = CheckYes(nameBuffer);
			if(nameCheck)
			{
				candidateNames[index] = nameBuffer;

			}
		}while(!nameCheck);

		cout << endl;

		do
		{
			oss << "Input the number of votes " <<
					candidateNames[index] <<
					" received: ";
			votesBuffer = GetInt(oss.str());
			oss.str("");
			votesCheck = CheckYes(votesBuffer);
			if(votesCheck)
			{
				votesReceived[index] = votesBuffer;
				totalVotes += votesBuffer;
			}
		}while(!votesCheck);
		cout << endl;
	}

	cout << left;
	cout << setw(COL_ONE)   << "Candidate"
		 << setw(COL_TWO)   << "Votes Received"
		 << setw(COL_THREE) << "% of Total Votes Received"
		 << endl;
	for(index = 0; index < maxCandidates; index++)
	{
		cout << setw(COL_ONE)   << candidateNames[index]
			 << setw(COL_TWO)   << votesReceived[index]
			 << setw(COL_THREE) << fixed << setprecision(2)
			 << ((float(votesReceived[index])/totalVotes)*100)
			 << endl;
		if(votesReceived[index] > mostVotes)
		{
			mostVotes = votesReceived[index];
			winnerIndex = index;
		}
	}

	cout << setw(COL_ONE)	<< "Total";
	cout << setw(COL_TWO)	<< totalVotes	<< endl << endl;
	cout << "The Winner of the Election is " << candidateNames[winnerIndex];


	delete [] candidateNames;
	delete [] votesReceived;


	return 0;
}


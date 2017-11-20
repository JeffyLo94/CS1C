/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN# 2 : Perfect Shuffle and Deck
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/2/2014
*******************************************************************************/

#include "AssignTwo.h"
#include "Deck.h"
using namespace JeffreyLo;


/*******************************************************************************
 * Assignment 2
 * ----------------------------------------------------------------------------
 * 	This program first outputs the student header for the program. It then
 * 	creates and outputs a deck of cards, it performs the necessary amount of
 * 	shuffles to return a shuffled deck of cards to its original state.
 * ----------------------------------------------------------------------------
 ******************************************************************************/
int main()
{
	//Variable List
	int shuffleCounter = 0; //Calc - holds number of shuffles
	Deck myDeck;			//Creates a deck object

	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	//DisplayOrigDeck - displays the orignal deck to the consout
	myDeck.DisplayOrigDeck(cout);

	//PerfectSuffle - performs a perfect shuffle
	myDeck.PerfectShuffle();
	shuffleCounter++;

	//DisplayShuffleDeck - displays the shuffled deck
	myDeck.DisplayShuffleDeck(cout);

	//Processing - loops and continues to shuffle until deck returns to
	//			   original state
	while((myDeck.CompareDeckDiff()) != 0)
	{
		myDeck.PerfectShuffle();
		shuffleCounter++;
	}

	//Output- displays final deck
	cout << "The Final ";
	myDeck.DisplayShuffleDeck(cout);

	//Output - displays total number of shuffles
	cout << "It took a total of " << shuffleCounter
		 << " shuffles to return the deck to "
		 << "the original configuration.\n\n";


	return 0;
}

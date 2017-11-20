/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN# 2 : Perfect Shuffle and Deck
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/2/2014
*******************************************************************************/

#ifndef DECK_H_
#define DECK_H_

#define DECK_MAX 52

#include "Card.h"
#include <sstream>
using namespace std;


// E N U M
enum suitType
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

// O B J E C T
class Deck
{
	public:
		Deck();		//Constructor
		~Deck();	//Destructor

		//Mutators
		/***********************************************************************
		 * Method PerfectShuffle
		 * -------------------------------------------------------------------
		 * Performs a perfect shuffle and modifies shuffleDeck
		 * 	returns-> nothing
		 **********************************************************************/
		void PerfectShuffle();
		/***********************************************************************
		 * Method ResetDecks
		 * -------------------------------------------------------------------
		 * Resets shuffled and original decks
		 * 	returns-> nothing
		 **********************************************************************/
		void ResetDecks();

		//Accessors
		/***********************************************************************
		 * Method DisplayOrigDeck
		 * -------------------------------------------------------------------
		 * Displays the cards in the deck into the specified stream
		 * 	returns -> cards in deck to ostream variable
		 **********************************************************************/
		void DisplayOrigDeck(ostream& os);
		/***********************************************************************
		 * Method DisplayShuffleDeck
		 * -------------------------------------------------------------------
		 * Displays the cards in the deck into the specified stream
		 * 	returns -> cards in deck to ostream variable
		 **********************************************************************/
		void DisplayShuffleDeck(ostream& os);
		/***********************************************************************
		 * Method CompareDeckDiff
		 * -------------------------------------------------------------------
		 * Compares and finds the number of differences in the decks
		 * 	returns -> number of differences in the deck
		 **********************************************************************/
		int  CompareDeckDiff();

	private:
		//Helpers
		/***********************************************************************
		 * Method SplitDeck
		 * -------------------------------------------------------------------
		 * Splits the shuffled deck of cards in preparation for the perfect
		 * shuffle
		 * 	returns -> arrays by reference
		 **********************************************************************/
		void SplitDeck(Card lower[], Card higher[]);

		Card origDeck[DECK_MAX];
		Card shuffleDeck[DECK_MAX];
};


#endif /* DECK_H_ */

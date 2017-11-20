/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN# 2 : Perfect Shuffle and Deck
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/2/2014
*******************************************************************************/

#ifndef CARD_H_
#define CARD_H_

#include <string>
using namespace std;

// O B J E C T
class Card
{
	public:
		Card(); //Default Constructor
		Card(int suitType, int cardNum); //Overloaded constructor
		~Card();

		//Helper Functions
		/***********************************************************************
		 * Method SetAll
		 * -------------------------------------------------------------------
		 * Sets all data (suit type and card number) for the card
		 * 	returns -> nothing
		 **********************************************************************/
		void SetAll(int suitType, int cardNum);

		/***********************************************************************
		 * Method GetSuit
		 * -------------------------------------------------------------------
		 * Gets the suit type of the card
		 * 	returns -> integer value of suit type
		 **********************************************************************/
		int GetSuit();

		/***********************************************************************
		 * Method GetValue
		 * -------------------------------------------------------------------
		 * Gets the number value of the card
		 * 	returns -> string of card number
		 **********************************************************************/
		string GetValue();

	private:
		// Data
		int suit;
		int  value;
};



#endif /* CARD_H_ */

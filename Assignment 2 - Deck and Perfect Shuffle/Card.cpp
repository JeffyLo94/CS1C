/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN# 2 : Perfect Shuffle and Deck
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/2/2014
*******************************************************************************/

#include  "Card.h"

//Constructor
Card::Card()
{
	suit = ' ';
	value = 0;
}

/***********************************************************************
 * Overloaded Constructor
 * -------------------------------------------------------------------
 * Initializes card with the set all method
 * 	returns -> nothing
 **********************************************************************/
Card::Card(int suitType, int cardNum)
{
	SetAll(suitType, cardNum);
}

//Destructor
Card::~Card()
{
}

/***********************************************************************
 * Method SetAll
 * -------------------------------------------------------------------
 * Sets all data (suit type and card number) for the card
 * 	returns -> nothing
 **********************************************************************/
void Card::SetAll(int suitType, int cardNum)
{
	suit = suitType;
	value = cardNum;
}

/***********************************************************************
 * Method GetSuit
 * -------------------------------------------------------------------
 * Gets the suit type of the card
 * 	returns -> integer value of suit type
 **********************************************************************/
int Card::GetSuit()
{
	return suit;
}

/***********************************************************************
 * Method GetValue
 * -------------------------------------------------------------------
 * Gets the number value of the card
 * 	returns -> string of card number
 **********************************************************************/
string Card::GetValue()
{
	string cardValue;

	switch(value)
	{
	case 0:  cardValue = "Ace";
			 break;
	case 1:  cardValue = "2";
			 break;
	case 2:  cardValue = "3";
			 break;
	case 3:  cardValue = "4";
			 break;
	case 4:  cardValue = "5";
			 break;
	case 5:  cardValue = "6";
			 break;
	case 6:  cardValue = "7";
			 break;
	case 7:  cardValue = "8";
			 break;
	case 8:  cardValue = "9";
			 break;
	case 9:  cardValue = "10";
			 break;
	case 10: cardValue = "Jack";
			 break;
	case 11: cardValue = "Queen";
			 break;
	case 12: cardValue = "King";
			 break;
	default: cardValue = "Undefined";
	}

	return cardValue;
}

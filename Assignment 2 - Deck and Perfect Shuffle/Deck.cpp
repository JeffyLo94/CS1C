/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	ASSIGN# 2 : Perfect Shuffle and Deck
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/2/2014
*******************************************************************************/

#include  "Card.h"
#include  "Deck.h"

//Constructor
Deck::Deck()
{
	ResetDecks();
}

//Destructor
Deck::~Deck()
{
}

/***********************************************************************
 * Method SplitDeck
 * -------------------------------------------------------------------
 * Splits the shuffled deck of cards in preparation for the perfect
 * shuffle
 * 	returns -> arrays by reference
 **********************************************************************/
void Deck::SplitDeck(Card lower[], Card higher[])
{
	int lowCount; //holds index value for lower array
	int highCount; //holds index value for higher array
	lowCount = 0;
	highCount = 0;

	//Processing loops until index whole deck is split
	for(int index = 0; index < 52; index++)
	{
		if(index < 26)
		{
			lower[lowCount] = shuffleDeck[index];
			lowCount++;
		}
		else
		{
			higher[highCount] = shuffleDeck[index];
			highCount++;
		}
	}
}

/***********************************************************************
 * Method PerfectShuffle
 * -------------------------------------------------------------------
 * Performs a perfect shuffle and modifies shuffleDeck
 * 	returns-> nothing
 **********************************************************************/
void Deck::PerfectShuffle()
{
	Card lowHalf[26]; //Card array for lower half
	Card upHalf[26];  //Card array for upper half
	int	 index;		  //Holds the index for the deck
	int  lowCount=0;
	int  upCount=0;

	//SplitDeck - Splits the deck and returns two arrays
	SplitDeck(lowHalf, upHalf);

	//Processing - loops until whole deck is shuffled
	for(index = 0; index < 52; index++)
	{
		if(index % 2 == 0)
		{
			shuffleDeck[index] = lowHalf[lowCount];
			lowCount++;
		}
		else
		{
			shuffleDeck[index] = upHalf[upCount];
			upCount++;
		}
	}
}

/***********************************************************************
 * Method ResetDecks
 * -------------------------------------------------------------------
 * Resets shuffled and original decks
 * 	returns-> nothing
 **********************************************************************/
void Deck::ResetDecks()
{
	int	index;
	int number;
	suitType suit;

	//Resetting Original Deck
	for(index = 0; index < 52; index++)
	{
		if(index < 13)
		{
			suit = CLUBS;
			origDeck[index] = Card(suit, index);
		}
		else if(index < 26)
		{
			suit = DIAMONDS;
			number = index - 13;
			origDeck[index] = Card(suit, number);
		}
		else if(index < 39)
		{
			suit = HEARTS;
			number = index - 26;
			origDeck[index] = Card(suit, number);
		}
		else if(index < 52)
		{
			suit = SPADES;
			number = index - 39;
			origDeck[index] = Card(suit, number);
		}
	}

	//Resetting Original Deck
	for(index = 0; index < 52; index++)
	{
		if(index < 13)
		{
			suit = CLUBS;
			shuffleDeck[index] = Card(suit, index);
		}
		else if(index < 26)
		{
			suit = DIAMONDS;
			number = index - 13;
			shuffleDeck[index] = Card(suit, number);
		}
		else if(index < 39)
		{
			suit = HEARTS;
			number = index - 26;
			shuffleDeck[index] = Card(suit, number);
		}
		else if(index < 52)
		{
			suit = SPADES;
			number = index - 39;
			shuffleDeck[index] = Card(suit, number);
		}
	}
}

/***********************************************************************
 * Method DisplayOrigDeck
 * -------------------------------------------------------------------
 * Displays the cards in the deck into the specified stream
 * 	returns -> cards in deck to ostream variable
 **********************************************************************/
void Deck::DisplayOrigDeck(ostream& os)
{
	int index;
	int cardSuit;

	os << "Original Deck:\n";

	//Processing - loops through whole deck to display each card
	for(index = 0; index < 52; index++)
	{
		cardSuit = origDeck[index].GetSuit();

		switch(cardSuit)
		{
		case CLUBS: os << origDeck[index].GetValue() << " of Clubs"
					   << endl;
			break;
		case DIAMONDS: os << origDeck[index].GetValue() << " of Diamonds"
						  << endl;
			break;
		case HEARTS: os << origDeck[index].GetValue() << " of Hearts" << endl;
			break;
		case SPADES: os << origDeck[index].GetValue() << " of Spades" << endl;
			break;
		default: os << "** ERROR - Suit Undefined **\n";
		}
	}

	os << endl;
}

/***********************************************************************
 * Method DisplayShuffleDeck
 * -------------------------------------------------------------------
 * Displays the cards in the deck into the specified stream
 * 	returns -> cards in deck to ostream variable
 **********************************************************************/
void Deck::DisplayShuffleDeck(ostream& os)
{
	int index;
	int cardSuit;

	os << "Shuffled Deck:\n";

	//Processing - loops through whole deck to display each card
	for(index = 0; index < 52; index++)
	{
		cardSuit = shuffleDeck[index].GetSuit();

		switch(cardSuit)
		{
		case CLUBS: os << shuffleDeck[index].GetValue() << " of Clubs"
					   << endl;
			break;
		case DIAMONDS: os << shuffleDeck[index].GetValue() << " of Diamonds"
						  << endl;
			break;
		case HEARTS: os << shuffleDeck[index].GetValue() << " of Hearts"
						<< endl;
			break;
		case SPADES: os << shuffleDeck[index].GetValue() << " of Spades"
						<< endl;
			break;
		default: os << "** ERROR - Suit Undefined **\n";
		}
	}

	os << endl;
}

/***********************************************************************
 * Method CompareDeckDiff
 * -------------------------------------------------------------------
 * Compares and finds the number of differences in the decks
 * 	returns -> number of differences in the deck
 **********************************************************************/
int Deck::CompareDeckDiff()
{
	int index;
	int diffCounter;

	diffCounter = 0;

	//Processing - loops through whole deck and compares differences
	//			   in suit and card value
	for(index = 0; index < 52; index++)
	{
		if(origDeck[index].GetSuit() != shuffleDeck[index].GetSuit() &&
		   origDeck[index].GetValue() != shuffleDeck[index].GetValue())
		{
			diffCounter++;
		}
	}

	return diffCounter;
}

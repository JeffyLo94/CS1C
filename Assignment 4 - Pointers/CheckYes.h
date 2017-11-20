/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*******************************************************************************/

#ifndef CHECKYES_H_
#define CHECKYES_H_


/*******************************************************************************
 *	CheckYes
 *	---------------------------------------------------------------------------
 *		This contains all prototypes for the CheckYes functions.
 ******************************************************************************/
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

/*******************************************************************************
 * FUNCTION CheckYes
 * ---------------------------------------------------------------------------
 *		This function takes in a string and checks if user really wants that
 *	string to be input.
 *	-> RETURNS: true or false
 ******************************************************************************/
bool CheckYes(string someStr);

/*******************************************************************************
 * FUNCTION CheckYes
 * ---------------------------------------------------------------------------
 *		This function takes in a int and checks if user really wants that
 *	integer to be input.
 *	-> RETURNS: true or false
 ******************************************************************************/
bool CheckYes(int someInt);



#endif /* CHECKYES_H_ */

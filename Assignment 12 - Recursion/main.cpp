/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #12 : Recursion
*	CLASS      : CS1C
*	SECTION    : 6-10p T-Th
*	DUE DATE   : 11/13/2014
*******************************************************************************/

#include "AssignTwelve.h"
using namespace JeffreyLo;

//G L O B A L   C O N S T A N T S
const string ALPHABET = "abcedefghijklmnopqrstuvwxyz";

// P R O T O T Y P E S
/******************************************************************************
 * getInput
 * ---------------------------------------------------------------------------
 * 	Obtains two integers from console. Function error checks that integers are
 * 	within ALPHABET string indices and integers are input. If invalid,
 * 	function recursively calls itself until user inputs are valid.
 * 	Returns: two integers
 *****************************************************************************/
void getInput( int &first, int &last );
/******************************************************************************
 * reverse
 * ---------------------------------------------------------------------------
 * 	reverses elements in the string from specified starting index to the
 * 	ending index.
 * 	Returns: reversed string
 *****************************************************************************/
string reverse( const string LETTERS, int start, int end );

int main(){

	OutputHeader(NAME,CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	// V A R I A B L E   L I S T
	int    start;
	int	   end;

	getInput(start, end);

	// 13 - 20
	cout << "Performing Reverse for indices " << start << " to " << end
		 << "..." << endl;
	cout << reverse(ALPHABET, start, end) << endl << endl;

	getInput(start, end);

	// 6 - 22
	cout << "Perform Reverse for indices " << start << " to " << end
		 << "..." << endl;
	cout << reverse(ALPHABET , start, end) << endl << endl;

	cout << "Perform Reverse on whole alphabet" << endl;
	cout << reverse(ALPHABET, 0, 26);


	return 0;
}


// F U N C T I O N S
void getInput( int &first, int &last ){
	try{
		bool invalid = false;
		do{
			cout << "Input starting index: ";
			if(!(cin >> first))
			{
				cout << endl;
				cout << "**** Please input a NUMBER ****\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				invalid = true;
			}

			if(first < 0 || first > ALPHABET.length()){
				throw first;
			}
		}while(invalid);

		do{
			cout << "Input ending index: ";
			if(!(cin >> last))
			{
				cout << endl;
				cout << "**** Please input a NUMBER ****\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				invalid = true;
			}
			if(last < 0 || last > ALPHABET.length()){
				throw last;
			}
		}while(invalid);

	}
	catch(int wrongInt){
		cout << "ERROR - INPUT not within bounds" << endl << endl;
		getInput( first, last );
	}
}

string reverse( const string LETTERS, int start, int end ){
	string reverseStr = LETTERS;

	if (start >= end ){
		return reverseStr;
	}
	else{

		char temp = reverseStr[start];
		reverseStr[start] = reverseStr[end];
		reverseStr[end] = temp;

		return reverse( reverseStr, start+1, end-1);
	}

}

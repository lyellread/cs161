
#include <iostream>
using namespace std;

/*********************************************************************
** Function: a_to_i
** Description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returns the decimal value of the character
*********************************************************************/

int a_to_i (char character){

	return int(character);

}

/*********************************************************************
** Function: i_to_a
** Description: turns a decimal value into a character value
** Parameters: int ascii
** Pre-Conditions: the input is an integer
** Post-Conditions: returns the character which represents the decimal value
*********************************************************************/

char i_to_a (int ascii){

	return char(ascii);

}

/*********************************************************************
** Function: main
** Description: calls a_to_i and i_to_a a couple times
** Parameters: none
** Pre-Conditions: na
** Post-Conditions: returns 1 for success
*********************************************************************/

int main(){

	char ascii_from_int;
	int int_from_ascii;

	ascii_from_int = i_to_a(99);
	int_from_ascii = a_to_i('#');

	cout << "The Ascii Value for int 99 is: " << ascii_from_int << "\n";
	cout << "The Int value for the ascii '#' is: " << int_from_ascii << "\n";
	
	return 1;

}	

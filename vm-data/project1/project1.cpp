/*********************************************************************
** Program Filename: project1.cpp
** Author: Lyell Read
** Date: 09-29-2018
** Description: Working with max and min sizes for n- byte binary numbers
** Input: User inputted int
** Output: Various lines of text
*********************************************************************/


#include <iostream>
#include <cmath>
#include <climits>


using namespace std;


const int INT_ALL_MIN = 0;



/*********************************************************************
** Function: doAll
** Description: Does the default operation to calculate max and min values for signed and unsigned int, short and long
** Parameters: None
** Pre-Conditions: NA
** Post-Conditions: NA
*********************************************************************/ 



void doAll () {
	
	// (max, min) (signed, unsigned) int
	
	cout << "\n\nInteger (int) Values:\n---------------------\n+Max Signed:    " << INT_MAX << endl;
	cout << "+Min Signed:   " << INT_MIN << endl;
	cout << "+Max Unsigned:  " << UINT_MAX << endl; 
	cout << "+Min Unsigned:  " << INT_ALL_MIN << "\n\n" << endl;

	// (max, min) (signed, unsigned) long int
	
	cout << "Long Integer (long int) Values:\n---------------------\n+Max Signed:    " << LONG_MAX << endl;
	cout << "+Min Signed:   " << LONG_MIN << endl;
	cout << "+Max Unsigned:  " << ULONG_MAX << endl;
	cout << "+Min Unsigned:  " << INT_ALL_MIN << "\n\n" << endl;

	// (max,min) (signed, unsigned) short int

	cout << "Short Integer (short int) Values:\n---------------------\n+Max Signed:    " << SHRT_MAX << endl;
	cout << "+Min Signed:   " << SHRT_MIN << endl;
	cout << "+Max Unsigned:  " << USHRT_MAX << endl;
	cout << "+Min Unsigned:  " << INT_ALL_MIN << "\n\n" << endl;

}



/*********************************************************************
** Function: nBytes
** Description: calculate values for n- bytes, user entered. Called by main
** Parameters: byteCount
** Pre-Conditions: NA
** Post-Conditions: NA
*********************************************************************/ 



void nBytes (int byteCount) {
	
	int bitCount = 8 * byteCount;

	cout << "\n\nInteger with length " << bitCount << " bits has values values:\n---------------------" << endl;

	
	
	// Calculate (max, min) (signed, unsigned) values for a $byteCount long integer.
	
	//Max Signed: Signed Maximum (n bits): ((2^n)/2)-1
	
	unsigned long long int signedMax  = pow((long double)2,(bitCount))/2 - 1;

	cout << "+Max Signed:    " << signedMax << endl;



	/*
	 * Min Signed: Signed Minimum (n bits): -(2^n)/2. 
	 * Because this is calculated as an *unsigned* long long, the "-" must 
	 * be added manually. Calculating the values into a signed variable would 
	 * be impossible as the max number for an unsigned 8 byte int is nearly
	 * twice as big as the available space in a signed int. 
	 */
	
	unsigned long long int signedMin = pow((long double)2,(bitCount))/2;

	cout << "+Min Signed:   -" << signedMin << endl;



	//Max Unsigned: Unsigned Max Value Calculation (n bits): -1+2^n (you have 2^n values, but one is 0)
	
	unsigned long long int unsignedMax = pow((long double)2,(bitCount)) - 1;

	cout << "+Max Unsigned:  " << unsignedMax << endl;



	//Min Unsigned (0): Just 0. This is stored as INT_ALL_MIN

	int unsignedMin = INT_ALL_MIN;
	
	cout << "+Min Unsigned:  " << unsignedMin << endl;

	
	// Subtract 1 from Mins and add 1 to maxs "Wrong Calculation"


	cout << "\n\nOverflowing values by 1 using +/- on variables:\n---------------------" << endl;

	// Max Signed
	
	cout << "+Max Signed + 1:    " << signedMax + 1 << endl;

	// Min Signed

	cout << "+Min Signed - 1:    " << signedMin - 1 << endl;

	// Max Unsigned
	
	cout << "+Max Unsigned + :   " << unsignedMax + 1 << endl;

	// Min Unsigned
	
	cout << "+Min Unsigned - 1: " << unsignedMin - 1 << endl;



	// Subtract 1 from Mins and add 1 to maxs the manual but right way


	cout << "\n\nOverflowing values by 1 ''manually'':\n---------------------" << endl;

	// Max Signed
	
	cout << "+Max Signed + 1:   -" << signedMin << endl;

	// Min Signed

	cout << "+Min Signed - 1:    " << signedMax << endl;

	// Max Unsigned
	
	cout << "+Max Unsigned + :   " << unsignedMin << endl;

	// Min Unsigned
	
	cout << "+Min Unsigned - 1:  " << unsignedMax << endl;


}



/*********************************************************************
** Function: main
** Description: Start process, calls other fxns and does cin for user byre input as well as checking of that input
** Parameters: none
** Pre-Conditions: NA
** Post-Conditions: NA
*********************************************************************/ 



int main () {

	// Call doAll - this prints the default requirements
	
	doAll();

	// Seek user input for the number of bytes and check that it is within range
	
	int userBytes;

	cout << "Enter the number of bytes:\n---------------------\nBytes:";
	
	cin >> userBytes;

	
	//Extra Credit Portion (Inout checking):

	
	if (userBytes > 8) {
		cout << "ERROR: USER INPUT GREATER THAN MAX POSSIBLE (8).\nQuitting!" << endl;
		return 1;
	}
	

	else if (userBytes <= 0){
		cout << "ERROR: USER INPUT LESS THAN MIN POSSIBLE (1).\nQuitting!" << endl;
		return 1;
	}
	
	
	else{


		cout << "Bits:" << 8 * userBytes << endl;		
		

		if (userBytes == 2){

			cout << "This is the same as a short int" << endl;
		}


		else if (userBytes == 4){

			cout << "This is the same as an int" << endl;
		}


		else if (userBytes == 8){

			cout << "This is the same as a long int" << endl;
		}
		

		nBytes (userBytes);
	}
	
	
	return 0;

}

#include <iostream>
#include <string>
using namespace std;

/*
	Written by Justin Goins
	October 27th, 2018

	This program accepts a string from the user and locates the first numeric character (if present).
	When the first numeric character is located, the program computes a sum of all the ASCII values contained in the number
	(continuing to read the characters until encountering a non-numeric character or until reaching the end of the string).

	e.g. Entering "183" will print 156 since that is the sum of the ASCII values.
	e.g. Entering "183a" will still print 156 since that is the sum of the ASCII values of the numeric portion of the string.
*/
int main() {
	string user_str;

	while (true) {
		cout << "Please enter a string: " << endl;
		getline(cin, user_str);

		// quit if the user entered "q"
		if (user_str.length() == 1 && user_str[0] == 'q') {
			cout << "Goodbye!" << endl;
			return 0;
		}

		int sum = 0;
		// begin to iterate over the entire string
		for (int i = 0; i < user_str.length(); i++) {
			// search for a numeric character
			// note that this IF statement is comparing against the ASCII representation value
			// '0' = 48, '9' = 57
			if (user_str[i] >= 48 && user_str[i] <= 57) {
				// add this ASCII value to the sum
				sum += user_str[i];
			} else if (sum > 0) {
				// sum will remain at 0 unless we have discovered an integer.
				// If we discover a non-integer and sum is greater than 0 it must be time to stop.
				break;
			}
		}

		cout << "The ASCII sum is: " << sum << endl;
	}

	return 0;
}

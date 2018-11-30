#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/*
	Written by Justin Goins
	October 26th, 2018

	This program accepts a string from the user and searches for the substring "dog" or "cat".
	If "dog" is discovered, the program prints the index of the 'd' character.
	If "cat" is discovered, the program prints the index of the 't' character.
	Behavior is not specified when both words are present.
*/
int main() {
	string user_str;
	string secret1 = "dog";
	string secret2 = "cat";

	while (true) {
		cout << "Please provide a string: " << endl;
		getline(cin, user_str);

		// quit if the user entered "q"
		if (user_str.length() == 1 && user_str[0] == 'q') {
			cout << "Goodbye!" << endl;
			exit(0);
		}

		// use a flag to track our status
		bool found_secret = false;

		// try to find the first secret word
		for (int i = 0; i < user_str.length(); i++) {
			// iterate and look for the first character of the secret word
			if (user_str[i] == secret1[0]) {
				// if we found the first character, see if the rest of the word is present
				for (int j = 1; j < secret1.length(); j++) {
					// make sure we are not looking past the end of the string (which means a match is impossible)
					if (i+j >= user_str.length())
						break;
					// stop if the word is not matching
					if (user_str[i+j] != secret1[j])
						break;
					if (j == secret1.length()-1) {
						// the whole word matched!
						found_secret = true;
						// print index of 'd' in dog
						cout << "Congrats! Found secret entry at index " << i << "." << endl;
					}
				}
			}
		}

		if (!found_secret) {
			// try to find the second secret word
			for (int i = 0; i < user_str.length(); i++) {
				// iterate and look for the first character of the secret word
				if (user_str[i] == secret2[0]) {
					// if we found the first character, see if the rest of the word is present
					for (int j = 1; j < secret2.length(); j++) {
						// make sure we are not looking past the end of the string (which means a match is impossible)
						if (i+j >= user_str.length())
							break;
						// stop if the word is not matching
						if (user_str[i+j] != secret2[j])
							break;
						if (j == secret2.length()-1) {
							// the whole word matched!
							found_secret = true;
							// print index of 't' in cat
							cout << "Congrats! Found secret entry at index " << i+j << "." << endl;
						}
					}
				}
			}
		}

		if (!found_secret) {
			cout << "Sorry, could not locate secret words." << endl;
		}
	}

	return 0;
}

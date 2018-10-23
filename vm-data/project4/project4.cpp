

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cstdlib>


//CHECK: https://web.engr.oregonstate.edu/~goinsj/resources/CS161/demos/bin_to_dec.cpp

using namespace std;


int input_character_check (string input){
	for (int index=0; index<input.length(); index++){
		int current=int(input[index]);
		if (!((current == 32 || current == 42 || current == 43 || current == 45 || current == 47) || (current>=48 && current <= 57))){
			return 0;
		}
	}
	return 1;
}


int input_structure_check(string input){
	for (int index=0; index<(input.length()-1); index++){
		if ((int(input[index]) == 42 || int(input[index]) == 43 || int(input[index]) == 45 || int(input[index]) == 47) && (int(input[index+1]) != 32)){
			return 88; // operator not followed by a space
		}
		if ((int(input[index])>=48 && int(input[index]) <=57) && (int(input[index+1]) == 42 || int(input[index+1]) == 43 || int(input[index+1]) == 45 || int(input[index+1]) == 47)) {
			return 99; // number not followed by a space
		}
	}
	return 1;
}


int s_to_i (string input){
	int output=0;
	for (int str_index=0; str_index < input.length(); str_index++){
		
		int multiplier = input.length()-(str_index+1);
		int working_digit = int(input[str_index])-48;
		
		for (int iterator=0; iterator < multiplier; iterator++){
			working_digit*=10;
		}//this works by usign ones, tens, hundreds...
		
		output+=working_digit;
	}
	return output;

}

int main () {

	while (1){
		string google;
		getline(cin, google);
		cout << input_character_check(google) << " -- " << input_structure_check(google) <<  endl;
	}

}	

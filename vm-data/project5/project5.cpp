

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cstdlib>


using namespace std;



// #####################
// #HOMEMADE CONVERTERS#
// #####################


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



// #####################
// #INPUT CHECKING FXNS#
// #####################


int string_Is_Int (string input){
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) return 0;
	}
	return 1;
}

int parameter_Check(string parameter){
	if (string_Is_Int(parameter)){
		return s_to_i (parameter);
	}
	else{
		cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS NOT A NUMBER" << endl;
		exit(EXIT_FAILURE);
	}
}		



// #####################
// #YAHTZEE SPECIFIC FX#
// #####################

int length_Of(int * arr){
	cout << sizeof(arr) << endl;
	return sizeof(*arr)/sizeof(arr[0]);
}
/*
int sum_Of(int arr[]){
	int result=0;
	for (int index=0; index< ; ++index){
		result += arr[index];
	}
	return result;
}
	

int q_Of_n (int n, int dice[]){
	int counter = 0; 
	cout << dice << endl;
	for (int index=0; index< dice.size(); ++index){
		cout << dice[index];
		if (dice[index] == n){
			++counter;
		}
	}
	return counter;
}	


int n_Of_A_Kind (int n, int * dice){
	int result = 0;
	for (int number = 1; number < 7; ++number){
		cout << "Dice: " << dice << "  Number: " << number << "  and QOFNL " << q_Of_n(number, dice) << endl;
		if (q_Of_n(number, dice) >= n){
			return sum_Of(dice);
		}
	}
	return 0;
}

*/
int main(int argc, char ** argv){
	if (argc == 2){
		
		int result;
		//result = parameter_Check(argv[1]);
		
		int myarray[5] = {1,2,2,2,3};
		//result = n_Of_A_Kind(3, myarray);
		cout << sizeof(myarray) << endl;
		result = length_Of(myarray);
		cout << "Result" << result << endl;
		
	}
	else{
	cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS EITHER BLANK OR OVERFULL" << endl;
	exit(EXIT_FAILURE);
	}
}
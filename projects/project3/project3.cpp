/*********************************************************************
** Program Filename:project3.cpp
** Author:Lyell C Read
** Date:10/17/2018
** Description:An Algebra Game Yay
** Input:User input
** Output:Text output
*********************************************************************/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cstdlib>


using namespace std;


/*********************************************************************
** Function:rand_int
** Description:Makes a random integer on a specific range
** Parameters:min and max for the output
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int rand_int (int min, int max){

	int n = (max-min)+1;
	
	return (rand()%n)+min;
}


/*********************************************************************
** Function:s_to_i
** Description:stoi recoded to meet requirements
** Parameters:string
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


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


/*********************************************************************
** Function:input_check
** Description:checks that input is an int on range
** Parameters:range min, range max
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int input_check(int acceptable_min, int acceptable_max){

	string input;
        int return_value;
	bool negative=false;

	getline(cin, input);
        
	int len = input.length();
	
	//check for length 0 AKA just a return

	if (len == 0){
		//for loop would not trigger as len = 0, and stoi would dump core :(
		cout << "Length was 0. Please re-enter!:";
		return input_check(acceptable_min, acceptable_max);
	}
	
	//check for a negative sign, then set a flag for it so that s_to_i doesnt have to work with it

	if (input[0]== '-'){
	       	negative = true;
		input.erase(input.begin());
		len = input.length();
	}
	
	//check that each character is an int

	for (int i=0; i< len;i++){
                if (int(input[i]) < 48 || int(input[i]) > 57){
                	cout << "Invalid Character Found, Re-Enter:";
			return input_check(acceptable_min, acceptable_max);
		}
        }
	
	return_value = s_to_i(input);	

	//if it is negative, add that on now
	
	if (return_value <= acceptable_max && return_value >= acceptable_min && negative){
		return -1* return_value;
	}
	
	// its not negative, and in range
	
	else if (return_value <= acceptable_max && return_value >= acceptable_min){
		
		return return_value;
	}
	
	//its not in range :(

	else{
		cout << "Invalid. Again:";
		return input_check(acceptable_min, acceptable_max);
		//recursively call this again on and on...
	
	}

}

/*********************************************************************
** Function:display_equation
** Description:displays an equation, calls input_check
** Parameters:type, min and max
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 

int display_equation(int eq_type, int range_low, int range_high){
		
	int a = rand_int(range_low, range_high);
	int b = rand_int(range_low, range_high);
	int result;
	int user_ans;
	switch (eq_type){
		case 1:{
			//addition x + a = a+b sol = b
			

			cout << "\nWhat is the correct result of the operation x + " << a <<" = " << a+b << "? :";
			user_ans = input_check(INT_MIN, INT_MAX);
			result = b;
	       	        break;
		       
		       }
	
	
		case 2:{
			//subtraction x - b = a-b sol = a
			cout << "\nWhat is the correct result of the operation x - " << b <<" = " << a-b << "? :";
			user_ans= input_check(INT_MIN, INT_MAX);
			result = a;
	       	        break;
		       
		       }
	
	
		case 3:{
			//multiplication
			cout << "\nWhat is the correct result of the operation x * " << b << " = " << a*b <<"? :";
			user_ans= input_check(INT_MIN, INT_MAX);
			result = a;
	       	        break;
		       
		       }
	

		case 4:{
			//division
			b=rand_int((range_low/4), (range_high/4));
			
			int c = a * b;
			
			cout << "\nWhat is the correct result of the operation x / " << b << " = " << a << "? :"; 
			user_ans = input_check(INT_MIN, INT_MAX);
			result = a*b;
	       	        break;
		       
		       }
		}
	
	
	if (user_ans == result){
		return true;
	
	}
	else{
		return false;
	
	}
	

}


/*********************************************************************
** Function:display_floor
** Description:prints the required ascii art
** Parameters:current, max floors
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void display_floor (int current_floor, int max_floor){
;	
	cout << "\n\n";

	for (int index = max_floor; index>0; --index){


		if (index == current_floor){

			cout << "|```[X]```|\n";
		}
		
		else{
			cout << "|`````````|\n";

		}
	}	
	
	cout << "'`````````'\n\n" << endl;
}


/*********************************************************************
** Function:main
** Description:commands the program, restarts the game...
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int main (){
	

	srand(time(NULL));

	int cont = 1;
	int floor_curr = 1;
	int floor_max;
	int difficulty;
	int operation;
	int result;
	int range_low = 0;
	const int range_high = 100;

	while (cont == 1){
		
		cout << "Welcome to the Tower of Math!\n\nWhat difficulty would you like (0- easy, 1- hard):";
		difficulty = input_check(0,1);
		floor_curr = 1;
		range_low=0;

		if (difficulty){
			range_low = -100;
		}
		
		cout << "\nThanks! Now how many floors?(min. 4):";
		floor_max = input_check(4,100);

		while (floor_curr > 0 && floor_curr < floor_max ){
			
			display_floor(floor_curr, floor_max);

			if (difficulty == 0){
				cout << "\nWhat operation for this floor?(1- add, 2- sub, 3- mul, 4- div):";
				operation = input_check(1,4);
			}
			else{
				operation = rand_int(1,4);
			}

			result = display_equation(operation, range_low, range_high);

			if (result){
				floor_curr++;
			}
			else{
				floor_curr--;
			}
		}
		if (floor_curr >1){
			cout << "\nCongratulations, you are victorious!"<< endl;
		}
		else{
			cout << "\nEpic Fail!" << endl;
		}
		cout << "\nPlay again? (1- or 0-):";
		cont=input_check(0,1);
	}


}

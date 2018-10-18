#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cstdlib>

using namespace std;


int rand_int (int min, int max){

	int n = (max-min)+1;
	
	return (rand()%n)+min;
}


int s_to_i (string input){
	int output=0;
	cout << "STOI START" << endl;	
	for (int str_index=0; str_index < input.length(); str_index++){
		
		int multiplier = input.length()-(str_index+1);
		int working_digit = int(input[str_index])-48;
		
		for (int iterator=0; iterator < multiplier; iterator++){
			working_digit*=10;
		}
		
		output+=working_digit;
	}
	cout << "STOI OUT: " << output << endl;
	return output;
}



int input_check(int acceptable_min, int acceptable_max){

	string input;
        int return_value;
	bool negative=false;

	getline(cin, input);
        
	int len = input.length();
	
	if (len == 0){
		//for loop would not trigger as len = 0, and stoi would dump core :(
		cout << "RETURNING ERROR" << endl;
		return INT_MAX;
	}
	
	if (input[0]== '-'){
	       	negative = true;
		input.erase(input.begin());
		len = input.length();
	}

	cout << "INPUT AFTER HYP EDIT: "<< input << endl;

	cout << "Neegative" << negative << endl;

	for (int i=0; i< len;i++){
		cout << "this loop working with >" << input[i] << "<" << endl;
                if (int(input[i]) < 48 || int(input[i]) > 57){
			cout << "RETURNING INTMAX ERROR" << endl;
                	return INT_MAX;
		}
		cout << "FOR" << endl;
        }
	
	return_value = s_to_i(input);	

	if (return_value <= acceptable_max && return_value >= acceptable_min && negative){
       		cout << "Ret Neg: " << -1*return_value << endl;
		return -1* return_value;
	}
	
	else if (return_value <= acceptable_max && return_value >= acceptable_min){
		
		cout << "RET STAN " << return_value << endl;
		return return_value;
	}
	
	else{
		cout << "ERR" << endl;
		return INT_MAX;
	}

}



int display_equation(int eq_type, int range_low, int range_high){
		
	int a = rand_int(range_low, range_high);
	int b = rand_int(range_low, range_high);
	int result;
	int user_ans;
	switch (eq_type){
		case 1:{
			//addition
			cout << "What is the correct result of the operation " << a << " + " << b <<"? :";
			user_ans = input_check(INT_MIN, INT_MAX);
			result = a+b;
	       	        break;
		       
		       }
	
	
		case 2:{
			//subtraction
			cout << "What is the correct result of the operation " << a << " - " << b <<"? :";
			user_ans= input_check(INT_MIN, INT_MAX);
			result = a-b;
	       	        break;
		       
		       }
	
	
		case 3:{
			//multiplication
			cout << "What is the correct result of the operation " << a << " * " << b <<"? :";
			user_ans= input_check(INT_MIN, INT_MAX);
			result = a*b;
	       	        break;
		       
		       }
	

		case 4:{
			//division
			b=rand_int(range_low, range_high);
			
			int c = a * b;
			cout << "What is the correct result of the operation " << c << " / " << b <<"? :";
			user_ans = input_check(INT_MIN, INT_MAX);
			result = a;
	       	        break;
		       
		       }
		}
	
	cout << "Current User Answer is:" << user_ans << ", and correct solution is said to be:" << result << endl;
	
	
	
	if (user_ans == result){
		cout << "true" << endl;	
		return true;
	
	}
	else{
		cout << "false" << endl;	
		return false;
	
	}
	

}

void display_floor (int current_floor, int max_floor){
	

	for (int index = max_floor; index>0; --index){


		if (index == current_floor){

			cout << "|```[X]```|\n";
		}
		
		else{
			cout << "|`````````|\n";

		}
	}	
	
	cout << "'`````````'" << endl;
}


int main (){
	

	srand(time(NULL));
	cout << display_equation(2, -100, 100)<<endl;

	cout << display_equation(1, -100, 100)<<endl;

	cout << display_equation(3, -100, 100)<<endl;

	cout << display_equation(4, -100, 100)<<endl;

	cout << display_equation(3, -100, 100)<<endl;

	cout << display_equation(4, -100, 100)<<endl;

	cout << display_equation(2, -100, 100)<<endl;

	cout << display_equation(1, -100, 100)<<endl;

}

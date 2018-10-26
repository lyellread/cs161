
/*********************************************************************
** Program Filename:project4.cpp
** Author:Lyell C Read
** Date:10/23/2018
** Description:A medle of a program. Can convert bin to dec. Can calculate weighted averages. Can evaluate equations as well.
** Input:User input
** Output:Text output
*********************************************************************/



//TODO: rework the eq input and evaluation, add a function to average grades unweighted



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cstdlib>


using namespace std;


/*********************************************************************
** Function:s_to_i
** Description:string to integer
** Parameters:string input
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int s_to_i (string input){
	int output = 0;
	for (int str_index = 0; str_index < input.length(); str_index++){
		
		int multiplier = input.length() - (str_index + 1);
		int working_digit = int(input[str_index]) - 48;
		
		for (int iterator = 0; iterator < multiplier; iterator++){
			working_digit *= 10;
		}//this works by usign ones, tens, hundreds...
		
		output += working_digit;
	}
	return output;

}


/*********************************************************************
** Function:b_to_i
** Description:turns a binary into an integer
** Parameters:string input
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int b_to_i (string input){
	int multiplier = 1;
	int total = 0;
	
	for (int index = input.length() - 1; index >= 0; index--){
		total += multiplier * (input[index] - 48);
		multiplier *= 2;
	}
	return total;
}


/*********************************************************************
** Function:input_character_check
** Description:checks for illegal characters in input
** Parameters:string input
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int input_character_check (string input){
	for (int index = 0; index < input.length(); index++){
		int current=int(input[index]);
		if (!((current == 32 || current == 42 || current == 43 || current == 45 || current == 47) || (current >= 48 && current <= 57))){
			return 0;
		}
	}
	return 1;
}


/*********************************************************************
** Function:input_structure_check
** Description:checks that there are spaces in the input
** Parameters:string input
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int input_structure_check(string input){
	for (int index = 0; index<(input.length() - 2); index++){
		if (((int(input[index]) == 42 || int(input[index]) == 43 || int(input[index]) == 45 || int(input[index]) == 47) && (int(input[index+1]) != 32)) || ((int(input[index])>=48 && int(input[index]) <=57) && (int(input[index + 1]) == 42 || int(input[index + 1]) == 43 || int(input[index + 1]) == 45 || int(input[index + 1]) == 47))){
			cout << "ERROR - OPERATOR OR NUMBER NOT FOLLOWED BY A SPACE! BREAKING\n\n";
			return 0; // operator or number not followed by a space
		}
		if 
		if (((int(input[index]) == 42 || int(input[index]) == 43 || int(input[index]) == 45 || int(input[index]) == 47) && (int(input[index+2]) == 42 || int(input[index+2]) == 43 || int(input[index+2]) == 45 || int(input[index+2]) == 47)) || ((int(input[index])>=48 && int(input[index]) <=57) && (int(input[index+1]) == 32) && (int(input[index+2])>=48 && int(input[index+2]) <=57))) {
			cout << "ERROR - NUMBERS OR OPERATOR SEPARATED BY A SPACE :(\n\n";
			return 0; // number not followed by a space
		}
	}
	return 1;
}


/*********************************************************************
** Function:eq_GetOperator
** Description:will return the current next operator as a char, and removes that from the head of the string
** Parameters:string &equation
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


char eq_GetOperator(string &equation){
	char temp;
	temp = equation[0];
	equation.erase(0,2);
	return temp;
}


/*********************************************************************
** Function:eq_GetNumber
** Description:Gets the next number of the equation. This also removes that from the head of the string.
** Parameters:string &equation
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 	

	
int eq_GetNumber(string &equation){
	int end_flag = 0;
	for (int i = 0; i<equation.length(); i++){
		if (equation[i] != ' '){
			end_flag += 1;
		}
		else{
			break;
		}
	}
	string temp = equation.substr(0,end_flag);
	equation.erase(0,end_flag+1);
	return s_to_i(temp);
}


/*********************************************************************
** Function:eq_Splitter
** Description:gets the operator and the integers. increases the total by the appropriate number.
** Parameters:int total, string &equation
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int eq_Splitter(int total, string &equation){
	char op = eq_GetOperator(equation);
	int target = eq_GetNumber(equation);
	if (op == '*') return (total * target);
	if (op == '+') return (total + target);
	if (op == '-') return (total - target);
	if (op == '/') return (total / target);
}


/*********************************************************************
** Function:eq_Orchestrator
** Description:Orchestrates the equation solving operations
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void eq_Orchestrator (){
	string equation;
	cin.ignore();
	cout << "Equation with Spaces: ";
	getline(cin, equation);
	
	int total = eq_GetNumber(equation);

	if (input_character_check(equation) && input_structure_check(equation)){
		int len = equation.length();
		while (len > 2){
			total = eq_Splitter(total, equation);
			len = equation.length();
		}
		cout << "Total came to: " << total << endl;
	}
	else{
		cout << "ERROR - ENTERED EQUATION IMPROPERLY FORMATTED. BREAKING";
	}
}


/*********************************************************************
** Function:checkBin
** Description:Makes sure that a number is a binary number
** Parameters:string input
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int checkBin(string input){

	int inputLength = input.length();

	for (int i = 0; i < inputLength; i++){

		int current = int(input[i]);
		if (!(current == 48 || current == 49)){
			return 0;
		}		
	}
	return 1;
}


/*********************************************************************
** Function:bin_Orchestrator
** Description:orchestrates the binary conversion process
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void bin_Orchestrator (){ 
	string bin;
	int integer;
	cout << "Please enter your binary number here:";
	cin.ignore();
	getline(cin, bin);
	if (checkBin(bin)){
		integer = b_to_i(bin);
		cout << "Your binary is: " << integer << " in BASE10";
	}
	else{
		cout << "ERROR - ENTERED NUMBER NOT BINARY! BREAKING\n\n";
	}
}


/*********************************************************************
** Function:weightedAverage
** Description:calculates the weighted average.
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void weightedAverage(){
	int count;
	double weight, grade, result = 0;
	cin.ignore();
	cout << "How many grades? :";
	cin >> count;
	for (count; count > 0; count--){
		cout << "Grade:";
		cin >> grade;
		cout << "Weight:";
		cin >> weight;
		result += (((grade / 100) * (weight / 100)) * 100);
	}
	cout << "Final Score: " << result << endl;
}


/*********************************************************************
** Function:menu
** Description:Displays the menu and iterates repeatedly
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void menu(){
	int choice = 0;
	
	while (1 == 1){
		cout << "\n\nProgram 4 Tool Menu: \n\n [1] - Convert a Binary Value to an Integer Value\n [2] - Calculate Grade Averages\n [3] - Process an Equation\n [4] - Quit this Program\n\nChoice:";
		cin >> choice;
		switch (choice){
			case 1:
				bin_Orchestrator();
				break;
			case 2: 
				weightedAverage();
				break;
			case 3:
				eq_Orchestrator();
				break;
			default:
				exit(0);
		}
	}
}


/*********************************************************************
** Function:main
** Description:calls menu for neatness
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int main () {

	menu();

}	



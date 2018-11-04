
/*********************************************************************
** Program Filename:project4.cpp
** Author:Lyell C Read
** Date:10/23/2018
** Description:A medley of a program. Can convert bin to dec. Can calculate weighted averages. Can evaluate equations as well.
** Input:User input
** Output:Text output
*********************************************************************/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <climits>
#include <ctime>
#include <cstdlib>


using namespace std;


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
** Function:do_operation
** Description:solves the operation of total (+|-|/|*) operate_by and total is passed by reference, so it can be a void
** Parameters:double &total, char op, double operate_by
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void do_operation (double &total, char op, double operate_by){
	if (op == '+') total += operate_by;
	if (op == '-') total -= operate_by;
	if (op == '/') total /= operate_by;
	if (op == '*') total *= operate_by;
}


/*********************************************************************
** Function:evaluate
** Description:called by evaluate, evaluates the equation
** Parameters:string str (the equation)
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


int evaluate(string str){
	
	char cstr[str.size()+1]; char * pch; bool operand=true; double total=0; char op;

	strcpy(cstr, str.c_str()); pch = strtok(cstr, " ");
	if (string(pch).find_first_not_of("1234567890-.")== string::npos && string(pch) != "-") total += stod(pch);
	else {cout << "INVALID VALUE:" << pch << endl; return 0;}
	
	pch=strtok(NULL, " ");
	while (pch != NULL){
		if (operand && (string(pch).find_first_not_of("+-/*")== string::npos) && string(pch).length() == 1) op=*pch;
		
		else if (operand == false && string(pch).find_first_not_of("1234567890-.")== string::npos) do_operation(total, op, stod (pch));
		
		else{cout << "INVALID VALUE:" << pch << endl;return 0;}
		
		operand = !operand;
		pch = strtok(NULL, " ");
	}
	if (operand) cout << "The total is: " << total << endl;
	return int(operand); // will be false if the last character found was an operator
	
}	

	
/*********************************************************************
** Function:eq_Orchestrator
** Description:Orchestrates the equation solving operations
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 


void eq_Orchestrator (){
	string equation; int outcome;
	cin.ignore();
	cout << "Equation with Spaces: ";
	getline(cin, equation);
	if (equation == "") return;
	outcome = evaluate(equation);
	while (outcome != 1){
	
	cout << "Processing Failed; Equation with Spaces: ";
	getline(cin, equation);	
	if (equation == "") return;
	
	outcome = evaluate(equation);	
		
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



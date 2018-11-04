#include <iostream>
//#include <string.h>
#include <string>
#include <cstring>
using namespace std;

int main () {
	
	int r4; double c4; string jj6; char * boos;
	
	while (1){


		cout << "Input:";

		string str;

		getline(cin, str);
		cout << str << endl;
		char cstr[str.size()+1];

		strcpy(cstr, str.c_str());

		cout << cstr << endl;

		char * pch;
		
		pch = strtok(cstr, " ");
		bool operand=false;
		while (pch != NULL){
				
				cout << pch << " --- " << operand << endl;
				if (operand && (string(pch).find_first_not_of("+-/*")== string::npos) && string(pch).length() == 1){
					cout << "Valid Operator:" << pch << endl;
					char op = *pch;
					cout << "Char Created:" << op << " with int value:" << int(op) << endl;
	
				}
				else {
					if (operand == false && string(pch).find_first_not_of("1234567890.")== string::npos){
					cout << "Valid Number:" << pch << endl;
					double base = stod (pch);
					cout << "Created Double:" << pch << endl;
					}
				
					else{
						cout << "INVALID VALUE:" << pch << endl;
					}
				}
				operand = !operand;
				pch = strtok(NULL, " ");
		}
	
		cout << str << endl;

		cout << cstr << endl;

		}	
		
}
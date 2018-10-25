#include <iostream>
//#include <string.h>
#include <string>
#include <cstring>
using namespace std;

int main () {
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
		while (pch != NULL){
		        cout << pch << endl;
	       		pch = strtok(NULL, " ");
		}
	}
}	

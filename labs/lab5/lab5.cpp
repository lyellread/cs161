#include <iostream>
#include <string>

using namespace std;

void getSent (string &s){

	cout << "Text Here: ";

	getline(cin, s);

}

int main (){

	string s;
	getSent(s);
	cout << s << endl;
	
}

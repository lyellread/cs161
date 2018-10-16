/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream> // Bug 1 Found here. corrected from iostraem to iostream
#include <stdio.h>
#include <stdlib.h>

using namespace std; //added this line to fix bug 2 - lack of standard namespace declaration.

int main(){

	int x=3, y;
	int myAnswer;

	int again; //bug 3 there was no definition of this variable.

	y = x;
	cout << "y is set to: " << y << endl;

	cout << "Please input a number: ";
	cin >> y;//bug 15 wrong direction << instead of >>
	again = 1; //bug 4 missing semicolon, bug 12 declaring it as int not bool
	while(again == 1){//bug 7 using int not bool or char
		if(x > y){//bug 20 lacking braces
			cout << "X is greater than Y\n";
			cout << "would you like to input another number?(y-1 or n-0)" << endl;//bug 5 no quotes, bug 16 backwards >> before endl
			cin >> again;
		}
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?(y-1 or n-0)" <<  endl;// bug 17 backwards << before endl
			cin >> again;
		}
	}
	for(x = 0; x < 10; x+1)
		cout << x << endl;
	int num; //num was not defined bug 8
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num;//bug 13 - no semicolon
	for(int x = num; x > 0; x--)
		x = x * x;
	
	cout << "Are you enjoying cs161? (y-1 or n-0) " << endl;
	cin >> myAnswer;//bug 11 myanswer --> myAnswer
	if(myAnswer == 1){//bug 19: lacking braces, bug 14 is that there was only one equals sign. y is not variable, setting to char. but 9, and bug 10: myanswer --> myAnswer
		cout << "Yay!" << endl;
	}
	else{//bug 18: lacking braces
		cout << "I hope you will soon!" << endl;
	}
	return 0;

} //bug 6 lacking closing brace :(

/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream> // Bug 1 Found here. corrected from iostraem to iostream
#include <stdio.h>
#include <stdlib.h>

using namespace std; //added this line to fix bug 2 - lack of standard namespace declaration.

int main(){
	
   	int x=3;
	int num;
	int myAnswer;
	int y;
	int again=1; //bug 3 there was no definition of this variable.
	unsigned long long factorial = 1;
	int i;

	while (again==1){
	
	   
		cout << "x is set to: " << x << endl;
	
		cout << "Please input a number: ";
		cin >> y; //bug 15 wrong direction << instead of >>
		if(x > y){//bug 20 lacking braces
			cout << "X is greater than Y\n";
		}
		else{
			cout << "X is less than Y" << endl;
		}


		for(int x = 0; x < 10; x++){
			cout << x << endl;
		}
		
		cout << "What number would you like to find the factorial for? " << endl;
		cin >> num;//bug 13 - no semicolon
		for(i=1; i<=num; ++i){
			factorial *= i;
			cout << factorial << endl;
		}
		
		cout << "Factoral is: " << factorial <<endl;

		cout << "Are you enjoying cs161? (y-1 or n-0) " << endl;
		cin >> myAnswer;//bug 11 myanswer --> myAnswer
		if(myAnswer == 1){//bug 19: lacking braces, bug 14 is that there was only one equals sign. y is not variable, setting to char. but 9, and bug 10: myanswer --> myAnswer
			cout << "Yay!" << endl;
		}
		else{//bug 18: lacking braces
			cout << "I hope you will soon!" << endl;
		}

		cout << "Play Again 1 or 0:";
		cin >> again;
	}

return 0;
} //bug 6 lacking closing brace :(

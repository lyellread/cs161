#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
//#include <stdlib>

using namespace std;

void passgen(int ll, int ul, int num, int chr){
	
	string password;

	srand(time(NULL));

	while ((ll + ul + num + chr)!=0){
		if (ll>0){
			//lowercase
			
			int ascii = (rand() % 26) + 97;

			password.push_back(ascii);

			ll--;
		}
		if (ul>0){
			//uppercase
			
			int ascii = (rand() % 26) + 65;

			password.push_back(ascii);

			ul--;
		}
		if (num>0){
			//number
			
			int ascii = (rand() % 10) + 48;

			password.push_back(ascii);

			num--;
		}
		if (chr>0){
			//spec. caracters
				
			int ascii = (rand() % 15) + 33;

			password.push_back(ascii);

			chr--;
		}

	}
	
	// shufle it up
	
	random_shuffle(password.begin(), password.end());

	cout << "Password:/n";
	cout << password << endl;
	


	
}


int main (){

	int cont = 1;
	int ll = 0;
	int ul = 0;
	int num = 0;
	int chr = 0;

	while (cont == 1){
		cout << "Welcome to PassGen1.0" << endl;
		cout << "\nHow Many Lower Case Letters? (0 for none):";
		cin >> ll;
		cout << "\nHow Many Upper Case Letters? (0 for none):";
		cin >> ul;
		cout << "\nHow Many Numbers Letters? (0 for none):";
		cin >> num;
		cout << "\nHow Many Special Characters? (0 for none):";
		cin >> chr;

		passgen(ll,ul,num,chr);

		cout << "\nPlay Again (1 for yes, 0 for no):";
		cin >> cont;
	}
}

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main () {
	int x;
	srand(time(NULL));

	x = rand()%6;
	cout << "x= " << x << endl;

	if (x == 0){
		cout << "Bummer, 0" << endl;
	}
	else if (x%2 == 0){
		cout << "Even" << endl;
	}
	else{
		cout << "Odd" << endl;
	}	

}

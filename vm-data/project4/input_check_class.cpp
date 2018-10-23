// A Class to check input... Not sure how this is gonna be used.


#include <iostream>
#include <string>


using namespace std;


class checkInput{

	//Access Specifier:
	public:

	//Data Members (variables):
	string input;
	int inputLength;

	//Member Functions:
	
	int checkNum(){

		inputLength = input.length();

		for (int i = 0; i < inputLength; i++){
			
			int current = int(input[i]);
			if (current<48 || current>57){
				return 0;
			}
		}
		return 1;
	}



	int checkAlpha (){

		inputLength = input.length();

		for (int i = 0; i < inputLength; i++){
			
			int current = int(input[i]);
			if (!((current>=65 && current<=90) || (current>=97 && current<=122))){
				return 0;
			}
		}
		return 1;
	}



	int checkHex(){

		inputLength = input.length();

		for (int i = 0; i < inputLength; i++){
			
			int current = int(input[i]);
			if (!((current>=65 && current<=70) || (current>=97 && current<=102) || (current>=48 && current<=57))){
				return 0;
			}
		}
		return 1;
	}



	int checkBin(){

		inputLength = input.length();

		for (int i = 0; i < inputLength; i++){
			
			int current = int(input[i]);
			if (!(current==48 || current == 49)){
				return 0;
			}
		}
		return 1;
	}

};


int main () {
	
	string teststr;

	while (1){

		cout << "\n\nHere:";
		getline(cin, teststr);

		checkInput input1;

		input1.input = teststr;

		cout << "CheckNum: " << input1.checkNum() << endl;

		cout << "CheckAlpha: " << input1.checkAlpha() << endl;

		cout << "CheckHex: " << input1.checkHex() << endl;

		cout << "CheckBin: " << input1.checkBin() << endl;
	}

}



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>


using namespace std;


// #####################
// #HOMEMADE CONVERTERS#
// #####################


int s_to_i (string input){
	int output=0;
	for (int str_index=0; str_index < input.length(); str_index++){

		int multiplier = input.length()-(str_index+1);
		int working_digit = int(input[str_index])-48;

		for (int iterator=0; iterator < multiplier; iterator++){
			working_digit*=10;
		}//this works by usign ones, tens, hundreds...

		output+=working_digit;
	}
	return output;
}

int number_Of_Digits (unsigned i){ //credit to: USER: Skizz, Tim Cooper, on https://stackoverflow.com/questions/1489830/efficient-way-to-determine-number-of-digits-in-an-integer
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

// #####################
// #INPUT CHECKING FXNS#
// #####################


int string_Is_Int (string input){
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) return 0;
	}
	return 1;
}

int parameter_Check(string parameter){
	if (string_Is_Int(parameter)){
		return s_to_i (parameter);
	}
	else{
		cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS NOT A NUMBER" << endl;
		exit(EXIT_FAILURE);
	}
}

int input_On_Range (int acceptable_min, int acceptable_max){

	string input;
  int return_value;
	bool negative=false;

	getline(cin, input);
	int len = input.length();

	//check for length 0 (blank)
	if (len == 0){
		//for loop would not trigger as len = 0, and stoi would dump core :(
		cout << "Length was 0. Please re-enter!:";
		return input_On_Range(acceptable_min, acceptable_max);
	}

	//check that each character is an int
	for (int i=0; i< len;i++){
    if (int(input[i]) < 48 || int(input[i]) > 57){
    	cout << "Invalid Character Found, Re-Enter:";
			return input_On_Range(acceptable_min, acceptable_max);
		}
  }

	return_value = s_to_i(input);

	if (return_value <= acceptable_max && return_value >= acceptable_min){
		return return_value;
	}
	//its not in range :(
	else{
		cout << "Invalid. Again:";
		return input_On_Range(acceptable_min, acceptable_max);
		//recursively call this again on and on...
	}
}


// #####################
// #MANIPULATION  TOOLS#
// #####################


int sum_Of(int arr[], int len_arr){ //[array, length]
	int result=0;
	for (int index=0; index< len_arr; ++index){
		result += arr[index];
	}
	return result;
}

int q_Of_n (int n, int dice[], int len_dice){ //[how many of n, array, length]
	//cout << "DICE ADDR: " << dice << endl;
	int counter = 0;
	for (int index=0; index<len_dice; ++index){
		//cout << "LOOP ENTERED;" << endl;
		//cout << dice[index];
		if (dice[index] == n){
			++counter;
		}
	}
	//cout << "COUNTER: " << counter << endl;
	return counter;
}

int are_Equal (int arr_1[], int arr_2[], int len_1, int len_2){
	if (len_1 != len_2)
		return 0;

	//sort(arr_1, arr_1+len_1);
	//sort(arr_2, arr_2+len_2);

	for (int i=0; i<len_1; ++i){
		if (arr_1[i] != arr_2[i])
			return 0;
	}
	return 1;
}


// #####################
// #YAHTZEE CALCULATION#
// #####################


int numbers_Only (int number, int dice[], int len_dice){
	int counter=0;
	for (int i=0; i<len_dice; ++i){
		if (dice[i] == number){
			counter+=number;
		}
	}
	return counter;
}

int n_Of_A_Kind (int n, int dice[], int len_dice){ //[(3|4) of a kind, array, length]
	//cout << "DICE ADDR: " << dice << endl;
	for (int number = 1; number < 7; ++number){
		if (q_Of_n(number, dice,5) >= n){
			return sum_Of(dice, 5);
		}
	}
	return 0;
}

int full_House (int dice[], int len_dice, int deltas[]){

	if ((deltas[0] == 0 && deltas[3] == 0) && (deltas[1] == 0 || deltas[2] == 0)){
		return 25;
	}
	return 0;
}

int small_Straight (int dice[], int len_dice, int deltas[], int large_Straight_Deltas[], int len_Large_Straight_Deltas){
	/*
	cout << "PRINTING DELTAS" << endl;
	for (int n=0; n<4; ++n){
		cout << deltas[n];
	}
 */

	if ((q_Of_n(1,deltas,4) == 3 && q_Of_n(0,deltas,4) == 1) || (are_Equal(large_Straight_Deltas, deltas, len_Large_Straight_Deltas, 4)) || ((deltas[0] == 2 && q_Of_n(1,deltas,4) == 3)) ||  (deltas[3] == 2 && q_Of_n(1,deltas,4) == 3)) {
		return 30;
	}
	return 0;
}

int large_Straight (int deltas[], int len_deltas, int large_Straight_Deltas[], int len_Large_Straight_Deltas){
	if (are_Equal(large_Straight_Deltas, deltas, len_Large_Straight_Deltas, len_deltas)){
		return 40;
	}
	return 0;
}

int yahtzee (int deltas[], int len_deltas, int yahtzee_Deltas[], int len_Yahtzee_Deltas){
	if (are_Equal(yahtzee_Deltas, deltas, len_Yahtzee_Deltas, len_deltas)){
		return 50;
	}
	return 0;
}


// #####################
// #GAMEPLAY  FUNCTIONS#
// #####################


void randomize_Dice (int dice[], int deltas[], int roll[]){

	srand(time(NULL));

	for (int i=0; i<5; ++i){
		if (roll[i] == 1){
			dice[i] = rand()%6+1;
		}
	}
	sort(dice, dice+5);
	/*
	cout << "PRINTING DICE" << endl;
	for (int n=0; n<5; ++n){
		cout << dice[n];
	}
  */

	for (int i = 1; i < 5; ++i) //1..4
		deltas[i-1]=(dice[i]-dice[i-1]);

	/*
		cout << "PRINTING DELTAS" << endl;
		for (int n=0; n<4; ++n){
			cout << deltas[n];
		}
		*/
}

int score_By_Play(int play, int dice[], int deltas[], int large_Straight_Deltas[], int yahtzee_Deltas[]){

	int result =0;

	if (play < 6){
		return numbers_Only(play+1, dice, 5);
	}

	if (play>5 && play <8){
		return (n_Of_A_Kind(play-3, dice, 5));
	}

	if (play==8){
		return (full_House(dice, 5, deltas));
	}

	if (play==9){
		return (small_Straight(dice, 5, deltas, large_Straight_Deltas, 4));
	}

	if (play==10){
		return (large_Straight(deltas, 4, large_Straight_Deltas, 4));
	}

	if (play==11){
		return (yahtzee(deltas, 4, yahtzee_Deltas, 4));
	}

	if (play==12){
		return sum_Of(dice, 5);
	}
}

void print_Score (int dice[], int ** scoresheet,int score_Flag, int player, int deltas[], int large_Straight_Deltas[], int yahtzee_Deltas[]){ //provide a scoresheet of length 13 with all '-1' to return a full theoretical dice roll

	char numbers[6][30] = {"	|        Ones : ", "	|        Twos : ", "	|      Threes : ", "	|       Fours : ", "	|       Fives : ", "	|       Sixes : "};
	char bottom [7][30] = {"	| 3 Of A Kind : ", "	| 4 Of A Kind : ", "	|  Full House : ", "	|Sm. Straight : ","	|Lg. Straignt : ","	|     Yahtzee : ", "	|      Chance : "};

	cout << "	+----------------------------+" << endl;
	if (score_Flag){cout << "	|       Current  Score       |" << endl;} else{	cout << "	|  Hypothetical Score Sheet  |" << endl;}
	cout << "	|  >with current dice roll<  |" << endl;
	cout << "	|          Player " << player+1 << "          |" << endl;
	cout << "	|----------------------------|" << endl;
	cout << "	|*******Upper  Section*******|" << endl;

	//score_By_Play(play, dice, deltas, large_Straight_Deltas, yahtzee_Deltas)

	for (int i=0; i < 6; ++i){
		cout << numbers[i]; //print name
		if (scoresheet[player][i] == -1){ //theres no score there yet!
			if (score_By_Play(i, dice, deltas, large_Straight_Deltas, yahtzee_Deltas) > 9) { //if it has two characters
				cout << "\033[1;31m" << score_By_Play(i, dice, deltas, large_Straight_Deltas, yahtzee_Deltas) << "\033[0m" << "           |" << endl; //bold for 2 character
			}
			else {
				cout << "\033[1;31m" << score_By_Play(i, dice, deltas, large_Straight_Deltas, yahtzee_Deltas) << "\033[0m" << "            |" << endl;
			}
		}

		else{ //there is a score there
			if(scoresheet[player][i] > 9) { //if its 2 digits
				cout << scoresheet[player][i] << "           |" << endl;
			}
			else {
				cout << scoresheet[player][i] << "            |" << endl;
			}
		}
	}
  // Same for bottom part
	cout << "	|*******Lower  Section*******|" << endl;

	for (int i=0; i < 7; ++i){
		cout << bottom[i]; //print name
		if (scoresheet[player][i+6] == -1){ //theres no score there yet!
			if (score_By_Play(i+6, dice, deltas, large_Straight_Deltas, yahtzee_Deltas) > 9) { //if it has two characters
				cout << "\033[1;31m" << score_By_Play(i+6, dice, deltas, large_Straight_Deltas, yahtzee_Deltas) << "\033[0m" << "           |" << endl; //bold for 2 character
			}
			else {
				cout << "\033[1;31m" << score_By_Play(i+6, dice, deltas, large_Straight_Deltas, yahtzee_Deltas) << "\033[0m" << "            |" << endl;
			}
		}

		else{ //there is a score there
			if(scoresheet[player][i+6] > 9) { //if its 2 digits
				cout << scoresheet[player][i+6] << "           |" << endl;
			}
			else {
				cout << scoresheet[player][i+6] << "            |" << endl;
			}
		}
	}

	cout << "	+----------------------------+" << endl;

}

void roll_Dice (int dice[], int deltas[], int large_Straight_Deltas[], int yahtzee_Deltas[], int ** scoresheet, int player){

	int roll_Binary[5] = {1,1,1,1,1};
	randomize_Dice(dice, deltas, roll_Binary);

	cout << "\033[0;32m\n\n		Current Dice:\n		";
	cout << dice[0];
	for (int y=0; y<4; ++y){
		cout << ", " << dice[y+1];
	}
	cout << "\n\n\033[0m";

	//int scoresheet_Blank[13] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

	print_Score(dice, scoresheet, 0, player, deltas, large_Straight_Deltas, yahtzee_Deltas);

	for (int i=0; i<2; ++i){

		int temp=0;
		cout << endl << "To Keep a Dice, Choose 0. To Roll Dice Again, Enter 1:" << endl;
		for (int y=0; y<5; ++y){
			cout << "Dice " << y+1 << " is currently " << dice[y] << ". Change? (1 or 0):";

			temp=input_On_Range(0,1);

			roll_Binary[y] = temp;
		}

		randomize_Dice(dice, deltas, roll_Binary);

		cout << "\033[0;32m\n\n		Current Dice:\n		";
		cout << dice[0];
		for (int y=0; y<4; ++y){
			cout << ", " << dice[y+1];
		}
		cout << "\n\n\033[0m";

		print_Score(dice, scoresheet, 0, player, deltas, large_Straight_Deltas, yahtzee_Deltas);

	}

}

void play_Dice(int dice[], int deltas[], int ** scoresheet, int player, int large_Straight_Deltas[], int yahtzee_Deltas[]){
	char options[13][30] = {"Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "3 Of A Kind", "4 Of A Kind", "Full House", "Sm. Straight","Lg. Straignt","Yahtzee", "Chance"};

	cout << "Choose one below that you have not already played in:" << endl;
	for (int available=0; available<13; ++available){
		cout << available << " : " << options[available] << endl;
	}
	int choice;
	cout << "\n\nChoice:";
	choice = input_On_Range(0,12);
	while (scoresheet[player][choice] != -1){
		cout << "That category has already been played. Try Again:";
		choice = input_On_Range(0,12);
	}

	scoresheet[player][choice] = score_By_Play(choice, dice, deltas, large_Straight_Deltas, yahtzee_Deltas);

}

int score_Player (int ** scoresheet, int player){
	int top_Sum=0;
	int bot_Sum=0;

	top_Sum=sum_Of(scoresheet[player], 6); //only first 6
	bot_Sum=sum_Of(&scoresheet[player][6], 7);//pointer to element 6 where the bottom part starts...

	if (top_Sum>=63){
		top_Sum+=35;
	}

	return (top_Sum+bot_Sum);
}

void score_All (int ** scoresheet, int n){
	cout << "\n\n";

	int * player_Scores = new int[n];
	for (int i=0; i<n; ++i){
		player_Scores[i] = score_Player(scoresheet, i);
		cout << "	Player " << i+1 << " : " << player_Scores[i] << " points." << endl;
	}

	int highest_Scoring_Player;
	highest_Scoring_Player = distance(player_Scores, max_element(player_Scores, player_Scores + n));

	cout << "\n\033[1;32m" << "The Highest Scoring Player Is : Player " << highest_Scoring_Player+1 << "!\033[0m" << endl;

	delete[] player_Scores;
}


// #####################
// #  MAIN   FUNCTION  #
// #####################


int main(int argc, char ** argv){
	if (argc == 2){

		int cont = 1;
		while (cont){
			int result;
			result = parameter_Check(argv[1]); //result is how many players to have

			cout << "\033[1;33m" << "Starting a game with " << result << " players." << "\033[0m\n";

			//int * scoresheet = new int[13][result]

			//initialize dice

			//initialize scoresheet
			int ** scoresheet;
			scoresheet = new int* [result];
			for(int i=0; i<result; i++) {
				scoresheet[i] = new int[13];
			}

			//'blank' out scoresheet to -1
			for (int row=0; row < result; ++row){
				for (int col=0; col<13; ++col){
					scoresheet[row][col] =-1;
				}
			}

			//now we have a scoresheet that is players X scores and is all empty


			int large_Straight_Deltas[4] = {1,1,1,1};
			int yahtzee_Deltas[4] = {0,0,0,0};
			int dice[5] = {1,1,1,1,1};
			int deltas[4] = {-1,-1,-1,-1};
			/*
			sort(dice, dice+5);

			int deltas[4];
			for (int i = 1; i < 5; ++i) //1..4
				deltas[i-1]=(dice[i]-dice[i-1]);
				*/

				for (int score=0; score < 13; ++score){
					for (int player=0; player<result; player++){
						cout << "\n\n\033[1;36m" << "It is now player #" << player+1 << "'s turn!" << "\033[0m\n\n";

						//call dice roll, which edits dice array

						roll_Dice(dice, deltas, large_Straight_Deltas, yahtzee_Deltas, scoresheet, player);

						//ask the user to choose where to play their dice roll and update the scoresheet

						play_Dice(dice, deltas, scoresheet, player, large_Straight_Deltas, yahtzee_Deltas);

					}
				}

			// score the sheets and display the winner

			score_All(scoresheet, result);



			cout << "Play Again? (1 | 0) :";
			cin >> cont;
		}
	}
	else{
	cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS EITHER BLANK OR OVERFULL" << endl;
	exit(EXIT_FAILURE);
	}
}

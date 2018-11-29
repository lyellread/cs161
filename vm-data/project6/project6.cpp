//Project SIX - connect4 //

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

/*********************************************************************
** Function:s_to_i
** Description:string to int
** Parameters:string input
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

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

// #####################
// #INPUT CHECKING FXNS#
// #####################

/*********************************************************************
** Function:string_Is_Int
** Description:checks a string is integer
** Parameters: string input
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int string_Is_Int (string input){
	for (int i=0; i<input.length(); ++i){
		if (input[i]>57 || input[i]<48) return 0;
	}
	return 1;
}

/*********************************************************************
** Function:parameter_Check
** Description: checks the parameters are cool
** Parameters:string parameter
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int parameter_Check(string parameter, int low, int high){
	if (string_Is_Int(parameter)){
		int int_Parameter = s_to_i (parameter);
    if (int_Parameter >= low && int_Parameter <= high){
      return int_Parameter;
    }
	}
	cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS NOT A VALID NUMBER" << endl;
	exit(EXIT_FAILURE);
}

/*********************************************************************
** Function:input_On_Range
** Description:checks that input is on a range, otherwise recuseive self-calls to force good input
** Parameters:int acceptable_min, int acceptable_max
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

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
// #WIN-CHECK FUNCTIONS#
// #####################

int check_Vertical (int ** grid, int rows, int cols, int player){
  //range will be on all rows, from 0..col_max-3, checking from the top
}

int check_Horizontal (int ** grid, int rows, int cols, int player){
  //range will be on rows from 0..row_max-3, all columns,  checking from the left
}

int check_Diagonal_Up (int ** grid, int rows, int cols, int player){
  //range will be on rows 0..row_max-3 and cols from 3..col_max, starting bottom left
}

int check_Diagonal_Down (int ** grid, int rows, int cols, int player){
  //range will be on rows 0..row_max-3, cols 0..col_max-3, top left
}

int check_All (int ** grid, int rows, int cols, int player){
  int sum = 0;
  sum += check_Vertical(grid, rows, cols, player);
  sum += check_Horizontal(grid, rows, cols, player);
  sum += check_Diagonal_Up(grid, rows, cols, player);
  sum += check_Diagonal_Down(grid, rows, cols, player);
  if (sum >= 1) {
  return player;
  }
  return -1;
}

// #####################
// #OTHER C4 FUNCTIONS #
// #####################

void draw_Grid (int ** grid, int rows, int cols){

}

int play_OK (int ** grid, int rows, int cols, int play_Column){


}

void play_Value (int ** grid, int rows, int cols, int play_Column, int player){
  //player is 1..2
  //we want to drop to bottom...

  for (int elev = 0; elev < cols; ++elev){
    if (grid[elev][play_Column] != 0){
      grid[elev-1][play_Column] = player;
      return;
    }
  }

  //the col is empty
  grid[rows-1][play_Column] = player;
  return;
}

void player_Turn (int ** grid, int rows, int cols, int player){

}

// #####################
// #  COMPUTER  "AI"   #
// #####################

def computer_Play (int ** grid, int rows, int cols){

}


// #####################
// #   MAIN  FUNCTION  #
// #####################


int main (int argc, char ** argv) {
  if (argc != 4){
    cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS OF INCORRECT LENGTH" << endl;
  	exit(EXIT_FAILURE);
  }

  int number_Of_Players = parameter_Check (argv[1], 1, 2);
  int number_Of_Rows = parameter_Check (argv[2],4,100);
  int number_Of_Columns = parameter_Check (argv[3],4,100);
  int continue_Game = 1;
  int game_Won = -1;

  //Define Dynamically Allocated 2D Array
  int ** grid;
  grid = new int* [number_Of_Rows];
  for(int i=0; i<number_Of_Rows; i++) {
    grid[i] = new int[number_Of_Columns];
  }

  while (continue_Game){

    //'blank' out scoresheet to 0's
    for (int row=0; row < number_Of_Rows; ++row){
      for (int col=0; col<number_Of_Columns; ++col){
        grid[row][col] = 0;
      }
    }

    for (int play=0; play < (number_Of_Rows * number_Of_Columns)){

      if ((play % 2) == 0){
        //even player turn = player 1's turn
        player_Turn(grid, number_Of_Rows, number_Of_Columns, 1);
        game_Won = check_All (grid, number_Of_Rows, number_Of_Columns, 1);
      }

      if ((play %2) != 0 && players == 1){
        //odd player turn = player 2, but 1 player game, so computer_Play
        computer_Play(grid, number_Of_Rows, number_Of_Columns);
        game_Won = check_All (grid, number_Of_Rows, number_Of_Columns, 2);
      }

      if ((play %2) != 0 && players == 2){
        //odd player turn = player 2 turn
        player_Turn(grid, number_Of_Rows, number_Of_Columns, 2);
        game_Won = check_All (grid, number_Of_Rows, number_Of_Columns, 2);
      }

      //the appropriate turn has been executed. Check and announce win
      if (game_Won != -1){
        cout << "PLAYER: " << game_Won << " WON!" << endl;
        break;
      }

    }

    if (game_Won == -1){
      cout << "CAT GAME!!" << endl;
    }

    cout << "\nPlay Again? (1 or 0) :";
    continue_Game = input_On_Range (0,1);

  }
}

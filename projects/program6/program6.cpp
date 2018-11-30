/*********************************************************************
** Program Filename:program6.cpp
** Author:Lyell C Read
** Date:11/29/2018
** Description:Connect 4 - A c++ Implementation
** Input:User input
** Output:Text output
*********************************************************************/

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

/*********************************************************************
** Structure:connect4_game
** Description:includes all the necessary values to make a sudoky grid
** Values: players, rows, cols, pointer to grid.
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

struct connect4_game {
  int players;
  int rows;
  int cols;
  int ** grid_ptr;
};

// #####################
// #HOMEMADE THINGS    #
// #####################

/*********************************************************************
** Function:rand_Int_On_Range
** Description:rand integer on a range
** Parameters:int min, int max
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int rand_Int_On_Range (int min, int max){

	int n = (max-min)+1;

	return (rand()%n)+min;
}

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

/*********************************************************************
** Function:check_Vertical
** Description:checks for a vertical win condition in all possible places
** Parameters:connect4_game c4, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int check_Vertical (connect4_game c4, int player){
  //range will be on all rows, from 0..col_max-3, checking from the top
  //cout << "VERT_CHECK REACHED";
  for (int row = 0; row < c4.rows-3; ++row){
    for (int col = 0; col < c4.cols; ++col){
      //cout << "[" << row << "," <<  col << "] ";
      if (c4.grid_ptr[row][col] == player && c4.grid_ptr[row+1][col] == player && c4.grid_ptr[row+2][col] == player && c4.grid_ptr[row+3][col] == player){
        //cout << "FOUND VERTICAL WIN @ " << row << ", " << col << endl;
        return 1;
      }
    }
  }

  return 0;
}

/*********************************************************************
** Function:check_Horizontal
** Description:checks for a horizontal win condition in all possible places
** Parameters:connect4_game c4, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int check_Horizontal (connect4_game c4, int player){
  //range will be on rows from 0..row_max-3, all columns,  checking from the left
  //cout << "HRZT_CHECK REACHED";
  for (int row = 0; row < c4.rows; ++row){
    for (int col = 0; col < c4.cols-3; ++col){
      //cout << "[" << row << "," <<  col << "] ";
      if (c4.grid_ptr[row][col] == player && c4.grid_ptr[row][col+1] == player && c4.grid_ptr[row][col+2] == player && c4.grid_ptr[row][col+3] == player){
        //cout << "FOUND HORIZONTAL WIN @ " << row << ", " << col << endl;
        return 1;
      }
    }
  }

  return 0;
}

/*********************************************************************
** Function:check_Diagonal_Up
** Description:checks for a diagonal up-sloping win condition in all possible places
** Parameters:connect4_game c4, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int check_Diagonal_Up (connect4_game c4, int player){
  //range will be on rows 0..row_max-3 and cols from 3..col_max, starting bottom left
  //cout << "DIAG_UP_CHECK REACHED";
  for (int row = 3; row < c4.rows; ++row){
    for (int col = 0; col < c4.cols-3; ++col){
      //cout << "[" << row << "," <<  col << "] ";
      if (c4.grid_ptr[row][col] == player && c4.grid_ptr[row-1][col+1] == player && c4.grid_ptr[row-2][col+2] == player && c4.grid_ptr[row-3][col+3] == player){
        //cout << "FOUND DIAGONAL_UP WIN @ " << row << ", " << col << endl;
        return 1;
      }
    }
  }

  return 0;
}

/*********************************************************************
** Function:check_Diagonal_Down
** Description:checks for a diagonal, downward sloping win condition in all possible places
** Parameters:connect4_game c4, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int check_Diagonal_Down (connect4_game c4, int player){
  //range will be on rows 0..row_max-3, cols 0..col_max-3, top left
  //cout << "DIAG_DW_CHECK REACHED";
  for (int row = 0; row < c4.rows-3; ++row){
    for (int col = 0; col < c4.cols-3; ++col){
      //cout << "[" << row << "," <<  col << "] ";
      if (c4.grid_ptr[row][col] == player && c4.grid_ptr[row+1][col+1] == player && c4.grid_ptr[row+2][col+2] == player && c4.grid_ptr[row+3][col+3] == player){
        //cout << "FOUND DIAGONAL_DOWN WIN @ " << row << ", " << col << endl;
        return 1;
      }
    }
  }

  return 0;
}

/*********************************************************************
** Function:check_All
** Description:checks the four (vertical, horizontal, diagonal(up|down) win case-checking functions)
** Parameters:connect4_game c4, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int check_All (connect4_game c4, int player){
  int sum = 0;
  sum += check_Vertical(c4, player);
  sum += check_Horizontal(c4, player);
  sum += check_Diagonal_Up(c4, player);
  sum += check_Diagonal_Down(c4, player);
  if (sum >= 1) {
  return player;
  }
  return -1;
}

// #####################
// #OTHER C4 FUNCTIONS #
// #####################

/*********************************************************************
** Function:color_Printout
** Description:prints out the numbers 0 in white, 1 in yellow, 2 in red
** Parameters:value
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void color_Printout (int value){
  switch (value){
    case 0:
      cout << value;
      break;
    case 1:
      cout << "\033[1;33m" << value << "\033[0m";
      break;
    case 2:
      cout << "\033[1;31m" << value << "\033[0m";
      break;
  }
}

/*********************************************************************
** Function:line_Printout
** Description:prints out specific character strings based on a flag.
** Parameters:int length, int flag
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void line_Printout (int length, int flag) {//length ~= cols; flag is pipedash (0) or dash (1)
  cout << "  ";
  if (flag){
    for (int i=0; i<length; ++i){
      cout << "---";
    }
    cout << "-";
  }
  else{
    cout << "-";
    for (int i=0; i<length; ++i){
      cout << "-|-";
    }
  }
  cout << "-\n";
}

/*********************************************************************
** Function:draw_Grid
** Description:prints out that noice looking grid.
** Parameters:connect4_game c4
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void draw_Grid (connect4_game c4){
  line_Printout(c4.cols, 1);
  for (int row=0; row < c4.rows; ++row){
    cout <<"  | ";
    for (int col=0; col < c4.cols; ++col){
      color_Printout(c4.grid_ptr[row][col]);
      if (col != c4.cols-1){
        cout << "  ";
      }
    }
    cout << " |\n";
    //line_Printout(c4.cols, 1);
    }

  line_Printout(c4.cols, 0); //---|--|--...

  cout << "    \033[1;36m";
  for (int col=0; col < c4.cols; ++col){
    if (col>8){
      cout << (col +1)<< " ";
    }
    else{
      cout << (col +1)<< "  ";
    }
  }
  cout << "\033[0m";
}

/*********************************************************************
** Function:column_Playable
** Description:bool if top element is full or not
** Parameters:connect4_game c4, int play_Column
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int column_Playable (connect4_game c4, int play_Column){

  //cout << "CHECKING IF " << c4.grid_ptr[0][play_Column-1] << " IS APPTR";
  if (c4.grid_ptr[0][play_Column-1] == 0){
    return 1;
  }
  return 0;
}

/*********************************************************************
** Function:play_Value
** Description:play a value in a column, dropping it to the bottom, or the lowest open spot otherwise
** Parameters:connect4_game c4, int play_Column, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void play_Value (connect4_game c4, int play_Column, int player){
  //player is 1..2
  //we want to drop to bottom...

  //cout << "VAL_PLAY ; COL : " << play_Column << endl;

  for (int elev = 0; elev < c4.rows; ++elev){
    if (c4.grid_ptr[elev][play_Column-1] != 0){
      c4.grid_ptr[elev-1][play_Column-1] = player;

      //cout << "PLAYING " << player << " AT " << elev-1 << ", " << play_Column-1 << endl;

      return;
    }
  }
  //the col is empty
  c4.grid_ptr[c4.rows-1][play_Column-1] = player;
  return;
}

/*********************************************************************
** Function:play_Input_And_Check
** Description:takes user input, and plays that value, or returns an error and recursivley self calls
** Parameters:connect4_game c4, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void play_Input_And_Check (connect4_game c4, int player){
  int play_Column;
  cout << "\n\n What column? :";
  play_Column = input_On_Range (1,c4.cols);
  if (column_Playable(c4, play_Column) == 1){ //top element is emptyyyyy
    play_Value(c4, play_Column, player);
  }
  else{
    cout << "BAD INPUT: AGAIN: ";
    play_Input_And_Check(c4, player);
  }
}

/*********************************************************************
** Function:player_Turn
** Description:manages the turn of a player
** Parameters:connect4_game c4, int player
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void player_Turn (connect4_game c4, int player){
  cout << "\n\n\n ~IT IS PLAYER ";
  color_Printout(player);
  cout << "'S TURN~\n\n";

  //display array currently

  draw_Grid (c4);

  //make a play

  play_Input_And_Check(c4, player);

}

// #####################
// #  COMPUTER  "AI"   #
// #####################

/*********************************************************************
** Function:computer_Play
** Description:plays for the CPU. RANDOM right now, in this iteration
** Parameters:connect4_game c4
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void computer_Play (connect4_game c4){
  int play_Column = rand_Int_On_Range (0,c4.cols-1); //if 4 cols, want on 0..3 for indexing
  while (!column_Playable(c4, play_Column+1)){
    play_Column = rand_Int_On_Range (0,c4.cols-1); //if 4 cols, want on 0..3 for indexing
  }
  play_Value(c4, (play_Column+1), 2);
}

// #####################
// #ARRAY MANIPULATION #
// #####################

/*********************************************************************
** Function:int ** make_Array
** Description:makes an array and assigns it that pointer that it returns
** Parameters:rows, cols
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int ** make_Array (int rows, int cols){
  int ** grid;
  grid = new int* [rows];
  for(int i=0; i<rows; i++) {
    grid[i] = new int[cols];
  }
  return grid;
}

/*********************************************************************
** Function:delete_Array
** Description:makes an array and assigns it that pointer that it returns
** Parameters:pointer-to-array, rows, cols
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void delete_Array (int ** array_pointer, int rows, int cols){
  cout << "Cleaning up..." << endl;
  for(int i=0; i<rows; i++) {
    delete[] array_pointer[i];
  }
  delete[] array_pointer;
}

/*********************************************************************
** Function: blank_Array
** Description:blanks an array to a specific value
** Parameters:int ** array_Ptr, int rows, int cols, int blank_To_Value
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

void blank_Array (int ** array_Ptr, int rows, int cols, int blank_To_Value){
  for (int row=0; row < rows; ++row){
    for (int col=0; col < cols; ++col){
      array_Ptr[row][col] = blank_To_Value;
    }
  }
}

// #####################
// #   MAIN  FUNCTION  #
// #####################

/*********************************************************************
** Function:main
** Description:commands this siiiick operation - calls turns and calls win-checking, and prints result messages, and manages looping
** Parameters:int argc, char ** argv
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int main (int argc, char ** argv) {
  if (argc != 4){
    cout << "BREAKING GRACEFULLY ~ INPUT PROVIDED IS OF INCORRECT LENGTH" << endl;
  	exit(EXIT_FAILURE);
  }

  connect4_game c4;
  srand(time(NULL));

  c4.players = parameter_Check (argv[1], 1, 2);
  c4.rows = parameter_Check (argv[2],4,100);
  c4.cols = parameter_Check (argv[3],4,100);
  c4.grid_ptr = make_Array(c4.rows, c4.cols);

  int continue_Game = 1;
  int game_Won = -1;

  while (continue_Game){

    //'blank' out scoresheet to 0's
    blank_Array (c4.grid_ptr, c4.rows, c4.cols, 0);

    for (int play = 0; play < (c4.rows * c4.cols); ++play){

      if ((play % 2) == 0){
        //even player turn = player 1's turn
        player_Turn(c4, 1);
        game_Won = check_All (c4, 1);
      }

      if ((play %2) != 0 && c4.players == 1){
        //odd player turn = player 2, but 1 player game, so computer_Play
        computer_Play(c4);
        game_Won = check_All (c4, 2);
      }

      if ((play %2) != 0 && c4.players == 2){
        //odd player turn = player 2 turn
        player_Turn(c4, 2);
        game_Won = check_All (c4, 2);
      }

      //the appropriate turn has been executed. Check and announce win
      if (game_Won != -1){
        cout << "\n";
        draw_Grid (c4);
        cout << "\n\n \033[0;32mPLAYER: " << game_Won << " WON!\033[0m" << endl;
        break;
      }

    }

    if (game_Won == -1){
      cout << "\n";
      draw_Grid (c4);
      cout << "\n\n\033[0;32m\n CAT GAME!!\033[0m" << endl;
    }

    cout << "\n Play Again? (1 or 0) :";
    continue_Game = input_On_Range (0,1);

  }

  delete_Array(c4.grid_ptr, c4.rows, c4.cols);

}

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
** Function:s_to_i
** Description:string to int
** Parameters:string input
** Pre-Conditions: na
** Post-Conditions: na
*********************************************************************/

int rand_Int_On_Range (int min, int max){

	int n = (max-min)+1;

	return (rand()%n)+min;
}

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

int column_Playable (connect4_game c4, int play_Column){

  //cout << "CHECKING IF " << c4.grid_ptr[0][play_Column-1] << " IS APPTR";
  if (c4.grid_ptr[0][play_Column-1] == 0){
    return 1;
  }
  return 0;
}

void play_Value (connect4_game c4, int play_Column, int player){
  //player is 1..2
  //we want to drop to bottom...

  for (int elev = 0; elev < c4.rows; ++elev){
    if (c4.grid_ptr[elev][play_Column-1] != 0){
      c4.grid_ptr[elev-1][play_Column-1] = player;
      return;
    }
  }
  //the col is empty
  c4.grid_ptr[c4.rows-1][play_Column-1] = player;
  return;
}

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

void computer_Play (connect4_game c4){
  int play_Column = rand_Int_On_Range (0,c4.cols-1); //if 4 cols, want on 0..3 for indexing
  while (!column_Playable(c4, play_Column)){
    play_Column = rand_Int_On_Range (0,c4.cols-1); //if 4 cols, want on 0..3 for indexing
  }
  play_Value(c4, play_Column+1, 2);
}

// #####################
// #   MAIN  FUNCTION  #
// #####################

int ** make_Array (int rows, int cols){
  int ** grid;
  grid = new int* [rows];
  for(int i=0; i<rows; i++) {
    grid[i] = new int[cols];
  }
  return grid;
}

void blank_Array (int ** array_Ptr, int rows, int cols, int blank_To_Value){
  for (int row=0; row < rows; ++row){
    for (int col=0; col < cols; ++col){
      array_Ptr[row][col] = blank_To_Value;
    }
  }
}

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
      cout << "\033[0;32m\n CAT GAME!!\033[0m" << endl;
    }

    cout << "\n Play Again? (1 or 0) :";
    continue_Game = input_On_Range (0,1);

  }
}

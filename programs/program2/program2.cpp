

/*********************************************************************
** Program Filename:program2.cpp
** Author:Lyell C Read
** Date:10/06/2018
** Description:Text Adventure Game
** Input:User Inputted ints
** Output: text
*********************************************************************/


#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

using namespace std;



/*********************************************************************
** Function:checkInput
** Description:Used to prompt for input and make sure that it is in the acceptable range
** Parameters:none
** Pre-Conditions:na
** Post-Conditions:na
*********************************************************************/ 



int checkInput(){
	int input;
	cout << "\nChoice: ";
	cin >> input;
	while (cin.fail() || input > 2 || input < 1){
		cin.clear();
		cin.ignore();
		cout << "Invalid Input. Retry: ";
		cin >> input;
	}
	cout << "\n\n\n" ;
	return input;
}



/*********************************************************************
** Function:Main
** Description:Main Function
** Parameters:NA
** Pre-Conditions:NA
** Post-Conditions:NA
*********************************************************************/ 



int main () {
	int cont;
	cont = 1;

	srand(time(NULL));

	while (cont == 1){
		cout << "You find yourself in a barn. This barn is old, and on the brink of collapse.\nYou decide to leave, but where do you want to go?\n\nEnter 1 to go to the grassland behind the barn.\nEnter 2 to visit the abandoned hangar to the north of the barn." << endl;
		int choice = checkInput();

		if (choice == 1){
			cout << "You exited the rusty-hinged door and you are in a grassland. \nYou spy some prairie dogs playing in the grass. Do you want to try to catch one of them?\n\nEnter 1 to try to catch one of these prairie dogs.\nEnter 2 to move on." << endl;
			int catchPrairieDog = checkInput();
		       	
			if (catchPrairieDog == 1){
				int success = rand() % 3;

				if (success == 1){
					cout << "The odds were in your favor. You catch a prairie dog and look at it, then release it." << endl;
				}
				else{
					cout << "The odds were against you - you do not catch a prairie dog." << endl;
				}
			}
			cout << "You continue on through the grasslands and find a bottle. \nIt has a dark blue color to it and you can see a thick liquid inside it. \nYou pop the cap to see better, and a cloud of turquoise mist engulfs you. \nBefore you can do anything, your eyes begin to close, and you black out . . ." << endl;
		}
				
		else{
			cout << "You pry the huge cement doors to the hangar with a piece of pipe. \nSlowly, they open and you squeeze inside. \nThe decaying hulks of many planes lay rusted, in disrepair.\nA ladder leads up to a trapdoor in the roof, 100 feet above your head. \nThe ceiling look unstable . . .\n\nEnter 1 to go to the roof via the ladder. \nEnter 2 to stay on the ground floor and examine the planes." << endl;

			int roof = checkInput();

			if (roof == 1){
				cout << "You make it to the roof. It is slimy and mossy, and very slippery. \nYou continue onto the roof anyways." << endl;

				int fall = rand() %3;

				if (fall == 1){
					cout << "You are about to make it to the center of roof, when you step on the corner of a sheet of metal.\nThe metal is smooth and acts as a surfboard, launching you off the edge of the roof.\nYou fall 100 feet onto the pavement. \nYou dont remember what happens next . . ." << endl;
				}
				else{
					cout << "You explore the roof some more. As you near the top of the roof, you notice a huge bolt sticking up. \nYou feel it. It feels loose...\n\nEnter 1 to pull out the bolt and check it out.\nEnter 2 to go back to the ladder and downstairs." << endl;

					int option = checkInput();

					if (option == 1){
						cout << "You pull the bolt. It emerges easily, and you begin to inspect it.\nYou can't inspect it long, though, as the roof begins to shake and folds in on itself...\nTurns out that bolt was all that was keeping the two-part concrete roof together. \nEveryting goes black . . ."  << endl;
					}

					else{
						cout << "You descend to the ladder. \nA glimmer appears right where you are about to put your foot, so at the last minute, you jump forwards a but to not step on whatever it is.\nInstead of landing on the concrete roof, you hear a shattering sound and crash through a huge skylight.\nBefore you black out, you notice that you are headed right for the cockpit of a B-52 . . ." << endl;
					}
				}
			}
			else{
				cout << "You start to look at the planes. You lose track of time, and it becomes dark outside.\nThe wild animals are making noise outside so you decide to sleep inside the hangar.\nAll you see before eveverything goes dark is the outline of the Rolls-Royce jet enging you chose to sleep under falling towards you . . ."<< endl;
			}
		}
		cout << "You wake up sweaty in your bed after a nightmare you cannot remember. Would you like to play again? \n\nEnter 1 to play again.\nEnter 2 to exit." << endl;
		cont = checkInput ();
		

	}
}


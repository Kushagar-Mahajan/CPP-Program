//Design a tic tac toe game in C++ in which two players are playing
#include <iostream>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();
int checkdraw();
void update_state(int state[][3]);//used in checkdraw function indicates which places belong to either player 
int main()
{
	int player = 1,i,choice;

	char mark;
	do
	{
		board();
		player=(player%2)?1:2;

		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;

		mark=(player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout<<"Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		if ( i = checkdraw() )
		i=checkwin();

		player++;
	}while(i==-1);
	board();
	if(i==1)

		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";

	cin.ignore();
	cin.get();
	return 0;
}

/*********************************************

	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}

/*******************************************************************
FUNCTION TO DECIDE WHETHER THE GAME IS DRAW OR NOT BEFORE END OF THE GAME
IN FACT , THIS FUNCTION CALCULATES THE CHANCE FOR EVERY PLAYER TO WIN;
AND IF THERE'S NO CHANCES , THE FUNCTION PREVENTS GOING AHEAD AND IT 
QUICKLY ENDS THE GAME WITH DRAW MESSAGE SHOWING THAT THERE'S NO WINNER
-1 IS RETURNED WHEN THE GAME IS STILL IN PROGRESS
0 FOR WHEN THE GAME IS OVER WITHOUT ANY RESULT , DRAW IN FACT
*********************************************************************/
int checkdraw(){
	int chances = 0;
	size_t i , j;
	int state[10][3] = {0};
	update_state(state);
	int sums[8][3] = {0};
	sums[0][1] = state[1][1] + state[2][1] + state[3][1];
	sums[0][2] = state[1][2] + state[2][2] + state[3][2];
	sums[1][1] = state[4][1] + state[5][1] + state[6][1];
	sums[1][2] = state[4][2] + state[5][2] + state[6][2];
	sums[2][1] = state[7][1] + state[8][1] + state[9][1];
	sums[2][2] = state[7][2] + state[8][2] + state[9][2];
	sums[3][1] = state[1][1] + state[4][1] + state[7][1];
	sums[3][2] = state[1][2] + state[4][2] + state[7][2];
	sums[4][1] = state[2][1] + state[5][1] + state[8][1];
	sums[4][2] = state[2][2] + state[5][2] + state[8][2];
	sums[5][1] = state[3][1] + state[6][1] + state[9][1];
	sums[5][2] = state[3][2] + state[6][2] + state[9][2];
	sums[6][1] = state[1][1] + state[5][1] + state[9][1];
	sums[6][2] = state[1][2] + state[5][2] + state[9][2];
	sums[7][1] = state[3][1] + state[5][1] + state[7][1];
	sums[7][2] = state[3][2] + state[5][2] + state[7][2];
	for ( i = 0 ; i < 8 ; i++ ) {
		if ( sums[i][1] == 0 || sums[i][2] == 0 ){
			chances++;break;
		}
	}
	if ( !chances )
		return 0;
	return -1;
}

/**********************************************************************
FUNCTION TO UPDATE THE STATE OF THE BOARD
STATE INDICATES THAT WE KNOW THAT WHICH PLACE BELONG TO WHICH PLAYER
**********************************************************************/
void update_state( int state[][3] ) {
	size_t i;
	for ( i = 1 ; i < 10 ; i++ ) {
		switch( square[i] ) {
			case 'X':
			state[i][1] = 1;break;
			case 'O':
			state[i][2] = 2;break;
			default:
			break;
		}
	} 
}

/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}

/*******************************************************************
				END OF PROJECT
********************************************************************/

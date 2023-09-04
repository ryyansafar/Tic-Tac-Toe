#include <iostream>
#include <string>
using namespace std;

const int COLUMNS = 3;
const int ROWS = 3;

void printGrid(string play_Grid[COLUMNS][ROWS]); 
// prints the layout of the grid

void getUserInput(string play_Grid[COLUMNS][ROWS]); 
// gets user input

bool ifOccupied(string play_Grid[COLUMNS][ROWS], int position); 
// checks if the position is occupied or not

string getWinner(string play_Grid[COLUMNS][ROWS]); 
// finds the winner if board isn't full. Returns the character who won or returns C for cats game(draw) if draw with board full or returns (<space>) if game still on

bool fullBoard(string play_Grid[COLUMNS][ROWS]);
// checks if board is full

int sampleGrid[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//a dummy grid to find i and j

bool gameOverVar = false;
// a bool variable to see if game is over or not

bool player1 = true;
bool player2 = false;
// the above both is to initialize turns for both players

int x, y;
// a global x and y to store the position


int main()
{
	int round = 1; 
	// round initializer

	string playGrid[3][3] = { {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };
	// the main playing Grid

	cout << "Welcome to the Classic Game of Tic-Tac-Toe" << endl;
	printGrid(playGrid); 
	// prints grid


	cout << "Player 1 is X\nPlayer 2 is O" << endl << endl;


	while (gameOverVar == false)
	// loops until gameover is true

	{
		cout << "Round " << round << endl << endl;

		getUserInput(playGrid);
		printGrid(playGrid);
		// prints the current grid after user input

		if (player1 == true)
		{
			player2 = true;
			player1 = false;
		}
		else
		{
			player2 = false;
			player1 = true;
		}
		// the above code changes turns after each round


		round++;
		string winner = getWinner(playGrid);
		//prints out <white space> if game isn't over
	}
	// exits if gameOverVar is true

	string winner = getWinner(playGrid);
	// Please refer function definition


	if (winner == "X" || winner == "O")
	{
		cout << "Congratulations, " << winner << " is the winner!";
		return 0;
	}
	cout << "The match is a draw";
	//ie if winner = "C" for Cat's Game

	return 0;
}	

void printGrid(string play_Grid[COLUMNS][ROWS])
{
	int position = 1; 
	// initializes position to 1 

	cout << " ___ ___ ___ " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|   |   |   |   " << endl;
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			if (play_Grid[i][j] == " ")
			{
				cout << " " << to_string(sampleGrid[i][j]) << " |";
				//if the element in the current position is a space it displays the current position, else prints out X or O.
			}
			else
			{
				cout << " " << play_Grid[i][j] << " |";
			}
			position++;
		}
		cout << endl << "|___|___|___|" << endl;
	}
}

void getUserInput(string play_Grid[COLUMNS][ROWS])
{
	if (player1 == true)
	{
		cout << "Player 1 (X)" << endl;
	}
	else
	{
		cout << "Player 2 (O)" << endl;
	}
	
	int position;
	do
	{
		cout << endl << "Enter position : ";
		cin >> position;
		cout << endl;
	} while (position < 1 || position > 9);
	// only performs the code if position is between 1 and 9


	bool occupied = ifOccupied(play_Grid, position);
	// checks if the current position is occupied or not


	if (occupied == true)
	{
		cout << "That position is already occupied. Please try again" << endl;
		getUserInput(play_Grid);
	}
	// if occupied, reprompts the user again for the input


	if (player1 == true)
	{
		play_Grid[x][y] = "X";
	}
	else if (player2 == true)
	{
		play_Grid[x][y] = "O";
	}
	// changes the grid accordingly
}

bool ifOccupied(string play_Grid[COLUMNS][ROWS], int position)
{
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (sampleGrid[i][j] == position) 
			// gets the position from the sample grid

			{
				if (play_Grid[i][j] != " ")
				// Then checks if that position is a white space or not

				{
					return true;
					// returns true if occupied else false
				}
				x = i;
				y = j;
				return false;
			}
		}
	}
}

string getWinner(string play_Grid[COLUMNS][ROWS])
{
	if (fullBoard(play_Grid) == false)
	// to print the winner

	{
		if (play_Grid[0][0] == "X" && play_Grid[0][1] == "X" && play_Grid[0][2] == "X" ||
			play_Grid[1][0] == "X" && play_Grid[1][1] == "X" && play_Grid[1][2] == "X" ||
			play_Grid[2][0] == "X" && play_Grid[2][1] == "X" && play_Grid[2][2] == "X" ||
			play_Grid[0][0] == "X" && play_Grid[1][0] == "X" && play_Grid[2][0] == "X" ||
			play_Grid[0][1] == "X" && play_Grid[1][1] == "X" && play_Grid[2][1] == "X" ||
			play_Grid[0][2] == "X" && play_Grid[1][2] == "X" && play_Grid[2][2] == "X" ||
			play_Grid[0][0] == "X" && play_Grid[1][1] == "X" && play_Grid[2][2] == "X" ||
			play_Grid[0][2] == "X" && play_Grid[1][1] == "X" && play_Grid[2][0] == "X")
		{
			// goes through all possiblities of a win

			gameOverVar = true; 
			// returns game over if won

			return "X";
		}
		else if (play_Grid[0][0] == "O" && play_Grid[0][1] == "O" && play_Grid[0][2] == "O" ||
			play_Grid[1][0] == "O" && play_Grid[1][1] == "O" && play_Grid[1][2] == "O" ||
			play_Grid[2][0] == "O" && play_Grid[2][1] == "O" && play_Grid[2][2] == "O" ||
			play_Grid[0][0] == "O" && play_Grid[1][0] == "O" && play_Grid[2][0] == "O" ||
			play_Grid[0][1] == "O" && play_Grid[1][1] == "O" && play_Grid[2][1] == "O" ||
			play_Grid[0][2] == "O" && play_Grid[1][2] == "O" && play_Grid[2][2] == "O" ||
			play_Grid[0][0] == "O" && play_Grid[1][1] == "O" && play_Grid[2][2] == "O" ||
			play_Grid[0][2] == "O" && play_Grid[1][1] == "O" && play_Grid[2][0] == "O")
		{
			gameOverVar = true;
			return "O";
		}
		else
		{
			return " "; 
			// else returns a standard white space

		}
	}
	gameOverVar = true; 
	// or if the board is full returns C for cats draw to indicate a draw game

	return "C";
}

bool fullBoard(string play_Grid[COLUMNS][ROWS])
{
	int played = 0;
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			if (play_Grid[i][j] != " ")
			{
				played++;
			}
		}
	}
	if (played == 9)
	// if all the grid is occupied, the played counter reaches 9 and indicates a full board

	{
		return true;
	}
	return false;
}
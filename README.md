# TicTacToe

## Description
This is a basic Tic-Tac-Toe Game I made with C++. Since I'm just getting used to the language, I decided to start off with this small project. Also this is my first **GIT PUSH** as well I guess (excluding my CS50 pushes). Anyway To the project We go
## Functions
- [`void printGrid(string play_Grid[COLUMNS][ROWS]);`](#void-printgridstring-play_gridcolumnsrows)
- `void getUserInput(string play_Grid[COLUMNS][ROWS]);`
- `bool ifOccupied(string play_Grid[COLUMNS][ROWS], int position);`
- `string getWinner(string play_Grid[COLUMNS][ROWS]);`
- `bool fullBoard(string play_Grid[COLUMNS][ROWS]);`


## Variables (Global)
- `int sampleGrid[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };`
- `bool gameOverVar = false;`
- `bool player1 = true;`
- `bool player2 = false;`
- `int x, y;`


### int(main)

> `roundint round = 1; `

> `string playGrid[3][3] = { {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };`

```
while (gameOverVar == false)
// loops until gameover is true
```

In This, The only thing extra are
- round initialiser
- The playing grid with spaces for empty spaces.

The game goes on until `getWinner()` is true. This is done by a simple while loop and once one round finishes the round variable increases by one.

Now, by default the starting player is X and the turns are changed by reversing the bool values of each player.

The winner is determined by the `getWinner()` function and if results in white space then `gameOverVar` is still false or else if it results in either ==C== or ==X== or ==O==, `gameOverVar` turns true

The program is exited with code 0 if successful.

---
### `void printGrid(string play_Grid[COLUMNS][ROWS]);`




# TicTacToe
---
## Description
This is a basic Tic-Tac-Toe Game I made with C++. Since I'm just getting used to the language, I decided to start off with this small project. Also this is my first **GIT PUSH** as well I guess (excluding my CS50 pushes). Anyway To the project We go


- ### Functions
  - [`void printGrid(string play_Grid[COLUMNS][ROWS]);`](#void-printgridstring-play_gridcolumnsrows)
  - [`void getUserInput(string play_Grid[COLUMNS][ROWS]);`](#void-getuserinputstring-play_gridcolumnsrows)
  - [`bool ifOccupied(string play_Grid[COLUMNS][ROWS], int position);`](#bool-ifoccupiedstring-play_gridcolumnsrows-int-position)
  - [`string getWinner(string play_Grid[COLUMNS][ROWS]);`](#string-getwinnerstring-play_gridcolumnsrows)
  - [`bool fullBoard(string play_Grid[COLUMNS][ROWS]);`](#bool-fullboardstring-play_gridcolumnsrows)


- ### Variables (Global)
  - `int sampleGrid[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };` [^1]
  - `bool gameOverVar = false;` [^2]
  - `bool player1 = true;`
  - `bool player2 = false;` [^3]
  - `int x, y;` [^4]

---


#### `int(main)`

> `roundint round = 1; `

> `string playGrid[3][3] = { {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };`

```
while (gameOverVar == false)
// loops until gameover is true
```

In This, The only thing extra are
- round initialiser
- The playing grid with spaces for empty spaces.

The game goes on until the game over variable is true. This is done by a simple while loop and once one round finishes the round variable increases by one.

Now, by default the starting player is X and the turns are changed by reversing the bool values of each player.

The winner is determined by the `getWinner()` function and if results in white space then `gameOverVar` is still false or else if it results in either == C == or == X == or == O ==, `gameOverVar` turns true

The program is exited with code 0 if successful.


---


### `void printGrid(string play_Grid[COLUMNS][ROWS]);`

> `int position = 1;`

: initializes the position to 1 and works with a for loop to finish the rest of the grid

> ```
> if (play_Grid[i][j] == " ")
> {
>	cout << " " << to_string(sampleGrid[i][j]) << " |";
> }
> else
> {
>	cout << " " << play_Grid[i][j] << " |";
> }
> ```

In the for loop after going through the values of i and j, checks if the element in the [i][j]'th position is a space or not. If it is a space then prints out the position number by changing the integer value of the element in the same position BUT from the **`samplegrid`** array. Else prints out the element in `play_Grid`.

---

#### `void getUserInput(string play_Grid[COLUMNS][ROWS]);`

Gets user input as function name suggests.

Prints out the player whose turn is next in the beginning.

Then prompts the user for a number between 0 and 9 ( re prompts if its more than that)



> `bool occupied = ifOccupied(play_Grid, position);`

Stores the bool value from the return of `ifOccupied()` function.
If true, restarts the `getUserInput` function again.
else, changes the value of the position in the `play_grid[][3]` to the element of the player

#### `bool ifOccupied(string play_Grid[COLUMNS][ROWS], int position)`

a function which checks if the element in `play_Grid` at `position` is occupied. returns true if element isn't a space. else returns false and sets the values of `x` and `y` as i and j.
```
x = i;
y = j;
```
---
#### `string getWinner(string play_Grid[COLUMNS][ROWS])`

checks for the winning cases if `fullboard()` returns false.
```
if (play_Grid[0][0] == "X" && play_Grid[0][1] == "X" && play_Grid[0][2] == "X" ||
	play_Grid[1][0] == "X" && play_Grid[1][1] == "X" && play_Grid[1][2] == "X" ||
	play_Grid[2][0] == "X" && play_Grid[2][1] == "X" && play_Grid[2][2] == "X" ||
	play_Grid[0][0] == "X" && play_Grid[1][0] == "X" && play_Grid[2][0] == "X" ||
	play_Grid[0][1] == "X" && play_Grid[1][1] == "X" && play_Grid[2][1] == "X" ||
	play_Grid[0][2] == "X" && play_Grid[1][2] == "X" && play_Grid[2][2] == "X" ||
	play_Grid[0][0] == "X" && play_Grid[1][1] == "X" && play_Grid[2][2] == "X" ||
	play_Grid[0][2] == "X" && play_Grid[1][1] == "X" && play_Grid[2][0] == "X")
```

this checks all the main possiblities for both cases.
- vertically
- horizontally
- diagonally

if the case is a winning one, then the function sets `gameOverVar` as true thereby prompting the while loop in `main` to exit. and returns the winner letter as well. else prints out " " which does nothing

But if `fullboard` returns true. function returns "C" for Cat's Game which indicates a draw

---

#### `bool fullBoard(string play_Grid[COLUMNS][ROWS])`

> `int played = 0;`

a variable which should conut upto 9 (max number of grids). Increments if the [i][j]th locations of play_Grid[][] is not a space

and if `played` becomes 9. it indicates a full board and returns true.



# ~ *fin* ~
---


[^1]: A dummy grid which makes it easier to get the position easily

[^2]: Variable which determines if the game is over

[^3]: turn initializer. By default, X starts first and after X's turn `player1` turns false and `player2` turns true and so on.

[^4]: stores the position of the user input to change the element to whichever player is playing

# Minesweeper
This is the Minesweeper game created by group 10 - CS161 - 21APCS1

## Members
* 21125029 - Tran Tuan Viet
* 21125076 - Hoang Thien Duc

## Description
The game is coded in C++17 using the multimedia library [SFML 2.5.1](https://www.sfml-dev.org/index.php).

In this game, we will have a board which is divided into cells, with mines randomly distributed to some cells.  To win, we need to open all safety cells without touching the mines. 
* We can use the left mouse button to open a cell.
* The number on a cell show the number of mines adjacent to it.
* If there is no number on a cell, that means there is no cells around it contain mines.
* Using this information, we can determine safe cells or mine cells.

We will have 3 basic levels corresponding to number of cells in a board
* Beginner: 9 rows, 9 columns and 10 mines
* Medium: 16 rows, 16 columns and 40 mines
* Expert: 16 rows, 30 columns and 99 mines

Beside 3 basic levels, we can choose the custom level to freely determine the number of columns, rows and mines of the board.

## Getting Started
### Installing
* Clone the project to your computer. 
```
  git clone https://github.com/ttviet2805/MINESWEEPER.git
```
* Set up [SFML Library](https://www.sfml-dev.org/tutorials/2.5/start-vc.php).

### Executing program
* Using an IDE to compile this game (Codeblocks, Visual Studio, ...)
* Remember to add all source codes to project before building and running

## Contact
Tran Tuan Viet - ttviet2805@gmail.com

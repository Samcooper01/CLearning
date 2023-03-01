//
// The Sudoku Solver.
// Author: Sam Cooper
//
// Purpose: to solve basic sudoku puzzles which can be solved using exclusion rules
//
#include <stdint.h>
#include <stdbool.h>

//constants
extern const int sizeOfBoard;
extern const int sizeOfBox;

//Example of a Box (3*3):
// 0 1 2 
// 3 4 5 
// 6 7 8 

typedef int box[9];

typedef box board[9];

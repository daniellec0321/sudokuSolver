// Function declarations for sudokuSolver

#ifndef SFUNC_H
#define SFUNC_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

#define SIZE 9
#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl
#define VECTOR std::vector
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

// prints a warning to the user
void warning(void);

// reads a file and creates sudoku board
void read_puzzle(IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku);

// checks the integrity of the given sudoku board
bool check_integrity(const VECTOR< VECTOR<int> > sudoku);

// prints a given sudoku puzzle to the terminal
void print_puzzle(const VECTOR< VECTOR<int> > sudoku);

// checking if a number can be placed in a certain spot
bool check_guess(const VECTOR< VECTOR<int> > sudoku, const int value, const int valRow, const int valCol);

// solves puzzle recursively
bool recursive_solver(VECTOR< VECTOR<int> >& sudoku, int row, int col);

// print a puzzle to a file
void print_puzzle_to_file(OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> > sudoku);

#endif

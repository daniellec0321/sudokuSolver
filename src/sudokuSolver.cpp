// main file for the sudokuSolver

#include "../include/sfunc.h"



int main(const int argc, const char *argv[]) {

	// if user entered incorrect amount of inputs
	if (argc != 3) {
		COUT << "Incorrect number of inputs." << ENDL;
		return EXIT_FAILURE;
	}

	// initializing reading streams
	IFSTREAM sudoku_infile;
	sudoku_infile.open(argv[1]);

    // testing if file exists
    if (sudoku_infile.fail()) {
        COUT << "File does not exist" << ENDL;
        return EXIT_FAILURE;
    }

    // Print warning to user
    warning();

	// initializing sudoku board
    VECTOR<int> vtemp(SIZE, 9);
	VECTOR< VECTOR<int> > sudoku(SIZE, vtemp);

	// filling the sudoku board
	read_puzzle(sudoku_infile, sudoku);

	// print puzzle
	COUT << ENDL << "Original puzzle:" << ENDL;
	print_puzzle(sudoku);

    // checking integrity of original board
    if (!check_integrity(sudoku)) {
        COUT << ENDL << "Not a valid sudoku puzzle." << ENDL << ENDL;
        return EXIT_FAILURE;
    }

	// Solving the puzzle
	if (recursive_solver(sudoku, 0, 0)) { 
		COUT << ENDL << "Solved puzzle:" << ENDL;

    // puzzle is not solvable
    } else {
		COUT << ENDL << "Puzzle is not solvable." << ENDL << ENDL;
        return EXIT_FAILURE;
    }

	// print puzzle to terminal
	print_puzzle(sudoku);
	COUT << ENDL;

    // initializing writing streams
	OFSTREAM sudoku_outfile;
	sudoku_outfile.open(argv[2]);

	// print puzzle to file
	print_puzzle_to_file(sudoku_outfile, sudoku);

	return EXIT_SUCCESS;

}

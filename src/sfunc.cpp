// Function definitions for sudokuSolver

#include "../include/sfunc.h"



// print a timing warning to the reader
void warning(void) {

    COUT << ENDL << "Depending on the puzzle, the solver may take a couple of minutes." << ENDL;

    return;

}



// reads a file stream and creates the sudoku board
void read_puzzle(IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku) {

	// setting temporary readers
	std::string temp_str;

	// row and column iterators
	int row = 0;
	int col = 0;

	// while loop to read file stream
	while (sudoku_infile >> temp_str) {

		// putting the number in the vector
		sudoku[row][col] = stoi(temp_str);

		// iterating column
		col++;

		// if at end of row
		if (col >= SIZE) {
			col = 0;
			row++;
		}

		// if at end of file
		if (row >= SIZE)
			break;

	}

	// closing file stream
	sudoku_infile.close();

	return;

}



// checks the integrity of the given board
bool check_integrity(const VECTOR< VECTOR<int> > sudoku) {

    // loop through the board
    for (int row=0; row<SIZE; row++) {

        for (int col=0; col<SIZE; col++) {

            // if a zero, continue
            if (sudoku[row][col] == 0)
                continue;

            // first check if valid number
            if ((sudoku[row][col] < 0) || (sudoku[row][col] > 9))
                return false;

            // Now do "check guess" with current val
            if (!check_guess(sudoku, sudoku[row][col], row, col))
                return false;

        }

    }

    // if no problems encountered, return true
    return true;

}



// print a given sudoku puzzle to the terminal
void print_puzzle(const VECTOR< VECTOR<int> > sudoku) {

	// for loop to print sudoku board
	for (int row=0; row<SIZE; row++) {

		for (int col=0; col<SIZE; col++) {

			// printing the number and whitespace
			COUT << sudoku[row][col] << " ";

		}

		// printing newline
		COUT << ENDL;

	}

	return;

}



// checks if a number can be placed in a certain spot
bool check_guess(const VECTOR< VECTOR<int> > sudoku, const int value, const int valRow, const int valCol) {

	// checking row
	for (int row=0; row<SIZE; row++) {

		// making sure to skip over original placement
		if (row == valRow) 
            continue;

		// checking that this is a valid placement
        if (sudoku[row][valCol] == value)
            return false;

	}

	// checking column
	for (int col=0; col<SIZE; col++) {

		// making sure to skip over original placement
		if (col == valCol) 
            continue;

		// checking that this is a valid placement
        if (sudoku[valRow][col] == value)
            return false;

	}

	// finding where to start row and col for checking the boxes
	int start_row = valRow - (valRow%3);
	int start_col = valCol - (valCol%3);

	// have to check 9 boxes, loop total of nine times
    for (int row=start_row; row<start_row+3; row++) {

        for (int col=start_col; col<start_col+3; col++) {

			// check if this spot is the original; if it is, dont do if statement
			if (!((row == valRow) && (col == valCol))) {

				// check if this spot equals the value
                if (sudoku[row][col] == value)
                    return false;

			}

		}

	}
	
	// if no problems encountered, return true
	return true;

}



// solves the puzzle recursively
bool recursive_solver(VECTOR< VECTOR<int> >& sudoku, int row, int col) {

	// iterate to a 0
    while (sudoku[row][col] != 0) {

		// iterate to next box
		col++;
        
        // check limits
		if (col >= SIZE) {
			col = 0;
			row++;
		}

		// if at end of puzzle (base case)
		if (row >= SIZE)
			return true;

	}

	for (int sentinel=1; sentinel<=SIZE; sentinel++) {

		// if guess not valid, conitnue
		if (!check_guess(sudoku, sentinel, row, col))
            continue;

		// set the sudoku board equal to the sentinel
        sudoku[row][col] = sentinel;

		// if the recursive call is true
		if (recursive_solver(sudoku, row, col)) 
			return true;

		// if not true, put 0 back in the puzzle
        sudoku.at(row).at(col) = 0;
		
	}

	// if there is no value that works in this spot, evaluate to false
	return false;

}



// prints puzzle to a file
void print_puzzle_to_file(OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> > sudoku) {

	// for loop to print row by row of sudoku board
	for (int row=0; row<SIZE; row++) {

		for (int col=0; col<SIZE; col++) {

			// printing number and whitespace
			sudoku_outfile << sudoku[row][col] << " ";

		}

		// printing endline character
		sudoku_outfile << ENDL;

	}

	// closing file
	sudoku_outfile.close();
	
	return;

}

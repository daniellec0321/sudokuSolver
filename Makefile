# g++ is for the GCC compiler for C++
CC := g++

# Flags for compiling
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -lm
CXXFLAGS := -m64 -std=c++11 $(FLAGS)

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# Make initialize - Create the objects and executables
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# on make, create object file for sudoku.cpp in objects folder (Singly Linked List Object)
$(OBJ)/sfunc.o: $(SRC)/sfunc.cpp $(INC)/sfunc.h
	$(CC) $(CXXFLAGS) -c $(SRC)/sfunc.cpp -o $@

# on make, create object file for PC05.cpp in objects folder
# might have problem with SRC/sudokuSolver, maybe switch
$(OBJ)/sudokuSolver.o: $(SRC)/sudokuSolver.cpp $(INC)/sfunc.h
	$(CC) $(CXXFLAGS) -c $(SRC)/sudokuSolver.cpp -o $@

# Create variables for all objects
sudokuSolver_objs := $(OBJ)/sfunc.o $(OBJ)/sudokuSolver.o

# Singly Linked List Executable and Run
sudokuSolver: $(sudokuSolver_objs)
	$(CC) $(CXXFLAGS) -o $(EXE)/sudokuSolver $(sudokuSolver_objs)

# Make clean
clean:
	rm -rf $(OBJ)/* $(EXE)/*



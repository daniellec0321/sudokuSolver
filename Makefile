# Compiler flags
FLAGS := -m64 -std=c++11 -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# Make initialize - Create the objects and executables
initialize: ; rm -rf $(OBJ) $(EXE) ; mkdir $(OBJ) $(EXE)

# On make, create objects and executables
sudokuSolver: ; g++ $(FLAGS) -c $(SRC)/sfunc.cpp -o $(OBJ)/sfunc.o ; g++ $(FLAGS) -c $(SRC)/sudokuSolver.cpp -o $(OBJ)/sudokuSolver.o ; g++ $(FLAGS) -o $(EXE)/sudokuSolver $(OBJ)/sfunc.o $(OBJ)/sudokuSolver.o

# Clean the objects and executables
clean: ; rm -rf $(OBJ)/* $(EXE)/*

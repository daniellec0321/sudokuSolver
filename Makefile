# Compiler flags
FLAGS := -m64 -std=c++11 -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm

# Folder Variables
INC := include
SRC := src
OBJ := objects
EXE := exe

# On make, create objects and executables
# This creates a folder to put the object files, and then once the executable is made, deletes the object folder
all: ; rm -rf $(EXE) ; mkdir $(OBJ) $(EXE) ; g++ $(FLAGS) -c $(SRC)/sfunc.cpp -o $(OBJ)/sfunc.o ; g++ $(FLAGS) -c $(SRC)/sudokuSolver.cpp -o $(OBJ)/sudokuSolver.o ; g++ $(FLAGS) -o $(EXE)/sudokuSolver $(OBJ)/sfunc.o $(OBJ)/sudokuSolver.o ; rm -rf $(OBJ)

# Clean the objects and executables
clean: ; rm -rf $(EXE)

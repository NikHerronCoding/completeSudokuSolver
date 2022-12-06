/* SUDOKU SOLVER PROGRAM MADE BY: NIK HERRON 

INPUT: This procedural program takes a text file as input that represents an unsolved sudoku, the input .txt file is an 81 character encoded file where there are 9 rows of 9 single digit ints to represent the state of the unsolved sudoku
PROCESS: This procedural program will solve the sudoku by iterating through the grid and trying to brute force the solution with a depth first search algorithm with backtracking
OUTPUT: This procedural program outputs a solved .txt file which is  9 rows of 9 ints representing the solved sudoku grid

*/


//header

#include<fstream>
#include<string>
#include<array>
#include<iostream>
#include "SudokuSolver.h"

//function declarations

//this function will run to open a text file containing the puzzle you want solved. It opens the file and returns an array of the 81 values in the unsolved sudoku
std::array<int, 81> load_puzzle(std::string filename);

//this function will take the solved puzzle state and save the state as a file
void save_puzzle(std::array<int, 81> puzzle, std::string filename);

//this function will solve the puzzle using a reference variable to edit puzzle
void solve_puzzle(std::array<int, 81>& puzzle);

//this function just prints a puzzle in its current state to the command line, it is a good tool to debug and understand whats happening behind the scenes
void print_puzzle(std::array<int, 81> puzzle);

//this function gets the path for the unsolved sudoku
std::string getInput();

//main
int main() {

    bool puzzleSolved;

    std::string fileName;
    std::string folderPath;
    std::string savePath;

    //the variable "puzzle" here will represent the state of the sudoku grid
    fileName = getInput();
    
    std::array<int, 81> puzzle = load_puzzle(fileName);
    std::array<int, 81> originalPuzzle = load_puzzle(fileName);
    
    std::cout << "Given Sudoku: " << std::endl << std::endl;
    //this runs the function command to solve the puzzle (not created yet - last thing to do)
    print_puzzle(puzzle);
    std::cout << std::endl;

    solvePuzzle(puzzle, originalPuzzle);

    //this will save the state of the puzzle in a txt file that represents the sudoku grid
    std::cout << "Enter the folder path you want to save the solution .txt file: (NO QUOTATION MARKS PLEASE)" << std::endl;

   
    std::getline(std::cin, folderPath);

    savePath = folderPath + "/solved.txt";

    save_puzzle(puzzle, savePath);

    return 0;

}
 

//contains file I/O, Arrays,
std::array<int, 81> load_puzzle(std::string filename) {
    int num_characters = 9;
    int num_lines = 9;
    int index;
    std::fstream infile;
    char ch;
    infile.open(filename);
    std::array<int, 81> puzzle;
    std::string line;

    //nested for loops here
    for (int i = 0; i < num_lines; i++) {
        infile >> line;
        for (int j = 0; j < num_characters; j++) {
            index = (i * 9) + j;

            //the -48 comes with conversion of char to int of each number
            puzzle[index] = line[j] - 48;

        }
    }

    infile.close();

    return puzzle;
}


//contains file io
void save_puzzle(std::array<int, 81> puzzle, std::string filename) {
    std::ofstream outfile;
    outfile.open(filename);
    for (int i = 0; i < puzzle.size(); i++) {
        if (i % 9 == 0 && i != 0) {
            outfile << '\n';
        }
        outfile << puzzle[i];
    }

    outfile.close();
    return;
}

//contains user input
std::string getInput() {
    std::string userInput;
    std::cout << "Please enter the path to the unsolved sudoku: NO QUOTES IN PATHNAME PLEASE! " << std::endl;
    std::getline(std::cin, userInput);
    return userInput;
}
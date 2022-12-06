#include<array>
#include<iostream>


#include "SudokuSolver.h"


/* function: rowSolved  - this function measures a row (1-9) and checks to make sure there are no repeating values, and that all values outside of zero (1-9) are used only once.
Input: arg1: Puzzle to check row
       arg2: which row to check
Process: Checks to make sure there are no repeating values, and that the values 1-9 are only used once
Output:  boolean where
*/

bool row_solved(std::array<int, 81> puzzle, int row) {
    int numberTracker[9] = { 0,0,0,0,0,0,0,0,0 };
    int numberTrackerLength = sizeof(numberTracker) / sizeof(int);
    int startingIndex = (row - 1) * 9;
    int endingIndex = startingIndex + 9;
    int currentIndex;
    int currentValue;

    /*for loop goes through row and counts frequency of numbers to an array where
    int value is mapped to its index + 1 (ie numberTracker[0] = number of times "1" is found)*/

    for (int i = 0; i + startingIndex < endingIndex; i++) {

        currentIndex = i + startingIndex;

        currentValue = puzzle[currentIndex];

        //if value is 0 ignore
        if (currentValue != 0) {
            numberTracker[currentValue - 1] += 1;
        }

    }

    //for loop goes through numberTracker array and returns true only if all values are used exactly once 
    for (int j = 0; j < numberTrackerLength; j++) {
        if (numberTracker[j] != 1) {
            return false;
        }
    }
    return true;
}

bool row_failed(std::array<int, 81> puzzle, int row) {
    int numberTracker[9] = { 0,0,0,0,0,0,0,0,0 };
    int numberTrackerLength = sizeof(numberTracker) / sizeof(int);
    int startingIndex = (row - 1) * 9;
    int endingIndex = startingIndex + 9;
    int currentIndex;
    int currentValue;


    /*for loop goes through row and counts frequency of numbers to an array where
    int value is mapped to its index + 1 (ie numberTracker[0] = number of times "1" is found)*/

    for (int i = 0; i + startingIndex < endingIndex; i++) {

        currentIndex = i + startingIndex;

        currentValue = puzzle[currentIndex];

        //if value is 0 ignore
        if (currentValue != 0) {
            numberTracker[currentValue - 1] += 1;
        }

    }


    //for loop goes through numberTracker array and returns true only if all values are used more than once
    for (int j = 0; j < numberTrackerLength; j++) {
        if (numberTracker[j] > 1) {
            //std::cout << "Square " << j << " failed.";
            return true;
        }
    }
    return false;
}

//goes through the specified column number (starting at 1) and sees if the column is solved. If column is solved returns true
bool colSolved(std::array<int, 81> puzzle, int column) {
    int numberCounter[9] = { 0,0,0,0,0,0,0,0,0 };
    int value = 0;
 

    //adding values to counting array
    for (int i = column - 1; i < 81; i += 9) {
        value = puzzle[i];
        if (value != 0) {
            numberCounter[value - 1] += 1;
        }
    }
    //goes through number frequency. if value not eq 1 return false
    for (int i = 0; i < 9; i++) {
        if (numberCounter[i] != 1) {
            return false;
        }
    }
    return true;
}

//goes through the specified column number (starting at 1) and sees if the column is solved. If column is solved returns true
bool colFailed(std::array<int, 81> puzzle, int column) {
    int numberCounter[9] = { 0,0,0,0,0,0,0,0,0 };
    int value = 0;


    //adding values to counting array
    for (int i = column - 1; i < 81; i += 9) {
        value = puzzle[i];
        if (value != 0) {
            numberCounter[value - 1] += 1;
        }
    }
    //goes through number frequency. if value not eq 1 return false
    for (int i = 0; i < 9; i++) {
        if (numberCounter[i] > 1) {
            //std::cout << "col " << column << " failed. Number:" << i + 1 << " with " << numberCounter[i] << " digits.";
            return true;
        }
    }
    return false;
}

bool squareFailed(std::array<int, 81> puzzle, int square) {
    int numbercounter[9] = { 0,0,0,0,0,0,0,0,0 };
    int startingIndex = (((square - 1) % 3) * 3) + (((square - 1) / 3) * 27); \
    int endIndex = startingIndex + 20;
    int value = 0;

    //finding numbers on each square
    for (int i = startingIndex; i < endIndex; i += 9) {
        for (int j = i; j < i + 3; j++) {
            value = puzzle[j];

            if (value != 0) {
                numbercounter[value - 1] += 1;
            }
        }
    }
    //if any number is used more than once return true becuase it fails
    for (int i = 0; i < 9; i++) {
        if (numbercounter[i] > 1) {
            //std::cout << "Square " << square << " failed with digit" << i + 1 << " " << numbercounter[i]  << " many times" << std::endl;
            return true;
        }
    }
    return false;
}

bool squareSolved(std::array<int, 81> puzzle, int square) {
    int numbercounter[9] = { 0,0,0,0,0,0,0,0,0 };
    int startingIndex = (((square - 1) % 3) * 3) + (((square - 1) / 3) * 27); \
    int endIndex = startingIndex + 20;
    int value = 0;

  
    //finding numbers on each square
    for (int i = startingIndex; i < endIndex; i += 9) {
        for (int j = i; j < i + 3; j++) {
            value = puzzle[j];

            if (value != 0) {
                numbercounter[value - 1] += 1;
            }
        }
    }
    //if any number is used more than once return true becuase it fails
    for (int i = 0; i < 9; i++) {
        if (numbercounter[i] != 1) {
            return false;
        }
    }
    return true;
}
//determines if puzzle is solved
bool solved(std::array<int, 81> puzzle) {
    bool row = true;
    bool col = true;
    bool square = true;

    for (int i = 1; i <= 9; i++) {
        row = row_solved(puzzle, i);
        col = colSolved(puzzle, i);
        square = squareSolved(puzzle, i);

        if (!(row == true && col == true && square == true)) {
            return false;
        }
    }
    return true;
}
//determines if puzzle breaks a rule in its current state
bool fails(std::array<int, 81> puzzle) {
    bool row = true;
    bool col = true;
    bool square = true;

    for (int i = 1; i <= 9; i++) {
        row = row_failed(puzzle, i);
        col = colFailed(puzzle, i);
        square = squareFailed(puzzle, i);

        if (row == true || col == true || square == true) {
            return true;
        }
    }
    return false;
}
//algorithmic next iteration
void next(std::array<int, 81> &puzzle) {
    int index = 0;
    int value = puzzle[index];

    //goes to first value that equals 0
    while (value != 0 && index < 81) {
        index++;
        value = puzzle[index];
    }

    //gives value of 1 to first encountered 0 value
    if (index > 80) {
        //if puzzle complete
        //do nothing
    }
    else {
        puzzle[index] = 1;
    }

    return;
}
//outputs state of puzzle to command line. Useful for debugging!
void print_puzzle(std::array<int, 81> puzzle) {
    for (int k = 0; k < puzzle.size(); k++) {
        if (k % 9 == 0) {
            std::cout << "\n";
        }
        std::cout << puzzle[k];
    }
    std::cout << std::endl;
}
//algorithmic backtack
void backtrack(std::array<int, 81>& puzzle, const std::array<int, 81> originalPuzzle) {
    int latestIndex = 0;
    int workingIndex;
    int value = puzzle[latestIndex];

    //goes to first zero in the puzzle or last value
    while ((value != 0) && (latestIndex < 80)) {
        latestIndex++;
        //std::cout << "latest Index: " << latestIndex << std::endl;
        value = puzzle[latestIndex];
    }

    //goes back 1 index if wasnt last value
    if (latestIndex == 80 && value != 0) {
        workingIndex = latestIndex;
    } else {
        workingIndex = latestIndex - 1;
    }

    //goes back to furthest modified piece that can actually be modified. Digits supplied by intial source cant be modified
    while (originalPuzzle[workingIndex] != 0) {
        workingIndex--;
    }

    //if digit is 9, need to go back to prev digit
    if (puzzle[workingIndex] == 9) {
        puzzle[workingIndex] = 0;
        backtrack(puzzle, originalPuzzle);
    }
    else {
        puzzle[workingIndex] += 1;
    }
    return;
}
//actually solves the puzzle 
void solvePuzzle(std::array<int, 81> &puzzle, const std::array<int, 81> originalPuzzle) {
    int iterations = 0;
    bool puzzleSolved = false;

    while (puzzleSolved == false && iterations < 100000) {
        next(puzzle);

        while (fails(puzzle) && iterations < 100000) {
        
            iterations += 1;
            backtrack(puzzle, originalPuzzle);
        }
        if (solved(puzzle)) {
            std::cout << "PUZZLE SOLVED!";
            puzzleSolved = true;
        }

        iterations += 1;
    }

    std::cout << "Solution Found. Took " << iterations << " steps." << std::endl;
    print_puzzle(puzzle);

    return;
}


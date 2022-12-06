#pragma once
#include<iostream> 

bool row_solved(std::array<int, 81> puzzle, int row);
bool row_failed(std::array<int, 81> puzzle, int row);
bool colSolved(std::array<int, 81> puzzle, int column);
bool colFailed(std::array<int, 81> puzzle, int column);
bool squareFailed(std::array<int, 81> puzzle, int square);
bool squareSolved(std::array<int, 81> puzzle, int square);
bool solved(std::array<int, 81> puzzle);
bool fails(std::array<int, 81> puzzle);
void next(std::array<int, 81>& puzzle);
void backtrack(std::array<int, 81>& puzzle, const std::array<int, 81> originalPuzzle);
void solvePuzzle(std::array<int, 81>& puzzle, const std::array<int, 81> originalPuzzle);
void print_puzzle(std::array<int, 81> puzzle);

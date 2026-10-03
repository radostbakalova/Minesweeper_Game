#pragma once
#include "Constants.h"
#include "Cell.h"
#include <vector>
#include <print>
#include <optional>

class Board {
	size_t rows = 0;
	size_t cols = 0;
	std::vector<std::vector<Cell>> board;
	std::vector<std::pair<int, int>> cellsToProcess;
	bool minesPlaced = false;
	int totalMines = 0;
	int flaggedMines = 0;
	
	void increaseFlags();
	void decreaseFlags();
	int generateRandomNumber();
	bool isCellInScope(size_t row, size_t col);
	int getSurroundingMines(int row, int col);
	void setNumberedCells();
	void triggerSurroundingCells(size_t row, size_t col);
	void revealNeighbors(int row, int col);
	void revealFirstCell(int row, int col);
	void printSymbol(char s, size_t count = 0);
	void processCells();

public:
	Board(size_t _rows, size_t _cols, int _totalMines);
	int getUnflaggedMines() const;
	void display();
	void placeMines();
	bool reveal(int row, int col);
};


#pragma once
#include "Constants.h"
#include "Cell.h"
#include <vector>
#include <print>

class Board {
	size_t rows = 0;
	size_t cols = 0;
	std::vector<std::vector<Cell>> board;
	std::vector<std::pair<int, int>> cellsToProcess;
	//std::vector<std::pair<int, int>> firstCellNeighbors;
	bool minesPlaced = false;
	int totalMines = 0;
	int revealedCells = 0;
	
	void setupMinefield(int firstRow, int firstCol);
	void placeMines(std::vector<std::pair<int, int>>& firstCellNeighbors);
	int generateRandomNumber() const;
	bool isCellInScope(size_t row, size_t col) const;
	int getSurroundingMines(int row, int col) const;
	void setNumberedCells();
	void triggerSurroundingCells(size_t row, size_t col);
	void setNeighbors(std::vector<std::pair<int, int>>& firstCellNeighbors, int row, int col);
	bool isNeighborOfFirstCell(std::vector<std::pair<int, int>>& firstCellNeighbors, int row, int col) const;
	void revealFirstCell(int row, int col);
	void printSymbol(char s, size_t count = 0) const;
	void processCells();

public:
	Board(size_t _rows, size_t _cols, int _totalMines);
	void display() const;
	bool reveal(int row, int col);
	void flag(int row, int col);
	void unflag(int row, int col);
	bool isBoardRevealed() const;
};


#include "Board.h"
#include <random>

void Board::setupMinefield(int firstRow, int firstCol) {
	std::vector<std::pair<int, int>> neighbors;
	setNeighbors(neighbors, firstRow, firstCol);
	placeMines(neighbors);
}

void Board::placeMines(std::vector<std::pair<int, int>>& firstCellNeighbors) {
	int mines = totalMines;
	while (mines > 0) {
		int num = generateRandomNumber();
		int row = num / cols;
		int col = num % cols;
		if (!isNeighborOfFirstCell(firstCellNeighbors, row,col) && !board[row][col].isRevealed() && !board[row][col].isMine()) {
			board[row][col].setAsMine();
			mines--;
		}
	}
	minesPlaced = true;
}

int Board::generateRandomNumber() const {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> numDist(0, rows * cols - 1);

	int num = numDist(gen);
	return num;
}

bool Board::isCellInScope(size_t row, size_t col) const {
	if (row < 0 || row >= rows || col < 0 || col >= cols)
		return false;
	return true;
}

int Board::getSurroundingMines(int row, int col) const {
	int mines = 0;
	for (size_t i = 0; i < GameConstants::NEIGHBORHOOD_SIZE; i++) {
		for (size_t j = 0; j < GameConstants::NEIGHBORHOOD_SIZE; j++) {
			int currentRow = row + i - 1;
			int currentCol = col + j - 1;
			if (isCellInScope(currentRow, currentCol) && board[currentRow][currentCol].isMine())
				mines++;
		}
	}
	return mines;
}

void Board::setNumberedCells() {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (!board[i][j].isMine()) {
				int mines = getSurroundingMines(i, j);
				board[i][j].setSurroundingMines(mines);
			}
		}
	}
}

void Board::triggerSurroundingCells(size_t row, size_t col) {
	for (size_t i = 0; i < GameConstants::NEIGHBORHOOD_SIZE; i++) {
		for (size_t j = 0; j < GameConstants::NEIGHBORHOOD_SIZE; j++) {
			int currentRow = row + i - 1, currentCol = col + j - 1;
			if (isCellInScope(currentRow,currentCol) && !board[currentRow][currentCol].isRevealed()
				&& !board[currentRow][currentCol].isFlagged()) {
				board[currentRow][currentCol].reveal();
				revealedCells++;
				cellsToProcess.push_back(std::pair(currentRow, currentCol));
			}
		}
	}
}

void Board::setNeighbors(std::vector<std::pair<int, int>>& firstCellNeighbors, int row, int col) {
	for (size_t i = 0; i < GameConstants::NEIGHBORHOOD_SIZE; i++) {
		for (size_t j = 0; j < GameConstants::NEIGHBORHOOD_SIZE; j++) {
			int currentRow = row + i - 1;
			int currentCol = col + j - 1;
			if ((currentRow != row || currentCol != col) && isCellInScope(currentRow, currentCol))
				firstCellNeighbors.push_back({ currentRow,currentCol });
		}
	}
}

bool Board::isNeighborOfFirstCell(std::vector<std::pair<int, int>>& firstCellNeighbors, int row, int col) const  {
	for (const auto& neighbor : firstCellNeighbors)
		if (neighbor.first == row && neighbor.second == col)
			return true;
	return false;
}

void Board::revealFirstCell(int row, int col) {
	board[row][col].reveal();
	revealedCells++;
	setupMinefield(row, col);
	setNumberedCells();
	cellsToProcess.push_back({ row, col });
	processCells();
}

void Board::printSymbol(char s, size_t count) const {
	if (count != 0) {
		for (size_t i = 0; i < count; i++)
			std::print("{}", s);
		std::println();
	}
	else
		std::print("{}", s);
}

void Board::processCells() {
	while (!cellsToProcess.empty()) {
		auto [row, col] = cellsToProcess.front();
		cellsToProcess.erase(cellsToProcess.begin());

		if (board[row][col].getSurroundingMines() == 0)
			triggerSurroundingCells(row, col);
	}
}

Board::Board(size_t _rows, size_t _cols, int _totalMines) : rows(_rows), cols(_cols),
board(rows, std::vector<Cell>(cols)), totalMines(_totalMines) {}

void Board::display() const {
	size_t totalRows = rows * GameConstants::ROW_DIMENTIONS + 1;
	size_t totalCols = cols * GameConstants::COL_DIMENTIONS + 1;
	int row = 0, col = 0;
	for (size_t i = 0; i < totalRows; i++) {
		if (i % 2 == 0) {
			printSymbol('-', totalCols);
			continue;
		}
		for (size_t j = 0; j < totalCols; j++) {
			if (j % GameConstants::COL_DIMENTIONS == 0) {
				printSymbol('|');
				continue;
			}
			if ((j - GameConstants::ROW_DIMENTIONS) % GameConstants::COL_DIMENTIONS == 0) {
				if (board[row][col].isFlagged()) {
					printSymbol('F');
					col++;
					continue;
				}
				if (board[row][col].isRevealed()) {
					if (board[row][col].isMine()) {
						printSymbol('M');
						col++;
						continue;
					}
					if (board[row][col].getSurroundingMines() != 0)
						printSymbol(static_cast<char>('0' + board[row][col].getSurroundingMines()));
					else
						printSymbol('0');
					col++;
					continue;
				}
				else {
					printSymbol(' ');
					col++;
					continue;
				}
			}
			printSymbol(' ');
		}
		std::println();
		row++;
		col = 0;
	}
}

bool Board::reveal(int row, int col) {
	try {
		if (!isCellInScope(row, col))
			throw std::invalid_argument("Cell is out of scope.\n");

		if (!minesPlaced) {
			revealFirstCell(row, col);
			return true;
		}
		else {
			board[row][col].reveal();
			revealedCells++;
			if (board[row][col].isMine())
				return false;

			cellsToProcess.push_back({ row, col });
			processCells();
			return true;
		}
	}
	catch (const std::logic_error& e) {
		std::println("{}", e.what());
		return true;
	}
}

void Board::flag(int row, int col) {
	try {
		if (!isCellInScope(row, col))
			throw std::invalid_argument("Cell is out of scope.\n");

		if (board[row][col].isRevealed())
			throw std::invalid_argument("Cannot flag revealed cells.\n");

		if (board[row][col].isFlagged())
			throw std::invalid_argument("Cell is already flagged.\n");

		board[row][col].flag();
	}
	catch (const std::invalid_argument& e) {
		std::println("{}", e.what());
	}
}

void Board::unflag(int row, int col) {
	try {
		if (!isCellInScope(row, col))
			throw std::invalid_argument("Cell is out of scope.\n");

		if (!board[row][col].isFlagged())
			throw std::invalid_argument("Cell is not flagged.\n");

		board[row][col].unflag();
	}
	catch (const std::invalid_argument& e) {
		std::println("{}", e.what());
	}
}

bool Board::isBoardRevealed() const {
	if ((static_cast<int>(rows * cols) - totalMines) == revealedCells)
		return true;
	return false;
}

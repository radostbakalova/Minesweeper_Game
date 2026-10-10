#pragma once
#include <stdexcept>
#include <print>

class Cell {
	int surroundingMines = 0;
	bool revealed = false;
	bool mine = false;
	bool flagged = false;

public:
	Cell() = default;
	int getSurroundingMines() const;
	bool isRevealed() const;
	bool isMine() const;
	bool isFlagged() const;

	void setSurroundingMines(int surroundingMines);
	void reveal();
	void setAsMine();
	void flag();
	void unflag();
};


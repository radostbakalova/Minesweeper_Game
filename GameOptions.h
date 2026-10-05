#pragma once
#include "EnumClasses.h"
#include "Constants.h"

class GameOptions {
	int rows;
	int cols;
	Difficulty difficulty;

public:
	GameOptions();
	void setRows(int _rows);
	void setCols(int _cols);
	void setDifficulty(Difficulty _difficulty);
	int getRows() const;
	int getCols() const;
	Difficulty getDifficulty() const;
};


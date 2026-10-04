#pragma once
#include "EnumClasses.h"

class GameOptions {
	int rows;
	int cols;
	Difficulty difficulty;

public:
	explicit GameOptions(int _rows, int _cols, Difficulty _difficulty);
	int getRows() const;
	int getCols() const;
	Difficulty& getDifficulty() const;
};


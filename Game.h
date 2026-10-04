#pragma once
#include "Board.h"
#include "IDifficultyStrategy.h"

class Game {
	Board board;

public:
	explicit Game(int rows, int cols, const IDifficultyStrategy& strategy);
	bool play();
};


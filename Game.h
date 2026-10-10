#pragma once
#include "Board.h"
#include "IDifficultyStrategy.h"
#include <print>
#include <iostream>

class Game {
	Board board;

	bool isActionValid(char action) const;
	bool playTurn();
public:
	explicit Game(int rows, int cols, const IDifficultyStrategy& strategy);
	bool play();
};


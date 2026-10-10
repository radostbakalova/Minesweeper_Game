#include "Game.h"

Game::Game(int rows, int cols, const IDifficultyStrategy& strategy) : board(rows, cols, strategy.getMineCount(rows* cols)) {}

#include "GameOptions.h"

GameOptions::GameOptions() 
    : rows(GameConstants::DEFAULT_ROWS), cols(GameConstants::DEFAULT_COLS), difficulty(Difficulty::Intermediate) {}

void GameOptions::setRows(int _rows) {
    rows = _rows;
}

void GameOptions::setCols(int _cols) {
    cols = _cols;
}

void GameOptions::setDifficulty(Difficulty _difficulty) {
    difficulty = _difficulty;
}

int GameOptions::getRows() const {
    return rows;
}

int GameOptions::getCols() const {
    return cols;
}

Difficulty GameOptions::getDifficulty() const {
    return difficulty;
}

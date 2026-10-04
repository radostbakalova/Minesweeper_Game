#include "GameOptions.h"

GameOptions::GameOptions(int _rows, int _cols, Difficulty _difficulty) : rows(_rows), cols(_cols), difficulty(_difficulty) {}

int GameOptions::getRows() const {
    return rows;
}

int GameOptions::getCols() const {
    return cols;
}

Difficulty& GameOptions::getDifficulty() const {
    return difficulty;
}

#include "Cell.h"

int Cell::getSurroundingMines() const {
    return surroundingMines;
}

bool Cell::isRevealed() const {
    return revealed;
}

bool Cell::isMine() const {
    return mine;
}

bool Cell::isFlagged() const {
    return flagged;
}

void Cell::setSurroundingMines(int surroundingMines) {
    this->surroundingMines = surroundingMines;
}

void Cell::reveal() {
    if (flagged)
        throw std::logic_error("Flagged cells cannot be revealed.\n");
    revealed = true;
}

void Cell::setAsMine() {
    mine = true;
}

void Cell::flag() {
    flagged = true;
}

void Cell::unflag() {
    flagged = false;
}

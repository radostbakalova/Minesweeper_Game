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
    return flag;
}

void Cell::setSurroundingMines(int surroundingMines) {
    this->surroundingMines = surroundingMines;
}

void Cell::reveal() {
    try {
        if (flagged)
            throw std::logic_error("Flagged cells cannot be revealed.\n");
    }
    catch (const std::logic_error& e) {
        std::println("{}", e.what());
        return;
    }
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

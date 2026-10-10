#include "Game.h"

bool Game::isActionValid(char action) const {
    if (action != 'r' && action != 'f' && action != 'n')
        return false;
    return true;
}

bool Game::playTurn() {
    int row, col;
    char action;
    std::println("Enter row, col and action:");
    std::cin >> row >> col >> action;
    if (!isActionValid(action))
        throw std::invalid_argument("Invalid action.\n");
    try {
        switch (action) {
        case 'r': return board.reveal(row, col);
        case 'f': board.flag(row, col);
            return true;
        case 'n': board.unflag(row, col);
            return true;
        default: throw std::invalid_argument("Unknown action.\n");
        }
    }
    catch (const std::logic_error& e) {
        std::println("{}", e.what());
        return true;
    }
}

Game::Game(int rows, int cols, const IDifficultyStrategy& strategy) : board(rows, cols, strategy.getMineCount(rows* cols)) {}

bool Game::play() {
    bool isGameOver = false;
    bool won = false;
    while (!isGameOver) {
        try {
            isGameOver = !playTurn();
        }
        catch (const std::invalid_argument& e) {
            std::println("{}", e.what());
        }
        if (isGameOver && !board.isBoardRevealed()) {
            std::println("Game over, you hit a mine!\n");
        }
        if (board.isBoardRevealed()) {
            std::println("Congratulations, you won!\n");
            won = true;
            isGameOver = true;
        }
    }
    return won;
}

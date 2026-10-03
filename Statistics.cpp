#include "Statistics.h"

int Statistics::getPlayedGames() const {
    return playedGames;
}

int Statistics::getWins() const {
    return wins;
}

void Statistics::increasePlayedGames() {
    playedGames++;
}

void Statistics::increaseWins() {
    wins++;
}

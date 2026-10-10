#include "Statistics.h"

Statistics::Statistics(int _playedGames, int _wins) : playedGames(_playedGames), wins(_wins) {}

Statistics Statistics::loadFromFile(std::istream& is) {
	int playedGames, wins;
	is >> playedGames;
	is >> wins;
	Statistics stats(playedGames, wins);
	return stats;
}

void Statistics::saveToFile(std::ostream& os) {
	os << playedGames;
	os << wins;
}

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

#pragma once
#include <fstream>
#include <ostream>

class Statistics {
	int playedGames = 0;
	int wins = 0;

public:
	Statistics() = default;
	explicit Statistics(int _playedGames, int _wins);
	static Statistics loadFromFile(std::istream& is);
	void saveToFile(std::ostream& os);
	int getPlayedGames() const;
	int getWins() const;
	void increasePlayedGames();
	void increaseWins();
};


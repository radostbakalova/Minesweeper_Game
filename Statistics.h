#pragma once

class Statistics {
	int playedGames = 0;
	int wins = 0;

public:
	Statistics() = default;
	int getPlayedGames() const;
	int getWins() const;
	void increasePlayedGames();
	void increaseWins();
};


#pragma once

class IDifficultyStrategy {
public:
	virtual int getMineCount(int totalCells) const = 0;
	virtual ~IDifficultyStrategy() = default;
};


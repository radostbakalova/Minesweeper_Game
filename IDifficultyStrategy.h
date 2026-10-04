#pragma once

class IDifficultyStrategy {
public:
	virtual int getMineCount() = 0;
	virtual ~IDifficultyStrategy() = default;
};


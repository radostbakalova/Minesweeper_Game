#pragma once
#include "IDifficultyStrategy.h"
#include "Constants.h"

class BeginnerStrategy : public IDifficultyStrategy {
public:
	BeginnerStrategy() = default;
	int getMineCount(int totalMines) const override;
};


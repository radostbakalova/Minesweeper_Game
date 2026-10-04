#pragma once
#include "IDifficultyStrategy.h"
#include "Constants.h"

class ExpertStrategy : public IDifficultyStrategy {
public:
	ExpertStrategy() = default;
	int getMineCount(int totalMines) const override;
};


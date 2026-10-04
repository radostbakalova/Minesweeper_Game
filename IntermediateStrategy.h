#pragma once
#include "IDifficultyStrategy.h"
#include "Constants.h"
class IntermediateStrategy : public IDifficultyStrategy {
public:
	IntermediateStrategy() = default;
	int getMineCount(int totalMines) const override;
};


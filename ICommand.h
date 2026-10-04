#pragma once
#include "CommandResult.h"
class ICommand {
public:
	virtual CommandResult execute() = 0;
	virtual ~ICommand() = default;
};


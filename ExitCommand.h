#pragma once
#include "ICommand.h"

class ExitCommand : public ICommand {
public:
	ExitCommand() = default;
	CommandResult execute() override;
};


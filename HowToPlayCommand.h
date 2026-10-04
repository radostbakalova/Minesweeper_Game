#pragma once
#include "ICommand.h"

class HowToPlayCommand : public ICommand {
public:
	HowToPlayCommand() = default;
	CommandResult execute() override;
};


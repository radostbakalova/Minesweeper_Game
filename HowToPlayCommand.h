#pragma once
#include "ICommand.h"
#include <print>

class HowToPlayCommand : public ICommand {
public:
	HowToPlayCommand() = default;
	CommandResult execute() override;
};


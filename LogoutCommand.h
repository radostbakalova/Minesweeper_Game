#pragma once
#include "ICommand.h"

class LogoutCommand : public ICommand {
public:
	LogoutCommand() = default;
	CommandResult execute() override;
};


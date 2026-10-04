#pragma once
#include "ICommand.h"

class PlayGameCommand : public ICommand {
public:
	PlayGameCommand() = default;
	CommandResult execute() override;
};


#pragma once
#include "ICommand.h"
#include "GameOptions.h"

class ShowGameOptionsCommand : public ICommand {
	GameOptions& options;

public:
	explicit ShowGameOptionsCommand(GameOptions& _options);
	CommandResult execute() override;
};


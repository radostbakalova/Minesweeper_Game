#pragma once
#include "ICommand.h"
#include "Player.h"

class ShowPlayerStatisticsCommand : public ICommand {
	Player* player;

public:
	explicit ShowPlayerStatisticsCommand(Player* _player);
	CommandResult execute() override;
};


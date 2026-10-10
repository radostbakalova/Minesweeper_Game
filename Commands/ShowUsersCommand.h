#pragma once
#include "ICommand.h"
#include "UserManager.h"

class ShowUsersCommand : public ICommand {
	UserManager& manager;
public:
	ShowUsersCommand(UserManager& _manager);
	CommandResult execute() override;
};


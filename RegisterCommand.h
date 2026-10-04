#pragma once
#include "ICommand.h"
#include "UserManager.h"

class RegisterCommand : public ICommand {
	UserManager& manager;
public:
	explicit RegisterCommand(UserManager& _manager);
	CommandResult execute() override;
};


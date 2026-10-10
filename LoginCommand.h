#pragma once
#include "ICommand.h"
#include "UserManager.h"

class LoginCommand : public ICommand {
	UserManager& manager;

public:
	explicit LoginCommand(UserManager& _manager);
	CommandResult execute() override;
};


#pragma once
#include "ICommand.h"
#include "UserManager.h"

class BlockUserCommand : public ICommand {
	UserManager& manager;
public:
	explicit BlockUserCommand(UserManager& _manager);
	CommandResult execute() override;
};


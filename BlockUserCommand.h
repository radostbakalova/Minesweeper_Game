#pragma once
#include "ICommand.h"
#include "UserManager.h"
#include <string>
#include <print>
#include <iostream>

class BlockUserCommand : public ICommand {
	UserManager& manager;

public:
	explicit BlockUserCommand(UserManager& _manager);
	CommandResult execute() override;
};


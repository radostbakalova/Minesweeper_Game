#pragma once
#include "UserManager.h"
#include "ICommand.h"
#include "Session.h"
#include <memory>
#include <optional>

class CommandFactory {
	UserManager& manager;

public:
	explicit CommandFactory(UserManager& _manager);
	std::unique_ptr<ICommand> create(int choice, std::optional<Session*> currentSession);
};


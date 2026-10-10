#pragma once
#include "UserManager.h"
#include "ICommand.h"
#include "LoginCommand.h"
#include "RegisterCommand.h"
#include "ShowUsersCommand.h"
#include "BlockUserCommand.h"
#include "LogoutCommand.h"
#include "PlayGameCommand.h"
#include "ShowGameOptionsCommand.h"
#include "ShowPlayerStatisticsCommand.h"
#include "HowToPlayCommand.h"
#include "ExitCommand.h"
#include "Session.h"
#include <memory>
#include <optional>

class CommandFactory {
	UserManager& manager;

public:
	explicit CommandFactory(UserManager& _manager);
	std::unique_ptr<ICommand> create(int choice, std::optional<Session*> currentSession);
};


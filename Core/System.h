#pragma once
#include "UserManager.h"
#include "IScreen.h"
#include "AuthScreen.h"
#include "AdminScreen.h"
#include "PlayerScreen.h"
#include "Session.h"
#include "CommandFactory.h"
#include "EnumClasses.h"
#include <memory>
#include <print>
#include <string>
#include <fstream>
#include <ostream>

class System {
	UserManager& manager;
	std::unique_ptr<IScreen> currentScreen;
	std::unique_ptr<Session> currentSession;
	CommandFactory factory;

	void loadFromFile(const std::string& fileName);
	void saveToFile(const std::string& fileName);

public:
	explicit System(UserManager& _manager);
	void run();
};


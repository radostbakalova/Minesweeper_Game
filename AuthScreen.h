#pragma once
#include "IScreen.h"
#include "ICommand.h"
#include "CommandFactory.h"
#include "Constants.h"
#include <map>
#include <memory>
#include <print>
#include <iostream>

class AuthScreen : public IScreen {
	std::map<int, std::unique_ptr<ICommand>> commands;

public:
	explicit AuthScreen(CommandFactory& factory);
	void display() const override;
	ScreenResult handleInput() override;
};


#pragma once
#include "ICommand.h"
#include "Session.h"

class PlayGameCommand : public ICommand {
	Session* currentSession;

public:
	explicit PlayGameCommand(Session* _currentSession);
	CommandResult execute() override;
};


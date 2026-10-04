#pragma once
#include "User.h"
#include "GameOptions.h"

class Session {
	User* currentUser;
	GameOptions& options;

public:
	explicit Session(User* user, GameOptions& _options);
	User* getCurrentUser() const;
	GameOptions& getGameOptions() const;
};


#pragma once
#include "User.h"
#include "GameOptions.h"
#include <optional>

class Session {
	User* currentUser;
	std::optional<GameOptions*> options;

public:
	explicit Session(User* user, std::optional<GameOptions*> _options);
	User* getCurrentUser() const;
	GameOptions* getGameOptions() const;
};


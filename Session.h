#pragma once
#include "User.h"
#include "GameOptions.h"

class Session {
	User* user;
	GameOptions& options;

public:
	explicit Session(User* _user, GameOptions& _options);
};


#pragma once
#include "User.h"
#include <optional>

class IScreen;

struct ScreenResult {
	IScreen* screen;
	std::optional<User*> user;

	explicit ScreenResult(IScreen* _screen, std::optional<User*> _user);
};
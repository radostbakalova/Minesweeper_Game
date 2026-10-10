#pragma once
#include "EnumClasses.h"
#include "User.h"
#include <optional>

class IScreen;

struct ScreenResult {
	TransitionResult transition;
	std::optional<User*> user;

	explicit ScreenResult(TransitionResult _transition, std::optional<User*> _user);
};

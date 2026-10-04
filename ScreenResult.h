#pragma once
#include "EnumClasses.h"
#include "User.h"
#include <optional>

class IScreen;

struct ScreenResult {
	TransitionResult result;
	std::optional<User*> user;

	explicit ScreenResult(TransitionResult _result, std::optional<User*> _user);
};
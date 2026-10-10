#pragma once
#include "EnumClasses.h"
#include "User.h"
#include <optional>

struct CommandResult {
	ExecutionResult status;
	std::optional<User*> user;

	explicit CommandResult(ExecutionResult _status, std::optional<User*> _user);
};

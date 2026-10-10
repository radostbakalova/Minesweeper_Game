#include "CommandResult.h"

CommandResult::CommandResult(ExecutionResult _status, std::optional<User*> _user) 
	: status(_status), user(_user) {}

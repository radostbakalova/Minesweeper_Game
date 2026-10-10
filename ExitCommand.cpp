#include "ExitCommand.h"

CommandResult ExitCommand::execute() {
    return CommandResult(ExecutionResult::Success, std::nullopt);
}

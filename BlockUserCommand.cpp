#include "BlockUserCommand.h"

BlockUserCommand::BlockUserCommand(UserManager& _manager) : manager(_manager) {}

CommandResult BlockUserCommand::execute() {
    std::string username;
    std::println("Please enter username of the player you want to block:");
    std::cin >> username;
    try {
        manager.removePlayer(username);
        std::println("User was successfully blocked.\n");
        return CommandResult(ExecutionResult::Success, std::nullopt);
    }
    catch (const std::invalid_argument& e) {
        std::println("{}", e.what());
        return CommandResult(ExecutionResult::Failure, std::nullopt);
    }
}

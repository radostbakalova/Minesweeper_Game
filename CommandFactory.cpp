#include "CommandFactory.h"

CommandFactory::CommandFactory(UserManager& _manager) : manager(_manager) {}

std::unique_ptr<ICommand> CommandFactory::create(int choice, std::optional<Session*> currentSession) {
    switch (choice) {
    case 1: return std::make_unique<LoginCommand>(manager);
        break;
    case 2: return std::make_unique<RegisterCommand>(manager);
        break;
    case 3: return std::make_unique<ShowUsersCommand>(manager);
        break;
    case 4: return std::make_unique<BlockUserCommand>(manager);
        break;
    case 5: return std::make_unique<LogoutCommand>();
        break;
    case 6: return std::make_unique<PlayGameCommand>(currentSession);
        break;
    case 7: return std::make_unique<ShowGameOptionsCommand>((*currentSession)->getGameOptions());
        break;
    case 8: return std::make_unique<ShowUsersCommand>(manager);
        break;
    case 9: return std::make_unique<HowToPlayCommand>();
        break;
    case 10: return std::make_unique<ExitCommand>();
        break;
    default: throw std::invalid_argument("Unknown command choice.\n");
    }
}

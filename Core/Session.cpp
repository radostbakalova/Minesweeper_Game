#include "Session.h"

Session::Session(User* user, std::optional<GameOptions*> _options) : currentUser(user), options(_options) {}

User* Session::getCurrentUser() const {
    return currentUser;
}

GameOptions* Session::getGameOptions() const {
    return *options;
}

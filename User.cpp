#include "User.h"

User::User(std::string _userId, std::string _username, std::string _password) noexcept
	: userId(std::move(_userId)), username(std::move(_username)), password(std::move(_password)) {}

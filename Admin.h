#pragma once
#include "User.h"
#include <string>

class Admin : public User {
public:
	explicit Admin(std::string userId, std::string username, std::string password);
};


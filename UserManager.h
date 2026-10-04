#pragma once
#include "User.h"
#include <vector>
#include <memory>

class UserManager {
	std::vector<std::unique_ptr<User>> users;

public:
	UserManager() = default;
	void loadFromFile(std::string& fileName);
	void saveToFile(std::string& fileName);
};


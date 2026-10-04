#pragma once
#include "User.h"
#include <vector>
#include <memory>

class UserManager {
	std::vector<std::unique_ptr<User>> users;

public:
	UserManager() = default;
	void loadFromFile(const std::string& fileName);
	void saveToFile(const std::string& fileName);
};


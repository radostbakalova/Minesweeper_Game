#pragma once
#include "User.h"
#include "Admin.h"
#include "Player.h"
#include <vector>
#include <memory>
#include <fstream>
#include <ostream>

class UserManager {
	std::vector<std::unique_ptr<User>> users;

public:
	UserManager() = default;
	void loadFromFile(std::istream& is);
	void saveToFile(std::ostream& os);
};


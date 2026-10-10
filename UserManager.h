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
	int userIds = 1;

public:
	UserManager() = default;
	void loadFromFile(std::istream& is);
	void saveToFile(std::ostream& os);
	User* searchByUsername(const std::string& username);
	void removePlayer(const std::string& username);
	User* loginUser(const std::string& username, const std::string& password);
	User* registerUser(const std::string& username, const std::string& password);
};


#pragma once
#include "User.h"
#include <string>
#include <fstream>
#include <ostream>

class Admin : public User {
public:
	explicit Admin(std::string userId, std::string username, std::string password);
	static Admin loadFromFile(std::istream& is);
	void saveToFile(std::ostream& os) override;
	const std::string& getUsername() const override;
	const std::string& getPassword() const override;
	bool isAdmin() const override;
};


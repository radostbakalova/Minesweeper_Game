#pragma once
#include <string>

class User {
protected:
	std::string userId;
	std::string username;
	std::string password;

public:
	explicit User(std::string _userId, std::string _username, std::string _password) noexcept;
	virtual ~User() = default;
	virtual void loadFromFile(const std::string& fileName) = 0;
	virtual void saveToFile(const std::string& fileName) = 0;
	virtual const std::string& getUsername() const = 0;
	virtual const std::string& getPassword() const = 0;
};


#pragma once
#include <string>
#include <ostream>

class User {
protected:
	std::string userId;
	std::string username;
	std::string password;

public:
	explicit User(std::string _userId, std::string _username, std::string _password) noexcept;
	virtual void saveToFile(std::ostream& os) = 0;
	virtual const std::string& getUsername() const = 0;
	virtual const std::string& getPassword() const = 0;
	virtual bool isAdmin() const = 0;
	virtual ~User() = default;
};


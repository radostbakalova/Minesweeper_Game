#include "Admin.h"

Admin::Admin(std::string userId, std::string username, std::string password) 
	: User(std::move(userId), std::move(username), std::move(password)) {}

bool Admin::isAdmin() const {
	return true;
}

#include "Admin.h"

Admin::Admin(std::string userId, std::string username, std::string password) 
	: User(std::move(userId), std::move(username), std::move(password)) {}

Admin Admin::loadFromFile(std::istream& is) {
	std::string userId, username, password;
	is >> userId;
	is >> username;
	is >> password;
	Admin admin(userId, username, password);
	return admin;
}

bool Admin::isAdmin() const {
	return true;
}

#include "UserManager.h"

void UserManager::loadFromFile(std::istream& is) {
	int userSize;
	is >> userSize;
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (userSize == 0) {
		users.push_back(std::make_unique<Admin>("1", "admin", "adminPass26!"));
		userIds++;
		return;
	}
	else {
		users.push_back(std::make_unique<Admin>(Admin::loadFromFile(is)));
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (size_t i = 0; i < userSize - 1; i++) {
			users.push_back(std::make_unique<Player>(Player::loadFromFile(is)));
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void UserManager::saveToFile(std::ostream& os) {
	int userSize = users.size();
	os << userSize;
	os << '\n';
	for (const std::unique_ptr<User>& user : users) {
		user->saveToFile(os);
		os << '\n';
	}
}

User* UserManager::searchByUsername(const std::string& username) {
	for (const auto& user : users) {
		if (username == user->getUsername())
			return user.get();
	}
	return nullptr;
}

void UserManager::removePlayer(const std::string& username) {
	auto it = std::find_if(users.begin(), users.end(),
		[&](const std::unique_ptr<User>& user) { return user->getUsername() == username; });
	if (it == users.end())
		throw std::invalid_argument("User not found.\n");
	if ((*it)->isAdmin())
		throw std::invalid_argument("Admin cannot be deleted.\n");
	users.erase(it);
}

User* UserManager::loginUser(const std::string& username, const std::string& password) {
	for (const auto& user : users) {
		if (username == user->getUsername() && password == user->getPassword())
			return user.get();
	}
	throw std::invalid_argument("Wrong username or password. Please try again.\n");
}

User* UserManager::registerUser(const std::string& username, const std::string& password) {
	if (!searchByUsername(username)) {
		users.push_back(std::make_unique<Player>(userIds, username, password));
		userIds++;
		return users.back().get();
	}
	else
		throw std::invalid_argument("User with such username already exists.\n");
}

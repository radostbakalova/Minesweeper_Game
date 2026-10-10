#include "UserManager.h"

void UserManager::loadFromFile(std::istream& is) {
	int userSize;
	is >> userSize;
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (userSize == 0) {
		users.push_back(std::make_unique<Admin>("1", "admin", "adminPass26!"));
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

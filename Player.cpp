#include "Player.h"

Player::Player(std::string userId, std::string username, std::string password, Statistics _stats) noexcept
	: User(std::move(userId),std::move(username),std::move(password)), stats(_stats) {}

Player Player::loadFromFile(std::istream& is) {
	std::string userId, username, password;
	is >> userId;
	is >> username;
	is >> password;
	Player player(userId, username, password, Statistics::loadFromFile(is));
	return player;
}

const std::string& Player::getUsername() const {
	return username;
}

const std::string& Player::getPassword() const {
	return password;
}

bool Player::isAdmin() const {
	return false;
}

void Player::recordGame(bool won) {
	stats.increasePlayedGames();
	if (won)
		stats.increaseWins();
}

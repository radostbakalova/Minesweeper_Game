#include "Player.h"

Player::Player(std::string userId, std::string username, std::string password) noexcept 
	: User(std::move(userId),std::move(username),std::move(password)), stats() {}

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

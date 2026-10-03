#pragma once
#include "User.h"
#include "Statistics.h"
#include <string>

class Player: public User {
	Statistics stats;

public:
	explicit Player(std::string userId, std::string username, std::string password) noexcept;
	const std::string& getUsername() const override;
	const std::string& getPassword() const override;
	void recordGame(bool won);
};


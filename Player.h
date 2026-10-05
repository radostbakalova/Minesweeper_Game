#pragma once
#include "User.h"
#include "Statistics.h"
#include <string>
#include <fstream>
#include <ostream>

class Player : public User {
	Statistics stats;

public:
	explicit Player(std::string userId, std::string username, std::string password, Statistics _stats) noexcept;
	static Player loadFromFile(std::istream& is);
	void saveToFile(std::ostream& os) override;
	const std::string& getUsername() const override;
	const std::string& getPassword() const override;
	bool isAdmin() const override;
	void recordGame(bool won);
};


#include "System.h"

void System::loadFromFile(const std::string& fileName) {
	std::ifstream is = std::ifstream(fileName);
	if (!is.is_open())
		throw std::runtime_error("Failed to open file.\n");
	if (!is.good())
		throw std::runtime_error("Failed to load data.\n");

	manager.loadFromFile(is);
	is.close();
}

void System::saveToFile(const std::string& fileName) {
	std::ofstream os = std::ofstream(fileName);
	if (!os.is_open())
		throw std::runtime_error("Failed to open file.\n");
	if (!os.good())
		throw std::runtime_error("Failed to save data.\n");

	manager.saveToFile(os);
	os.close();
}

System::System(UserManager& _manager) : manager(_manager), currentScreen(std::make_unique<AuthScreen>(factory)), factory(_manager) {}

void System::run() {
	std::println(" --- WELCOME TO MINESWEEPER ---\n");
	try {
		loadFromFile("data.txt");
	}
	catch (const std::runtime_error& e) {
		std::println("{}", e.what());
		return;
	}
	bool running = true;
	while (running) {
		currentScreen->display();
		auto result = currentScreen->handleInput();
		if (result.transition == TransitionResult::Stay)
			continue;
		if (result.transition == TransitionResult::GoToAuthScreen) {
			currentScreen = std::make_unique<AuthScreen>(factory);
			currentSession = nullptr;
			continue;
		}
		if (result.transition == TransitionResult::GoToAdminScreen && result.user) {
			currentScreen = std::make_unique<AdminScreen>(factory);
			currentSession = std::make_unique<Session>(result.user, std::nullopt);
			continue;
		}
		if (result.transition == TransitionResult::GoToPlayerScreen && result.user) {
			currentScreen = std::make_unique<PlayerScreen>(factory);
			currentSession = std::make_unique<Session>(result.user, GameOptions());
			continue;
		}
		if (result.transition == TransitionResult::Exit) {
			running = false;
			continue;
		}
		std::println("Something went wrong. Please try again.");
	}
	try {
		saveToFile("data.txt");
	}
	catch (const std::runtime_error& e) {
		std::println("{}", e.what());
		return;
	}
}

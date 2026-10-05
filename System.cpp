#include "System.h"

System::System(UserManager& _manager) : manager(_manager), currentScreen(std::make_unique<AuthScreen>(factory)), factory(_manager) {}

void System::run() {
	std::println(" --- WELCOME TO MINESWEEPER ---\n");
	//loadFromFile();
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
	//saveToFile();
}

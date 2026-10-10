#include "AuthScreen.h"

AuthScreen::AuthScreen(CommandFactory& factory) {
	commands[1] = factory.create(1, std::nullopt);
	commands[2] = factory.create(2, std::nullopt);
	commands[3] = factory.create(10, std::nullopt);
}

void AuthScreen::display() const {
	std::println(" 1 ) login");
	std::println(" 2 ) register");
	std::println(" 3 ) exit");
	std::println();
}

ScreenResult AuthScreen::handleInput() {
	int choice;
	std::cin >> choice;
	try {
		CommandResult result = commands.at(choice)->execute();
		if (choice == 1 && result.status == ExecutionResult::Success && result.user != std::nullopt) {

			std::println("Successful login!");
			if ((*result.user)->isAdmin())
				return ScreenResult(TransitionResult::GoToAdminScreen, *result.user);
			else
				return ScreenResult(TransitionResult::GoToPlayerScreen, *result.user);
		}
		if (choice == 2 && result.status == ExecutionResult::Success && result.user != std::nullopt) {

			std::println("Successful registration!");
			return ScreenResult(TransitionResult::GoToPlayerScreen, *result.user);
		}
		if (choice == 1 && result.status == ExecutionResult::Failure) {

			std::println("Failed to login!");
			return ScreenResult(TransitionResult::Stay, std::nullopt);
		}
		if (choice == 2 && result.status == ExecutionResult::Failure) {

			std::println("Failed to register!");
			return ScreenResult(TransitionResult::Stay, std::nullopt);
		}
		if (result.status == ExecutionResult::Cancelled)
			return ScreenResult(TransitionResult::Stay, std::nullopt);

		if (choice == 3 && result.status == ExecutionResult::Success)
			return ScreenResult(TransitionResult::Exit, std::nullopt);
		
		std::println("Something went wrong. Please try again.");
		return ScreenResult(TransitionResult::Stay, std::nullopt);
	}
	catch (const std::out_of_range& e) {
		std::println("No valid command! Please try again.");
		return ScreenResult(TransitionResult::Stay, std::nullopt);
	}
}

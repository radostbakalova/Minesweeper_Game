#include "PlayerScreen.h"

PlayerScreen::PlayerScreen(CommandFactory& factory) {
	commands[1] = factory.create(6, std::nullopt);
	commands[2] = factory.create(7, std::nullopt);
	commands[3] = factory.create(8, std::nullopt);
	commands[4] = factory.create(9, std::nullopt);
	commands[5] = factory.create(5, std::nullopt);
	commands[6] = factory.create(10, std::nullopt);
}

void PlayerScreen::display() const {
	std::println(" 1 ) play game");
	std::println(" 2 ) show game options");
	std::println(" 3 ) show player's statistics");
	std::println(" 4 ) how to play");
	std::println(" 5 ) logout");
	std::println(" 6 ) exit");
	std::println();
}

ScreenResult PlayerScreen::handleInput() {
	int choice;
	std::cin >> choice;
	try {
		CommandResult result = commands.at(choice)->execute();
		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
			return ScreenResult(TransitionResult::Stay, std::nullopt);

		if (choice == 5 && result.status == ExecutionResult::Success)
			return ScreenResult(TransitionResult::GoToAuthScreen, std::nullopt);

		if (choice == 6 && result.status == ExecutionResult::Success)
			return ScreenResult(TransitionResult::Exit, std::nullopt);

		std::println("Something went wrong. Please try again.");
		return ScreenResult(TransitionResult::Stay, std::nullopt);
	}
	catch (const std::out_of_range& e) {
		std::println("No valid command! Please try again.");
		return ScreenResult(TransitionResult::Stay, std::nullopt);
	}
}

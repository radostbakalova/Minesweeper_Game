#include "AdminScreen.h"

AdminScreen::AdminScreen(CommandFactory& factory) {
	try {
		commands[1] = factory.create(3, std::nullopt);
		commands[2] = factory.create(4, std::nullopt);
		commands[3] = factory.create(5, std::nullopt);
		commands[4] = factory.create(10, std::nullopt);
	}
	catch (const std::invalid_argument& e) {
		std::println("{}", e.what());
	}
}

void AdminScreen::display() const {
	std::println(" 1 ) show all users");
	std::println(" 2 ) block user");
	std::println(" 3 ) logout");
	std::println(" 4 ) exit");
	std::println();
}

ScreenResult AdminScreen::handleInput() {
	int choice;
	std::cin >> choice;
	try {
		CommandResult result = commands.at(choice)->execute();
		if ((choice == 1 || choice == 2) && result.status==ExecutionResult::Success)
			return ScreenResult(TransitionResult::Stay, std::nullopt);

		if (choice == 3 && result.status == ExecutionResult::Success)
			return ScreenResult(TransitionResult::GoToAuthScreen, std::nullopt);

		if (choice == 4 && result.status == ExecutionResult::Success)
			return ScreenResult(TransitionResult::Exit, std::nullopt);

		std::println("Something went wrong. Please try again.");
		return ScreenResult(TransitionResult::Stay, std::nullopt);
	}
	catch (const std::out_of_range& e) {
		std::println("No valid command! Please try again.");
		return ScreenResult(TransitionResult::Stay, std::nullopt);
	}
}

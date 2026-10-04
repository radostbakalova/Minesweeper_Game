#pragma once

enum class ExecutionResult {
	LoginSuccess,
	RegistrationSuccess,
	LoginFailure,
	RegistrationFailure,
	Cancelled
};

enum class TransitionResult {
	Stay,
	GoToAuthScreen,
	GoToAdminScreen,
	GoToPlayerScreen,
	Exit
};

enum class Difficulty {
	Beginner,
	Intermediate,
	Expert
};
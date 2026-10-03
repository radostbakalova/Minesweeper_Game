#pragma once

enum class ExecutionResult {
	Success,
	Failure,
	Cancelled
};

enum class TransitionResult {
	Stay,
	GoToAuthScreen,
	GoToMainMenuScreen,
	Exit
};

enum class Difficulty {
	Beginner,
	Intermediate,
	Expert
};
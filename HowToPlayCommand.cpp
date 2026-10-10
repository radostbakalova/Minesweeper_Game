#include "HowToPlayCommand.h"

CommandResult HowToPlayCommand::execute() {
    std::println("======== HOW TO PLAY ========");
    std::println("GOAL\n Reveal every cell that does not contain a mine.If you reveal a mine, you lose.\n");
    std::println("THE BOARD\n" 
        "Each revealed cell shows a number : how many mines are in the 8 cells around it.\n"
        "A blank revealed cell has no mines nearby, and its empty neighbours open automatically.\n"
        "F marks a cell you have flagged as a suspected mine.\n");
    std::println("YOUR TURN\n"
        "Each turn, enter an action followed by a row and a column :\n"
        "<row> <col> r   reveal a cell\n"
        "<row> <col> f   flag a cell\n"
        "<row> <col> n   remove a flag\n"
        "Example : 3 5 r  reveals the cell in row 3, column 5.\n");
    std::println("RULES\n"
        "- Your first reveal is always safe, and the cells around it are mine - free too.\n"
        "- A flagged cell cannot be revealed. Remove the flag first.\n"
        "- An invalid move, such as a cell outside the board, costs you nothing. You just try again.\n");
    std::println("GAME OPTIONS"
        "Before playing you can change the board size(3 to 30 for rows and columns) and the difficulty:\n"
        "Beginner       about 10 % of the cells are mines\n"
        "Intermediate   about 20 % of the cells are mines\n"
        "Expert         about 30 % of the cells are mines\n"
        "Your wins and played games are tracked in the user's statistics.\n");
    std::println("Good luck!");
    std::println("=============================");
    return CommandResult(ExecutionResult::Success, std::nullopt);
}

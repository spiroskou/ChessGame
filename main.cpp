#include <iostream>
#include <string>
#include <sstream>
#include "Board.h"
#include "Pawn.h"

int main()
{
	// Get global board and initialize turn counter
	std::shared_ptr<Board> board = getBoard();
	int turn_counter = 1;
	board->print();

	// Game Loop!
	while (true) {
		std::string input;
		int src_row = -1, src_col = -1, dest_row = -1, dest_col = -1;

		// Player Turn starts here
		std::cout << (turn_counter % 2 != 0 ? "Player1 (Green) " : "Player2 (Red) ") << "turn" << std::endl;
		std::cout << "Enter 'q' to quit or four integers: src_row src_col dest_row dest_col: ";

		// Get input from players
		std::getline(std::cin, input);
		std::istringstream iss(input);
		iss >> src_row >> src_col >> dest_row >> dest_col;

		// Check if the input is 'q'
		if (input == "q" || input == "Q") {
			break; // Exit the loop
		}

		// Make the pawn move
		bool res = board->move(src_row, src_col, dest_row, dest_col);

		// Check if the move was valid and proceed to the next round
		if (res == true) {
			board->print();
			std::cout << std::endl;
		} else {
			std::cout << "Invalid Move. Try again" << std::endl;
			continue;
		}

		if (board->isCheckmate(turn_counter)) {
			std::cout << "Checkmate! Game has ended!" << std::endl;
			break;
		}

		turn_counter++;
	}

	return 0;
}

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
		int srcRow = -1, srcCol = -1, destRow = -1, destCol = -1;

		// Get input from player
		std::cout << (turn_counter % 2 != 0 ? "Player1 (Green) " : "Player2 (Red) ") << "turn" << std::endl;
		std::cout << "Enter 'q' to quit or four integers: srcRow srcCol destRow destCol: ";
		std::getline(std::cin, input);
		std::istringstream iss(input);
		iss >> srcRow >> srcCol >> destRow >> destCol;

		// Check if the input is 'q'
		if (input == "q" || input == "Q") {
			break; // Exit the loop
		}

		// Make the pawn move
		bool res = board->move(srcRow, srcCol, destRow, destCol);

		// Check if the move was valid and proceed to the next round
		if (res == true) {
			board->print();
			std::cout << std::endl;
		} else {
			std::cout << "Invalid Move. Try again" << std::endl;
			continue;
		}

		turn_counter++;
	}

	return 0;
}

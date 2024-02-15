#include <iostream>
#include <string>
#include <sstream>
#include "Board.h"
#include "Pawn.h"

int main()
{
	std::shared_ptr<Board> board = getBoard();

	board->print();

	int turn_counter = 1;
	while (true) {
		std::string input;
		int srcRow = -1, srcCol = -1, destRow = -1, destCol = -1;

		std::cout << (turn_counter % 2 != 0 ? "Player1 (Green) " : "Player2 (Red) ") << "turn" << std::endl;
		std::cout << "Enter 'q' to quit or four integers: srcRow srcCol destRow destCol: ";
		std::getline(std::cin, input);

		// Check if the input is 'q'
		if (input == "q" || input == "Q") {
			break; // Exit the loop
		}

		std::istringstream iss(input);
		iss >> srcRow >> srcCol >> destRow >> destCol;
		bool res = board->move(srcRow, srcCol, destRow, destCol);

		if (res == true) {
			turn_counter++;
			board->print();
			std::cout << std::endl;
		}
		else {
			std::cout << "Invalid Move. Try again" << std::endl;
		}
	}

	//board->move(1, 1, 3, 1); // move pawn 2 squares ahead

	return 0;
}

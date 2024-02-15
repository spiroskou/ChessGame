#include <iostream>
#include "Board.h"
#include "Pawn.h"

int main()
{
	std::shared_ptr<Board> board = getBoard();

	board->print();

	board->move(1, 1, 3, 1); // move leftmost pawn 2 squares ahead
	std::cout << std::endl;

	board->print();

	return 0;
}

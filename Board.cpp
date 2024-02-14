#include <iostream>
#include "Board.h"
#include "Piece.h"

void Board::print()
{
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			m_layout[row][col].print();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

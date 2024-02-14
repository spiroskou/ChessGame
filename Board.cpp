#include <iostream>
#include "Board.h"
#include "Piece.h"

Board::Board()
{
	m_layout[0] = { PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen, PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook };
	m_layout[1] = { PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn };
	m_layout[2] = { PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty };
	m_layout[3] = { PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty };
	m_layout[4] = { PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty };
	m_layout[5] = { PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty, PieceType::Empty };
	m_layout[6] = { PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn, PieceType::Pawn };
	m_layout[7] = { PieceType::Rook, PieceType::Knight, PieceType::Bishop, PieceType::Queen, PieceType::King, PieceType::Bishop, PieceType::Knight, PieceType::Rook };
}

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

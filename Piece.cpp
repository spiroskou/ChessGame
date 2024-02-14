#include <iostream>
#include "Piece.h"

void Piece::print()
{
	char symbol = 0;

	switch (m_type)
	{
	case PieceType::Empty:
		symbol = '.';
		break;
	case PieceType::Pawn:
		symbol = 'P';
		break;
	case PieceType::Knight:
		symbol = 'N';
		break;
	case PieceType::Bishop:
		symbol = 'B';
		break;
	case PieceType::Rook:
		symbol = 'R';
		break;
	case PieceType::Queen:
		symbol = 'Q';
		break;
	case PieceType::King:
		symbol = 'K';
		break;
	default:
		break;
	}

	std::cout << symbol;
}

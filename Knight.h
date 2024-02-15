#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(PieceColor col) : Piece(col, PieceType::Knight)
	{
	};
};


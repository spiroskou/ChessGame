#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(PieceColor col) : Piece(col, PieceType::King) {};
};


#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(PieceColor col) : Piece(col, PieceType::Knight)
	{
	};

    bool isValidMove(int org_row, int org_col, int trg_row, int trg_col) const override;
};


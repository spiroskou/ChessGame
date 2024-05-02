#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(PieceColor col) : Piece(col, PieceType::King) {};

    bool isValidMove(int org_row, int org_col, int trg_row, int trg_col) const override;
};


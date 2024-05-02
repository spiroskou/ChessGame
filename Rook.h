#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    Rook(PieceColor col) : Piece(col, PieceType::Rook) {};

    bool isValidMove(int org_row, int org_col, int trg_row, int trg_col) const override;
    bool isPathClear(int org_row, int org_col, int trg_row, int trg_col) const;
};


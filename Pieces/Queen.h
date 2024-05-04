#pragma once
#include "Piece.h"
class Queen :
    public Piece
{
public:
    Queen(PieceColor col) : Piece(col, PieceType::Queen) {};
    bool isValidMove(int org_row, int org_col, int trg_row, int trg_col) const override;
    bool isPathClear(int org_row, int org_col, int trg_row, int trg_col) const;
};


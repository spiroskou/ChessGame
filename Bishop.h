#pragma once
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(PieceColor col) : Piece(col, PieceType::Bishop) {};
    bool isValidMove(int org_row, int org_col, int trg_row, int trg_col) const override;
    bool isPathClear(int org_row, int org_col, int trg_row, int trg_col) const;
};


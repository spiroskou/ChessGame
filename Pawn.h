#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
    char isFirstMove{ 1 };
public:
    Pawn(PieceColor col) : Piece(col, PieceType::Pawn)
    {
    };

    bool isValidMove(int src_row, int src_col, int trg_row, int trg_col) const override;

    void setFirstMove(char move) { isFirstMove = move; };
    const int getFirstMove() const{ return isFirstMove; };
    std::string getImagePath() const override;
};


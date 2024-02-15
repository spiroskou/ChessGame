#pragma once
#include "Piece.h"
class Rook :
    public Piece
{
public:
    Rook(PieceColor col) : Piece(col, PieceType::Rook) {};
};


#pragma once
#include "Piece.h"
class Queen :
    public Piece
{
public:
    Queen(PieceColor col) : Piece(col, PieceType::Queen) {};
};


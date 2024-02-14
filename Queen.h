#pragma once
#include "Piece.h"
class Queen :
    public Piece
{
public:
    Queen() : Piece(PieceType::Queen) {};
};


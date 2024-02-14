#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
public:
    Pawn() : Piece(PieceType::Pawn)
    {
    };
};


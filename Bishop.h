#pragma once
#include "Piece.h"
class Bishop :
    public Piece
{
public:
    Bishop(PieceColor col) : Piece(col, PieceType::Bishop) {};
};


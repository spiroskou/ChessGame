#pragma once

#include <array>
#include "Block.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board
{
private:
	std::array<std::array<Block, 8>, 8> m_layout;
public:
    Board() : m_layout{{
        {Block(Rook()), Block(Knight()), Block(Bishop()), Block(Queen()), Block(King()), Block(Bishop()), Block(Knight()), Block(Rook())},
        {Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn())},
        {Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece())},
        {Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece())},
        {Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece())},
        {Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece()), Block(Piece())},
        {Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn()), Block(Pawn())},
        {Block(Rook()), Block(Knight()), Block(Bishop()), Block(Queen()), Block(King()), Block(Bishop()), Block(Knight()), Block(Rook())}
    } } {};
	void print();
};


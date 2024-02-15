#pragma once

#include "Piece.h"

constexpr auto MAX_NUM_BLOCKS = 64;

class Block
{
private:
	Piece *m_piece;

public:

	Block(Piece *piece = nullptr)
		: m_piece{ piece }
	{
	};

	Piece *getPiece() const { return m_piece; };
	void setPiece(Piece* piece) { m_piece = piece; };

	void print();
	bool isEmpty() const { return getPiece()->getType() == PieceType::Empty ? 1 : 0; };
};


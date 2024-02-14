#pragma once

#include "Piece.h"

constexpr auto MAX_NUM_BLOCKS = 64;

class Block
{
private:
	Piece m_piece;

public:

	Block(Piece piece = PieceType::Empty)
		: m_piece{ piece }
	{
	};

	const Piece& getPiece() { return m_piece; };
	void setPiece(const Piece& piece) { m_piece = piece; };

	void print();
	void blockMove(Block& org, Block& trg);
};


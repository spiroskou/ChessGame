#pragma once

#include <iostream>
#include "Piece.h"

constexpr auto MAX_NUM_BLOCKS = 64;

class Block
{
private:
	std::shared_ptr<Piece> m_piece;

public:

	Block(std::shared_ptr<Piece> piece = nullptr)
		: m_piece{ piece }
	{
	};

	std::shared_ptr<Piece> getPiece() const { return m_piece; };
	void setPiece(std::shared_ptr<Piece> piece) { m_piece = piece; };

	void print();
	bool isEmpty() const { return getPiece()->getType() == PieceType::Empty ? 1 : 0; };
};


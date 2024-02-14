#pragma once

enum class PieceType {Empty, Pawn, Knight, Bishop, Rook, Queen, King};

class Piece
{
public:
	Piece(PieceType type = PieceType::Empty)
		: m_type{ type }
	{
	};
	void print();

private:
	PieceType m_type;
};

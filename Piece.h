#pragma once

#include <array>

enum class PieceType {Empty, Pawn, Knight, Bishop, Rook, Queen, King};
enum class PieceColor {Blank, White, Black};

class Block;

class Piece
{
public:
	Piece(PieceColor col = PieceColor::Blank, PieceType type = PieceType::Empty)
		: m_type{ type }, m_color {col}
	{
	};

	const PieceColor& getColor() const { return m_color; };
	const PieceType& getType() const { return m_type; };
	void print() const;
	virtual bool isValidMove(int org_row, int org_col, int trg_row, int trg_col) const { return false; };

private:
	PieceType m_type;
	PieceColor m_color;
};

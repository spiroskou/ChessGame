#pragma once

#include <array>
#include <string>

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
	virtual bool isValidMove(int src_row, int src_col, int trg_row, int trg_col) const { return false; };
	bool isEmpty() const { return getType() == PieceType::Empty ? 1 : 0; };
	virtual std::string getImagePath() const { return ""; };

private:
	PieceType m_type;
	PieceColor m_color;
};

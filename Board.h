#pragma once

#include <array>
#include "Piece.h"

class Board
{
private:
	std::array<std::array<Piece, 8>, 8> m_layout;
public:
	Board();
	void print();
};


#include <iostream>
#include "Board.h"
#include "Piece.h"

std::shared_ptr<Board> board = std::make_shared<Board>();

std::shared_ptr<Board> getBoard()
{
	return board;
}

bool Board::isValidPosition(int row, int col)
{
	return row >= 0 && row < 8 && col >= 0 && col < 8;
}

void Board::print()
{
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			m_layout[row][col].print();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
void Board::replace(int org_row, int org_col, int trg_row, int trg_col)
{
	m_layout[trg_row][trg_col].setPiece(m_layout[org_row][org_col].getPiece());
	m_layout[org_row][org_col].setPiece(new Piece());
}

bool Board::move(int org_row, int org_col, int trg_row, int trg_col)
{
	if (!isValidPosition(org_row, org_col) || !isValidPosition(trg_row, trg_col)) {
		return false;
	}

	Block org_blk = m_layout[org_row][org_col];

	if (!org_blk.getPiece()->isValidMove(org_row, org_col, trg_row, trg_col)) {
		return false;
	}

	replace(org_row, org_col, trg_row, trg_col);
	
	return true;
}

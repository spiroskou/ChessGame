#include <iostream>
#include "Board.h"
#include "Piece.h"
#include <windows.h>

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
			getPiece(row, col)->print();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
void Board::replace(int src_row, int src_col, int trg_row, int trg_col)
{
	std::shared_ptr<Piece> src_piece = getPiece(src_row, src_col);
	setPiece(trg_row, trg_col, src_piece);
	setPiece(src_row, src_col, std::make_shared<Piece>());
}

bool Board::move(int src_row, int src_col, int trg_row, int trg_col)
{
	// Check if the player chose valid positions
	if (!isValidPosition(src_row, src_col) || !isValidPosition(trg_row, trg_col)) {
		return false;
	}

	// Check if the player chose a valid move for the corresponding Piece
	if (!getPiece(src_row, src_col)->isValidMove(src_row, src_col, trg_row, trg_col)) {
		return false;
	}

	replace(src_row, src_col, trg_row, trg_col);
	
	return true;
}

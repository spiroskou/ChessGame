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
			getBlock(row, col).print();
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}
void Board::replace(int org_row, int org_col, int trg_row, int trg_col)
{
	std::shared_ptr<Piece> org_piece = getPieceInBlock(org_row, org_col);
	setPieceInBlock(trg_row, trg_col, org_piece);
	setPieceInBlock(org_row, org_col, std::make_shared<Piece>());
}

bool Board::move(int org_row, int org_col, int trg_row, int trg_col)
{
	// Check if the player chose valid positions
	if (!isValidPosition(org_row, org_col) || !isValidPosition(trg_row, trg_col)) {
		return false;
	}

	// Check if the player chose a valid move for the corresponding Piece
	if (!getPieceInBlock(org_row, org_col)->isValidMove(org_row, org_col, trg_row, trg_col)) {
		return false;
	}

	replace(org_row, org_col, trg_row, trg_col);
	
	return true;
}

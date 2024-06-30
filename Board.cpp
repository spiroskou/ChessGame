#include <iostream>
#include "Board.h"
#include "Piece.h"
#include <windows.h>
#include <memory>

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

std::shared_ptr<Piece> Board::temp_replace(int src_row, int src_col, int trg_row, int trg_col)
{
	std::shared_ptr<Piece> src_piece = getPiece(src_row, src_col);
	std::shared_ptr<Piece> dest_piece = getPiece(trg_row, trg_col);
	setPiece(trg_row, trg_col, src_piece);
	setPiece(src_row, src_col, std::make_shared<Piece>());

	return dest_piece;
}

void Board::restore(int src_row, int src_col, int trg_row, int trg_col, std::shared_ptr<Piece> tmp_piece)
{
	std::shared_ptr<Piece> dest_piece = getPiece(trg_row, trg_col);
	setPiece(trg_row, trg_col, tmp_piece);
	setPiece(src_row, src_col, dest_piece);
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

static PieceColor getOpponentColor(int turn_counter)
{
	if (turn_counter % 2 != 0) {
		return PieceColor::Black;
	}

	return PieceColor::White;
}

std::shared_ptr<King> Board::getKing(PieceColor color, int &king_row, int& king_col)
{
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			std::shared_ptr<Piece> piece = m_layout[row][col];
			
			if (piece->getType() == PieceType::King && piece->getColor() == color) {
				std::shared_ptr<King> king = std::static_pointer_cast<King> (piece);
				king_row = row;
				king_col = col;
				return king;
			}
		}
	}

	return nullptr;
}

bool Board::isKingInCheck(std::shared_ptr<King> king, int king_row, int king_col) const
{
	// If the king is not found, it's not a valid state, so return false
	if (!king) {
		return false;
	}

	// Check if any opponent's pieces threaten the king

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			std::shared_ptr<Piece> piece = getPiece(row,col);
			
			if (piece->getColor() == king->getColor()) {
				continue;
			}

			if (piece->isValidMove(row, col, king_row, king_col)) {
				return true;
			}
		}
	}

	return false; // King is not in check
}

bool Board::isCheckmate(int turn_counter)
{
	PieceColor opp_color = getOpponentColor(turn_counter);

	int king_row = -1, king_col = -1;
	std::shared_ptr<King> king = getKing(opp_color, king_row, king_col);
	// If the king is not found, it's not a valid state, so return false
	if (!king) {
		return false;
	}

	// Check if the king is in check
	if (!isKingInCheck(king, king_row, king_col)) {
		return false; // King is not in check, so it's not checkmate
	}

	// Check if the king has any legal moves to escape check
	for (int row = king_row - 1; row <= king_row + 1; ++row) {
		for (int col = king_col - 1; col <= king_col + 1; ++col) {
			if (row >= 0 && row < 8 && col >= 0 && col < 8 && !(row == king_row && col == king_col)) {
				if (getPiece(row, col)->getColor() != opp_color) {
					int dum_king_row = -1, dum_king_col = -1;
					// Try to move the king to the target position and check if it's still in check
					king = getKing(opp_color, dum_king_row, dum_king_col);
					std::shared_ptr<Piece> tmp_piece = temp_replace(dum_king_row, dum_king_col, row, col);
					bool still_in_check = isKingInCheck(king, row, col);
					// Undo the move
					restore(dum_king_row, dum_king_col, row, col, tmp_piece);
					if (!still_in_check) {
						return false; // King has at least one legal move to escape check
					}
				}
			}
		}
	}

	// If the king has no legal moves to escape check, it's checkmate
	return true;

}

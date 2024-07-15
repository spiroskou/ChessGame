#include <iostream>
#include "Board.h"
#include "Piece.h"
#include <windows.h>
#include <memory>
#include "sdl.h"

static std::shared_ptr<Board> board = std::make_shared<Board>();
static int turn_counter = 1;

void Board::initializePieceRow(int row, PieceColor color) {
	m_layout[row][0] = std::make_shared<Rook>(color);
	m_layout[row][1] = std::make_shared<Knight>(color);
	m_layout[row][2] = std::make_shared<Bishop>(color);
	m_layout[row][3] = std::make_shared<Queen>(color);
	m_layout[row][4] = std::make_shared<King>(color);
	m_layout[row][5] = std::make_shared<Bishop>(color);
	m_layout[row][6] = std::make_shared<Knight>(color);
	m_layout[row][7] = std::make_shared<Rook>(color);
}

void Board::initializePawnRow(int row, PieceColor color) {
	for (int col = 0; col < 8; ++col) {
		m_layout[row][col] = std::make_shared<Pawn>(color);
	}
}

void Board::initializeEmptyRows() {
	for (int row = 2; row <= 5; ++row) {
		for (int col = 0; col < 8; ++col) {
			m_layout[row][col] = nullptr;
		}
	}
}

static PieceColor getOpponentColor()
{
	if (turn_counter % 2 != 0) {
		return PieceColor::Black;
	}

	return PieceColor::White;
}

static PieceColor getColor()
{
	if (turn_counter % 2 != 0) {
		return PieceColor::White;
	}

	return PieceColor::Black;
}

int getTurnCounter()
{
	return turn_counter;
}

void IncrementTurnCounter()
{
	turn_counter++;
}

std::shared_ptr<Board> getBoard()
{
	return board;
}

std::shared_ptr<Piece> Board::replace(int src_row, int src_col, int trg_row, int trg_col)
{
	std::shared_ptr<Piece> src_piece = getPiece(src_row, src_col);
	std::shared_ptr<Piece> dest_piece = getPiece(trg_row, trg_col);
	setPiece(trg_row, trg_col, src_piece);
	setPiece(src_row, src_col, nullptr);

	return dest_piece;
}

void Board::restore(int src_row, int src_col, int trg_row, int trg_col, std::shared_ptr<Piece> tmp_piece)
{
	std::shared_ptr<Piece> dest_piece = getPiece(trg_row, trg_col);
	setPiece(trg_row, trg_col, tmp_piece);
	setPiece(src_row, src_col, dest_piece);
}

MoveResult Board::move(int src_row, int src_col, int trg_row, int trg_col)
{
	// Check if the player chose a piece
	if (!getPiece(src_row, src_col)) {
		return MoveResult::InvalidPiece;
	}

	// Check if the player chose opponent's piece
	PieceColor opp_color = getOpponentColor();
	if (getPiece(src_row, src_col)->getColor() == opp_color) {
		return MoveResult::OpponentPiece;
	}
	
	// Check if the player chose a valid move for the corresponding Piece
	if (!getPiece(src_row, src_col)->isValidMove(src_row, src_col, trg_row, trg_col)) {
		return MoveResult::InvalidMove;
	}

	replace(src_row, src_col, trg_row, trg_col);
	
	if (board->isKingInCheck(getColor())) {
		std::shared_ptr<Piece> tmp_piece = board->getPiece(src_row, src_col);
		board->restore(src_row, src_col, trg_row, trg_col, tmp_piece);
		return MoveResult::KingInCheck;
	}

	if (board->isCheckmate()) {
		return MoveResult::Checkmate;
	}

	return MoveResult::ValidMove;
}

std::shared_ptr<King> Board::getKing(PieceColor color, int &king_row, int& king_col) const
{
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			std::shared_ptr<Piece> piece = m_layout[row][col];
			if (!piece) continue;
			
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

bool Board::isKingInCheck(PieceColor color) const
{
	// If the king is not found, it's not a valid state, so return false
	int king_row = -1, king_col = -1;
	std::shared_ptr<King> king = getKing(color, king_row, king_col);
	if (!king) {
		return false;
	}

	// Check if any opponent's pieces threaten the king

	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 8; col++) {
			std::shared_ptr<Piece> piece = getPiece(row,col);
			if (!piece) continue;
			
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

static int checkForPromotion(int dest_row, int dest_col)
{
	std::shared_ptr<Piece> tmp_piece = board->getPiece(dest_row, dest_col);
	if (!tmp_piece) return 0;

	if (tmp_piece->getType() == PieceType::Pawn && (dest_row == 0 || dest_row == 7)) {
		board->setPiece(dest_row, dest_col, std::make_shared<Queen>(getColor()));
		return 1;
	}

	return 0;
}

MoveResult makeTheMove(int src_row, int src_col, int trg_row, int trg_col)
{
	MoveResult res = board->move(src_row, src_col, trg_row, trg_col);

	if (res == MoveResult::ValidMove) {
		int promoted = checkForPromotion(trg_row, trg_col);
		if (promoted) {
			if (board->isCheckmate()) {
				res = MoveResult::Checkmate;
			}
		}
	}

	return res;
}

bool Board::isCheckmate()
{
	PieceColor opp_color = getOpponentColor();

	int king_row = -1, king_col = -1;
	std::shared_ptr<King> king = getKing(opp_color, king_row, king_col);
	// If the king is not found, it's not a valid state, so return false
	if (!king) {
		return false;
	}

	// Check if the king is in check
	if (!isKingInCheck(opp_color)) {
		return false; // King is not in check, so it's not checkmate
	}

	// Check if the king has any legal moves to escape check
	for (int row = king_row - 1; row <= king_row + 1; ++row) {
		for (int col = king_col - 1; col <= king_col + 1; ++col) {
			if (row >= 0 && row < 8 && col >= 0 && col < 8 && !(row == king_row && col == king_col)) {
				std::shared_ptr<Piece> piece = getPiece(row, col);
				if (!piece) continue;

				if (piece->getColor() != opp_color) {
					int dum_king_row = -1, dum_king_col = -1;

					// Try to move the king to the target position and check if it's still in check
					king = getKing(opp_color, dum_king_row, dum_king_col);
					std::shared_ptr<Piece> tmp_piece = replace(dum_king_row, dum_king_col, row, col);
					bool still_in_check = isKingInCheck(opp_color);

					// Undo the move
					restore(dum_king_row, dum_king_col, row, col, tmp_piece);

					if (!still_in_check) {
						return false; // King has at least one legal move to escape check
					}
				}
			}
		}
	}

	// Check if any piece can block the check or capture the attacking piece
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (row == king_row && col == king_col) continue;
			std::shared_ptr<Piece> piece = getPiece(row, col);
			if (!piece) continue;

			if (piece->getColor() == opp_color) {
				// Check all possible moves for this piece
				for (int target_row = 0; target_row < 8; ++target_row) {
					for (int target_col = 0; target_col < 8; ++target_col) {
						if (piece->isValidMove(row, col, target_row, target_col)) {
							std::shared_ptr<Piece> tmp_piece = replace(row, col, target_row, target_col);
							bool still_in_check = isKingInCheck(opp_color);

							// Undo the move
							restore(row, col, target_row, target_col, tmp_piece);

							if (!still_in_check) {
								return false; // There is a piece that can block the check or capture the attacker
							}
						}
					}
				}
			}
		}
	}

	// If the king has no legal moves to escape check, it's checkmate
	return true;

}

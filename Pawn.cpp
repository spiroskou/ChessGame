#include "Pawn.h"
#include <iostream>
#include <array>
#include "Board.h"

bool Pawn::isValidMove(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();
	int direction = (this->getColor() == PieceColor::White) ? 1 : -1;
    Block trg_block = board->getBlock(trg_row, trg_col);
    Piece *trg_piece = trg_block.getPiece();

	if (trg_piece->getType() == PieceType::Empty) {
        // Pawn can move forward one square
        if (trg_col == org_col && trg_row == org_row + direction) {
            return true;
        }
        // Pawn can move forward two squares from its starting position
        else if (trg_col == org_col && trg_row == org_row + 2 * direction && getFirstMove()) {
            // Check if the path is clear (no pieces in the way)
            if (board->getBlock(org_row + direction, org_col).isEmpty()) {
                return true;
            }
        }
    }
    else {
        // Check if the destination block contains an opponent's piece
        if (board->getBlock(trg_row, trg_col).getPiece()->getColor() != this->getColor()) {
            // Pawn can capture diagonally
            if (std::abs(trg_col - org_col) == 1 && trg_row == org_row + direction) {
                return true;
            }
        }
    }

	return false;
}

#include "Pawn.h"
#include <iostream>
#include <array>
#include "Board.h"

bool Pawn::isValidMove(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();
    int direction = (this->getColor() == PieceColor::White) ? 1 : -1;
    std::shared_ptr<Piece> trg_piece = board->getPiece(trg_row, trg_col);

    if (trg_piece->isEmpty()) {
        // Pawn can move forward one square
        if (trg_col == org_col && trg_row == org_row + direction) {
            return true;
        } else if (trg_col == org_col && trg_row == org_row + 2 * direction && getFirstMove()) { 
            // Pawn can move forward two squares from its starting position

            // Check if the path is clear (no pieces in the way)
            if (board->getPiece(org_row + direction, org_col)->isEmpty()) {
                return true;
            }
        }
    } else {
        // Check if the destination block contains an opponent's piece
        if (board->getPiece(trg_row, trg_col)->getColor() != this->getColor()) {
            // Pawn can capture diagonally
            if (std::abs(trg_col - org_col) == 1 && trg_row == org_row + direction) {
                return true;
            }
        }
    }
	
    return false;
}

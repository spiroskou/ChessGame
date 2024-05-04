#include "Pawn.h"
#include <iostream>
#include <array>
#include "Board.h"

bool Pawn::isValidMove(int src_row, int src_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();
    int direction = (this->getColor() == PieceColor::White) ? 1 : -1;
    std::shared_ptr<Piece> trg_piece = board->getPiece(trg_row, trg_col);

    if (trg_piece->isEmpty()) {
        // Pawn can move forward one square
        if (trg_col == src_col && trg_row == src_row + direction) {
            return true;
        } else if (trg_col == src_col && trg_row == src_row + 2 * direction && getFirstMove()) { 
            // Pawn can move forward two squares from its starting position

            // Check if the path is clear (no pieces in the way)
            if (board->getPiece(src_row + direction, src_col)->isEmpty()) {
                return true;
            }
        }
    } else {
        // Check if the destination block contains an opponent's piece
        if (board->getPiece(trg_row, trg_col)->getColor() != this->getColor()) {
            // Pawn can capture diagonally
            if (std::abs(trg_col - src_col) == 1 && trg_row == src_row + direction) {
                return true;
            }
        }
    }
	
    return false;
}

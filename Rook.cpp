#include "Rook.h"
#include <iostream>
#include <array>
#include "Board.h"

bool Rook::isValidMove(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Check if the rook is moving horizontally or vertically
    if (org_row == trg_row || org_col == trg_col) {
        // Check if the path is clear
        if (isPathClear(org_row, org_col, trg_row, trg_col)) {
            // Check if the target block is empty or contains an opponent's piece
            std::shared_ptr<Piece> trg_piece = board->getPiece(trg_row, trg_col);
            if (trg_piece->getType() == PieceType::Empty || trg_piece->getColor() != this->getColor()) {
                return true;
            }
        }
    }

    return false;
}

bool Rook::isPathClear(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Check if the rook is moving horizontally
    if (org_row == trg_row) {
        int start_col = std::min(org_col, trg_col);
        int end_col = std::max(org_col, trg_col);
        for (int col = start_col + 1; col < end_col; ++col) {
            if (!board->getPiece(org_row, col)->isEmpty()) {
                return false; // Path is pieceed
            }
        }
    }
    // Check if the rook is moving vertically
    else if (org_col == trg_col) {
        int start_row = std::min(org_row, trg_row);
        int end_row = std::max(org_row, trg_row);
        for (int row = start_row + 1; row < end_row; ++row) {
            if (!board->getPiece(row, org_col)->isEmpty()) {
                return false; // Path is pieceed
            }
        }
    }

    return true; // Path is clear
}
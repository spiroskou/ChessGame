#include "Bishop.h"
#include <iostream>
#include <array>
#include "Board.h"

bool Bishop::isValidMove(int src_row, int src_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Check if the bishop is moving diagonally
    if (std::abs(trg_row - src_row) == std::abs(trg_col - src_col)) {
        // Check if the path is clear
        if (isPathClear(src_row, src_col, trg_row, trg_col)) {
            // Check if the target block is empty or contains an opponent's piece
            std::shared_ptr<Piece> trg_piece = board->getPiece(trg_row, trg_col);
            if (trg_piece->isEmpty() || trg_piece->getColor() != this->getColor()) {
                return true;
            }
        }
    }

    return false;
}

bool Bishop::isPathClear(int src_row, int src_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Determine the direction of movement
    int row_direction = (trg_row > src_row) ? 1 : -1;
    int col_direction = (trg_col > src_col) ? 1 : -1;

    // Iterate over the squares along the diagonal path
    int row = src_row + row_direction;
    int col = src_col + col_direction;
    while (row != trg_row && col != trg_col) {
        if (!board->getPiece(row, col)->isEmpty()) {
            return false; // Path is blocked
        }
        row += row_direction;
        col += col_direction;
    }

    return true; // Path is clear
}

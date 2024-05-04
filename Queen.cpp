#include "Queen.h"
#include <iostream>
#include <array>
#include "Board.h"

bool Queen::isValidMove(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Check if the queen is moving horizontally, vertically, or diagonally
    if (org_row == trg_row || org_col == trg_col || std::abs(trg_row - org_row) == std::abs(trg_col - org_col)) {
        // Check if the path is clear
        if (isPathClear(org_row, org_col, trg_row, trg_col)) {
            // Check if the target piece is empty or contains an opponent's piece
            std::shared_ptr<Piece> trg_piece = board->getPiece(trg_row, trg_col);
            if (trg_piece->isEmpty() || trg_piece->getColor() != this->getColor()) {
                return true;
            }
        }
    }

    return false;
}

bool Queen::isPathClear(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Determine the direction of movement
    int row_direction = (trg_row > org_row) ? 1 : (trg_row < org_row) ? -1 : 0;
    int col_direction = (trg_col > org_col) ? 1 : (trg_col < org_col) ? -1 : 0;

    // Check if the queen is moving horizontally, vertically, or diagonally
    if (org_row == trg_row || org_col == trg_col || std::abs(trg_row - org_row) == std::abs(trg_col - org_col)) {
        int row = org_row + row_direction;
        int col = org_col + col_direction;

        // Iterate over the squares along the path
        while (row != trg_row || col != trg_col) {
            if (!board->getPiece(row, col)->isEmpty()) {
                return false; // Path is pieceed
            }
            row += row_direction;
            col += col_direction;
        }
    }

    return true; // Path is clear
}

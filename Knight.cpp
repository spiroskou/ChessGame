#include "Knight.h"
#include <iostream>
#include <array>
#include "Board.h"

bool Knight::isValidMove(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Calculate the absolute difference in rows and columns
    int row_diff = std::abs(trg_row - org_row);
    int col_diff = std::abs(trg_col - org_col);

    // Check if the move is in an L-shape (2 squares in one direction and 1 square in the other)
    if ((row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2)) {
        // Check if the target block is empty or contains an opponent's piece
        std::shared_ptr<Piece> trg_piece = board->getPiece(trg_row, trg_col);
        if (trg_piece->isEmpty() || trg_piece->getColor() != this->getColor()) {
            return true;
        }
    }

    return false;
}


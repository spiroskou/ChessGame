#include "King.h"
#include <iostream>
#include <array>
#include "Board.h"

bool King::isValidMove(int org_row, int org_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    // Check if the target block is within one square of the king's position
    if (std::abs(trg_row - org_row) <= 1 && std::abs(trg_col - org_col) <= 1) {
        // Check if the target block is empty or contains an opponent's piece
        Block trg_block = board->getBlock(trg_row, trg_col);
        if (trg_block.getPiece()->getType() == PieceType::Empty || trg_block.getPiece()->getColor() != this->getColor()) {
            return true;
        }
    }

    return false;
}

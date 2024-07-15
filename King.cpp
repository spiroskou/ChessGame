#include "King.h"
#include <iostream>
#include <array>
#include "Board.h"

bool King::isValidMove(int src_row, int src_col, int trg_row, int trg_col) const
{
    std::shared_ptr<Board> board = getBoard();

    if (src_row == trg_row && src_col == trg_col) {
        return false;
    }

    // Check if the target block is within one square of the king's position
    if (std::abs(trg_row - src_row) <= 1 && std::abs(trg_col - src_col) <= 1) {
        // Check if the target block is empty or contains an opponent's piece
        std::shared_ptr<Piece> trg_piece = board->getPiece(trg_row, trg_col);
        if (!trg_piece || trg_piece->getColor() != this->getColor()) {
            return true;
        }
    }

    return false;
}

std::string King::getImagePath() const
{
    std::string str1, str2 = "-king.png";

    switch (getColor()) {
        case (PieceColor::White):
            str1 = "images/white";
            break;
        case (PieceColor::Black):
            str1 = "images/black";
            break;
        case (PieceColor::Blank):
        default:
            str1 = "";
            break;
    }

    return (str1 + str2);
}

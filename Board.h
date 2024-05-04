#pragma once

#include <array>
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board
{
private:
	std::array<std::array<std::shared_ptr<Piece>, 8>, 8> m_layout;

public:
    Board() : m_layout{{
        {std::make_shared<Rook>(PieceColor::White), std::make_shared<Knight>(PieceColor::White), std::make_shared<Bishop>(PieceColor::White), std::make_shared<Queen>(PieceColor::White), std::make_shared<King>(PieceColor::White), std::make_shared<Bishop>(PieceColor::White), std::make_shared<Knight>(PieceColor::White), std::make_shared<Rook>(PieceColor::White)},
        {std::make_shared<Pawn>(PieceColor::White), std::make_shared<Pawn>(PieceColor::White), std::make_shared<Pawn>(PieceColor::White), std::make_shared<Pawn>(PieceColor::White), std::make_shared<Pawn>(PieceColor::White), std::make_shared<Pawn>(PieceColor::White), std::make_shared<Pawn>(PieceColor::White), std::make_shared<Pawn>(PieceColor::White)},
        {std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>()},
        {std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>()},
        {std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>()},
        {std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>(), std::make_shared<Piece>()},
        {std::make_shared<Pawn>(PieceColor::Black), std::make_shared<Pawn>(PieceColor::Black), std::make_shared<Pawn>(PieceColor::Black), std::make_shared<Pawn>(PieceColor::Black), std::make_shared<Pawn>(PieceColor::Black), std::make_shared<Pawn>(PieceColor::Black), std::make_shared<Pawn>(PieceColor::Black), std::make_shared<Pawn>(PieceColor::Black)},
        {std::make_shared<Rook>(PieceColor::Black), std::make_shared<Knight>(PieceColor::Black), std::make_shared<Bishop>(PieceColor::Black), std::make_shared<Queen>(PieceColor::Black), std::make_shared<King>(PieceColor::Black), std::make_shared<Bishop>(PieceColor::Black), std::make_shared<Knight>(PieceColor::Black), std::make_shared<Rook>(PieceColor::Black)},
    } } {};

    void print();
    bool move(int org_row, int org_col, int trg_row, int trg_col);
    void replace(int org_row, int org_col, int trg_row, int trg_col);
    bool isValidPosition(int row, int col);
    std::shared_ptr<Piece> getPiece(int row, int col) { return m_layout[row][col]; };
    void setPiece(int row, int col, std::shared_ptr<Piece> piece) { m_layout[row][col] = piece; };
};

std::shared_ptr<Board> getBoard();

#pragma once

#include <array>
#include "Block.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board
{
private:
	std::array<std::array<Block, 8>, 8> m_layout;

public:
    Board() : m_layout{{
        {Block(std::make_shared<Rook>(PieceColor::White)), Block(std::make_shared<Knight>(PieceColor::White)), Block(std::make_shared<Bishop>(PieceColor::White)), Block(std::make_shared<Queen>(PieceColor::White)), Block(std::make_shared<King>(PieceColor::White)), Block(std::make_shared<Bishop>(PieceColor::White)), Block(std::make_shared<Knight>(PieceColor::White)), Block(std::make_shared<Rook>(PieceColor::White))},
        {Block(std::make_shared<Pawn>(PieceColor::White)), Block(std::make_shared<Pawn>(PieceColor::White)), Block(std::make_shared<Pawn>(PieceColor::White)), Block(std::make_shared<Pawn>(PieceColor::White)), Block(std::make_shared<Pawn>(PieceColor::White)), Block(std::make_shared<Pawn>(PieceColor::White)), Block(std::make_shared<Pawn>(PieceColor::White)), Block(std::make_shared<Pawn>(PieceColor::White))},
        {Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>())},
        {Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>())},
        {Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>())},
        {Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>()), Block(std::make_shared<Piece>())},
        {Block(std::make_shared<Pawn>(PieceColor::Black)), Block(std::make_shared<Pawn>(PieceColor::Black)), Block(std::make_shared<Pawn>(PieceColor::Black)), Block(std::make_shared<Pawn>(PieceColor::Black)), Block(std::make_shared<Pawn>(PieceColor::Black)), Block(std::make_shared<Pawn>(PieceColor::Black)), Block(std::make_shared<Pawn>(PieceColor::Black)), Block(std::make_shared<Pawn>(PieceColor::Black))},
        {Block(std::make_shared<Rook>(PieceColor::Black)), Block(std::make_shared<Knight>(PieceColor::Black)), Block(std::make_shared<Bishop>(PieceColor::Black)), Block(std::make_shared<Queen>(PieceColor::Black)), Block(std::make_shared<King>(PieceColor::Black)), Block(std::make_shared<Bishop>(PieceColor::Black)), Block(std::make_shared<Knight>(PieceColor::Black)), Block(std::make_shared<Rook>(PieceColor::Black))},
    } } {};

    void print();
    bool move(int org_row, int org_col, int trg_row, int trg_col);
    void replace(int org_row, int org_col, int trg_row, int trg_col);
    bool isValidPosition(int row, int col);
    Block& getBlock(int row, int col) { return m_layout[row][col]; };
    std::shared_ptr<Piece> getPieceInBlock(int row, int col) { return getBlock(row, col).getPiece(); };
    void setPieceInBlock(int row, int col, std::shared_ptr<Piece> piece) { m_layout[row][col].setPiece(piece); };
};

std::shared_ptr<Board> getBoard();

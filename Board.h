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
        {Block(new Rook(PieceColor::White)), Block(new Knight(PieceColor::White)), Block(new Bishop(PieceColor::White)), Block(new Queen(PieceColor::White)), Block(new King(PieceColor::White)), Block(new Bishop(PieceColor::White)), Block(new Knight(PieceColor::White)), Block(new Rook(PieceColor::White))},
        {Block(new Pawn(PieceColor::White)), Block(new Pawn(PieceColor::White)), Block(new Pawn(PieceColor::White)), Block(new Pawn(PieceColor::White)), Block(new Pawn(PieceColor::White)), Block(new Pawn(PieceColor::White)), Block(new Pawn(PieceColor::White)), Block(new Pawn(PieceColor::White))},
        {Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece())},
        {Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece())},
        {Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece())},
        {Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece()), Block(new Piece())},
        {Block(new Pawn(PieceColor::Black)), Block(new Pawn(PieceColor::Black)), Block(new Pawn(PieceColor::Black)), Block(new Pawn(PieceColor::Black)), Block(new Pawn(PieceColor::Black)), Block(new Pawn(PieceColor::Black)), Block(new Pawn(PieceColor::Black)), Block(new Pawn(PieceColor::Black))},
        {Block(new Rook(PieceColor::Black)), Block(new Knight(PieceColor::Black)), Block(new Bishop(PieceColor::Black)), Block(new Queen(PieceColor::Black)), Block(new King(PieceColor::Black)), Block(new Bishop(PieceColor::Black)), Block(new Knight(PieceColor::Black)), Block(new Rook(PieceColor::Black))},
    } } {};
	void print();

    bool move(int org_row, int org_col, int trg_row, int trg_col);
    void replace(int org_row, int org_col, int trg_row, int trg_col);
    bool isValidPosition(int row, int col);
    const Block& getBlock(int row, int col) { return m_layout[row][col]; };
};

std::shared_ptr<Board> getBoard();

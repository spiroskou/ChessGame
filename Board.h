#pragma once

#include <array>
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

enum class MoveResult {
    InvalidPosition = 0,
    OpponentPiece,
    InvalidMove,
    KingInCheck,
    ValidMove
};

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
    MoveResult move(int src_row, int src_col, int trg_row, int trg_col);
    void replace(int src_row, int src_col, int trg_row, int trg_col);
    std::shared_ptr<Piece> temp_replace(int src_row, int src_col, int trg_row, int trg_col);
    void restore(int src_row, int src_col, int trg_row, int trg_col, std::shared_ptr<Piece> tmp_piece);
    bool isValidPosition(int row, int col);
    std::shared_ptr<Piece> getPiece(int row, int col) const { return m_layout[row][col]; };
    void setPiece(int row, int col, std::shared_ptr<Piece> piece) { m_layout[row][col] = piece; };
    bool isCheckmate();
    std::shared_ptr<King> getKing(PieceColor color, int& king_row, int& king_col);
    bool isKingInCheck(std::shared_ptr<King> king, int king_row, int king_col) const;
};

std::shared_ptr<Board> getBoard();
void IncrementTurnCounter();
int getTurnCounter();
MoveResult makeTheMove(int src_row, int src_col, int trg_row, int trg_col);
bool boardIsCheckmate();

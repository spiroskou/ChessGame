#pragma once

#include <array>
#include <memory>
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

enum class MoveResult {
    InvalidPiece = 0,
    OpponentPiece,
    InvalidMove,
    KingInCheck,
    Checkmate,
    ValidMove
};

class Board
{
private:
	std::array<std::array<std::shared_ptr<Piece>, 8>, 8> m_layout;

    void initializePieceRow(int row, PieceColor color);
    void initializePawnRow(int row, PieceColor color);
    void initializeEmptyRows();
public:
    Board() {
        initializePieceRow(0, PieceColor::White);
        initializePawnRow(1, PieceColor::White);
        initializeEmptyRows();
        initializePawnRow(6, PieceColor::Black);
        initializePieceRow(7, PieceColor::Black);
    }

    MoveResult move(int src_row, int src_col, int trg_row, int trg_col);
    std::shared_ptr<Piece> replace(int src_row, int src_col, int trg_row, int trg_col);
    void restore(int src_row, int src_col, int trg_row, int trg_col, std::shared_ptr<Piece> tmp_piece);
    std::shared_ptr<Piece> getPiece(int row, int col) const { return m_layout[row][col]; };
    void setPiece(int row, int col, std::shared_ptr<Piece> piece) { m_layout[row][col] = piece; };
    bool isCheckmate();
    std::shared_ptr<King> getKing(PieceColor color, int& king_row, int& king_col) const;
    bool isKingInCheck(PieceColor color) const;
};

std::shared_ptr<Board> getBoard();
void IncrementTurnCounter();
int getTurnCounter();
MoveResult makeTheMove(int src_row, int src_col, int trg_row, int trg_col);

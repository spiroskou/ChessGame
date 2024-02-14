#include "Block.h"

void Block::print()
{
	m_piece.print();
}

void Block::blockMove(Block& org, Block& trg)
{
	Piece org_piece = org.getPiece();
	Piece trg_piece = trg.getPiece();
}

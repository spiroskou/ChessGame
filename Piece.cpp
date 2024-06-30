#include <iostream>
#include <array>
#include "Piece.h"
//#include <windows.h>

void Piece::print() const
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//if (hConsole == INVALID_HANDLE_VALUE) {
	//	std::cerr << "Error getting console handle\n";
	//	return;
	//}

	char symbol = 0;

	switch (m_type)
	{
	case PieceType::Empty:
		symbol = '.';
		break;
	case PieceType::Pawn:
		symbol = 'P';
		break;
	case PieceType::Knight:
		symbol = 'N';
		break;
	case PieceType::Bishop:
		symbol = 'B';
		break;
	case PieceType::Rook:
		symbol = 'R';
		break;
	case PieceType::Queen:
		symbol = 'Q';
		break;
	case PieceType::King:
		symbol = 'K';
		break;
	default:
		break;
	}

	//switch (m_color) {
	//case PieceColor::Black:
	//	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	//	break;
	//case PieceColor::White:
	//	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	//	break;
	//case PieceColor::Blank:
	//default:
	//	break;
	//}

	//std::cout << symbol;
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	this->size = 8;
}

ChessBoard::ChessBoard(int _size)
{
	size = _size;
}

const int ChessBoard::get_size()
{
	return this->size;
}

ChessBoard& ChessBoard::operator=(const ChessBoard& other)
{
	this->size = other.size;
	return *this;
}

bool ChessBoard::operator==(const ChessBoard& other)
{
	return this->size == other.size;
}
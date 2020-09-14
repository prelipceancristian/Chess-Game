#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	this->size = 8;
	this->id = 0;
}

ChessBoard::ChessBoard(int _id, int _size)
{
	size = _size;
	id = _id;
}

int ChessBoard::get_size() const
{
	return this->size;
}

int ChessBoard::get_id() const
{
	return this->id;
}

ChessBoard& ChessBoard::operator=(const ChessBoard& other)
{
	this->size = other.size;
	this->id = other.id;
	return *this;
}

bool ChessBoard::operator==(const ChessBoard& other)
{
	return this->id == other.id;
}
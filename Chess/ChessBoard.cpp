#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	this->size = 8;
	this->id = 0;
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			board[i][j] = 0;
}

ChessBoard::ChessBoard(int _id, int _size)
{
	size = _size;
	id = _id;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			board[i][j] = 0;
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

int ChessBoard::get_val_at_coord(int x, int y)
{
	return this->board[x][y];
}

void ChessBoard::set_val_at_coord(int val, int x, int y)
{
	this->board[x][y] = val;
}

bool ChessBoard::is_empty(int x, int y)
{
	return this->board[x][y] == 0;
}
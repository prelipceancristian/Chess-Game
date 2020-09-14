#include "ChessPiece.h"
ChessPiece::ChessPiece()
{
	pos_x = pos_y = 0;
	color = white;
}

ChessPiece::ChessPiece(int _pos_x, int _pos_y, Color _color)
{
	pos_x = _pos_x;
	pos_y = _pos_y;
	color = _color;
}

ChessPiece::ChessPiece(const ChessPiece& _piece)
{
	pos_x = _piece.pos_x;
	pos_y = _piece.pos_y;
	color = _piece.color;
}

int ChessPiece::get_position_x()
{
	return this->pos_x;
}

int ChessPiece::get_position_y()
{
	return this->pos_y;
}

Color ChessPiece::get_color()
{
	return this->color;
}

void ChessPiece::set_position_x(int pos)
{
	this->pos_x= pos;
}

void ChessPiece::set_position_y(int pos)
{
	this->pos_y = pos;
}

void ChessPiece::set_color(Color color)
{
	this->color = color;
}

void ChessPiece::set_position(int pos_x, int pos_y)
{
	pos_x = pos_x;
	pos_y = pos_y;
}
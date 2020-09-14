#pragma once
#include "ChessPiece.h"
class Pawn :
	public ChessPiece
{
	public:
	Pawn() : ChessPiece() {};
	Pawn(int _id, int _pos_x, int _pos_y, Color _color) : ChessPiece(_id, _pos_x, _pos_y, _color) {};
	Pawn(const Pawn& _pawn) : ChessPiece(_pawn) {};
	virtual vector<pair<int, int>> moves() override;
};


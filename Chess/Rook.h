#pragma once
#include "ChessPiece.h"
class Rook :
	public ChessPiece
{
public:
	Rook() : ChessPiece() {};
	Rook(int id, int pos_x, int pos_y, Color color) : ChessPiece(id, pos_x, pos_y, color) {};
	Rook(const Rook& rook) : ChessPiece(rook) {};
	virtual vector<pair<int, int>> moves() override;
};


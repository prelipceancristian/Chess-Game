#pragma once
#include "ChessPiece.h"
class Bishop :
	public ChessPiece
{
public:
	Bishop() : ChessPiece() {};
	Bishop(int id, int pos_x, int pos_y, Color color) : ChessPiece(id, pos_x, pos_y, color) {};
	Bishop(const Bishop& _Bishop) : ChessPiece(_Bishop) {};
	virtual vector<pair<int, int>> moves() override;
};


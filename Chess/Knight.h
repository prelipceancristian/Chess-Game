#pragma once
#include "ChessPiece.h"
class Knight :
	public ChessPiece
{
public:
	Knight() : ChessPiece() {};
	Knight(int id, int pos_x, int pos_y, Color color) : ChessPiece(id, pos_x, pos_y, color) {};
	Knight(const Knight& knight) : ChessPiece(knight) {};
	virtual vector<pair<int, int>> moves(ChessBoard) override;
};


#pragma once
#include "ChessPiece.h"
class Queen :
	public ChessPiece
{
public:
	Queen() : ChessPiece() {};
	Queen(int id, int pos_x, int pos_y, Color color) : ChessPiece(id, pos_x, pos_y, color) {};
	Queen(const Queen& queen) : ChessPiece(queen) {};
	virtual vector<pair<int, int>> moves(ChessBoard) override;
};


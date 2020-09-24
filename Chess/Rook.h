#pragma once
#include "ChessPiece.h"
class Rook :
	public ChessPiece
{
public:
	Rook() : ChessPiece() { name = "Rook"; };
	Rook(int id, int pos_x, int pos_y, Color color) : ChessPiece(id, pos_x, pos_y, color) { name = "Rook"; };
	Rook(const Rook& rook) : ChessPiece(rook) {};
	virtual vector<pair<int, int>> moves(ChessBoard) override;
};


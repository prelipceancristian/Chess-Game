#pragma once
#include "ChessPiece.h"
class King :
	public ChessPiece
{
public:
	King() : ChessPiece() {};
	King(int id, int px, int py, Color color) : ChessPiece(id, px, py, color) {};
	King(const King& king) : ChessPiece(king) {};
	virtual vector<pair<int, int>> moves(ChessBoard cb) override;
};


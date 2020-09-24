#pragma once
#include "ChessPiece.h"
class King :
	public ChessPiece
{
public:
	King() : ChessPiece() { name = "King"; };
	King(int id, int px, int py, Color color) : ChessPiece(id, px, py, color) { name = "King"; };
	King(const King& king) : ChessPiece(king) {};
	virtual vector<pair<int, int>> moves(ChessBoard cb) override;
};


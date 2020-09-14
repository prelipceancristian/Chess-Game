#pragma once
#include "ChessPiece.h"

class ChessBoard
{
private:
	int size;
public:
	ChessBoard();
	ChessBoard(int);
	~ChessBoard() {};

	const int get_size();

	ChessBoard& operator=(const ChessBoard& other);
	bool operator==(const ChessBoard& other);
};


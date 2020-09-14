#pragma once
#include "ChessPiece.h"

class ChessBoard
{
private:
	int size;
	int id;
public:
	ChessBoard();
	ChessBoard(int, int);
	~ChessBoard() {};

	int get_size() const;
	int get_id() const;

	ChessBoard& operator=(const ChessBoard& other);
	bool operator==(const ChessBoard& other);
};


#pragma once

#include <utility>
#include <vector>
#include "ChessBoard.h"
#include <iostream>
#include <string>


using std::vector;
using std::pair;
using std::ostream;
using std::string;

enum class Color
{
	white, black
};

class ChessPiece
{
protected:
	int id;
	int pos_x;
	int pos_y;
	Color color;
	string name = "ChessPiece";
public:
	ChessPiece();
	ChessPiece(int, int, int, Color);
	ChessPiece(const ChessPiece&);
	~ChessPiece() {};

	int get_position_x();
	int get_position_y();
	Color get_color();
	int get_id() const;

	void set_position_x(int);
	void set_position_y(int);
	void set_position(int, int);
	void set_color(Color);

	ChessPiece& operator=(const ChessPiece&);
	bool operator == (const ChessPiece&);

	virtual vector<pair<int, int>> moves(ChessBoard) { 
		vector<pair<int, int>> sol;
		return sol; 
	};

	friend ostream& operator<<(ostream& os, const ChessPiece& piece)
	{
		os << piece.get_id() << ". " << piece.name << " at coords (" << char(piece.pos_x + 65) << ", " << piece.pos_y + 1 << ")";
		return os;
	}
};


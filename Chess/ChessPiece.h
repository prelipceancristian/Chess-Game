#pragma once

enum Color
{
	white, black
};

typedef struct Position
{
	int pos_x;
	int pos_y;
};


class ChessPiece
{
private:
	int pos_x;
	int pos_y;
	Color color;
public:
	ChessPiece();
	ChessPiece(int, int, Color);
	ChessPiece(const ChessPiece&);
	~ChessPiece() {};

	int get_position_x();
	int get_position_y();
	Color get_color();

	void set_position_x(int);
	void set_position_y(int);
	void set_position(int, int);
	void set_color(Color);
};


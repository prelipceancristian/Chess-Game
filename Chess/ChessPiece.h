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
	int id;
	int pos_x;
	int pos_y;
	Color color;
public:
	ChessPiece();
	ChessPiece(int, int, int, Color);
	ChessPiece(const ChessPiece&);
	~ChessPiece() {};

	int get_position_x();
	int get_position_y();
	Color get_color();
	const int get_id();

	void set_position_x(int);
	void set_position_y(int);
	void set_position(int, int);
	void set_color(Color);

	ChessPiece& operator=(const ChessPiece&);
	bool operator == (const ChessPiece&);

};


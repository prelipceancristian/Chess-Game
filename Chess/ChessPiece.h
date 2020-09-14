#pragma once

enum class Color
{
	white, black
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
	int get_id() const;

	void set_position_x(int);
	void set_position_y(int);
	void set_position(int, int);
	void set_color(Color);

	ChessPiece& operator=(const ChessPiece&);
	bool operator == (const ChessPiece&);

};


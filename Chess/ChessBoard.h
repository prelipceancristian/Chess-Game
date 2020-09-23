#pragma once

constexpr int MAX_SIZE = 100;


/*
Convention for matrix values:
	-empty: 0
	-white piece: 1
	-black piece: -1
*/

class ChessBoard
{
private:
	int size;
	int id;
	int board[MAX_SIZE][MAX_SIZE];
public:
	ChessBoard();
	ChessBoard(int, int);
	~ChessBoard() {};

	int get_size() const;
	int get_id() const;
	int get_val_at_coord(int, int);

	void set_val_at_coord(int, int, int);

	bool is_empty(int, int);

	ChessBoard& operator=(const ChessBoard& other);
	bool operator==(const ChessBoard& other);
};


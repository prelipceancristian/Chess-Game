#include "Rook.h"
vector<pair<int, int>> Rook::moves(ChessBoard cb)
{
	int pos_x = this->get_position_x();
	int pos_y = this->get_position_y();
	vector<pair<int, int>> sol;
	for (int i = 0; i < 8; i++)
		if (i != pos_y)
		{
			if (cb.is_empty(pos_x, i))
				sol.push_back({ pos_x, i });
			else
				break;
		}
	for (int i = 0; i < 8; i++)
		if (i != pos_x)
		{
			if (cb.is_empty(i, pos_y))
				sol.push_back({ i, pos_y });
			else
				break;
		}
	return sol;
}

vector<pair<int, int>> Rook::attacks(ChessBoard cb)
{
	int pos_x = this->get_position_x();
	int pos_y = this->get_position_y();
	int col = this->get_color() == Color::white ? 1 : -1;
	vector<pair<int, int>> sol;
	//right
	int i;
	for (i = pos_x + 1; i < 8; i++) // start from the first right location until chessboard border
	{
		if (!cb.is_empty(i, pos_y)) // when finding something in the way, stop searching
			break;
	}
	if (i < 8 && col * cb.get_val_at_coord(i, pos_y) == -1) // if we stopped using the break, then i should be smaller than 8. if then the pieces have different colors, add the location as a possbile attack location
		sol.push_back({i, pos_y});
	//down
	for (i = pos_y - 1; i >= 0; i--)
	{
		if (!cb.is_empty(pos_x, i))
			break;
	}
	if (i >= 0 && col * cb.get_val_at_coord(pos_x, i) == -1)
		sol.push_back({ pos_x, i });
	//left
	for (i = pos_x - 1; i >= 0; i--)
	{
		if (!cb.is_empty(i, pos_y))
			break;
	}
	if (i >= 0 && col * cb.get_val_at_coord(i, pos_y) == -1)
		sol.push_back({i, pos_y});
	//up
	for (i = pos_y + 1; i <= 8; i++)
	{
		if (!cb.is_empty(pos_x, i))
			break;
	}
	if (i < 8 && col * cb.get_val_at_coord(pos_x, i) == -1)
		sol.push_back({pos_x, i});
	return sol;
	return sol;
}
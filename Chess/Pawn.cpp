#include "Pawn.h"
vector<pair<int, int>> Pawn::moves(ChessBoard cb)
{
	vector<pair<int, int>> sol;
	if (this->get_color() == Color::white)
	{
		if (this->get_position_y() <= 6 && cb.is_empty(this->get_position_x(), this->get_position_y() + 1))
			sol.push_back({ this->get_position_x(), this->get_position_y() + 1 });
	}
	else
		if(this->get_position_y() >= 1 && cb.is_empty(this->get_position_x(), this->get_position_y() - 1))
			sol.push_back({ this->get_position_x(), this->get_position_y() - 1 });
	return sol;
}

bool can_attack(int x, int y, int col, ChessBoard cb)
{
	if (x < 8 && y >= 0 && y < 8 && x >= 0 && cb.get_val_at_coord(x, y) * col == -1)
		return true;
	return false;
}

vector<pair<int, int>> Pawn::attacks(ChessBoard cb)
{
	vector<pair<int, int>> sol;
	int px = this->pos_x;
	int py = this->pos_y;
	int col = this->get_color() == Color::white ? 1 : -1;
	if (col == 1)
	{
		if (can_attack(px + 1, py + 1, col, cb))
			sol.push_back({ px + 1, py + 1 });
		if (can_attack(px - 1, py + 1, col, cb))
			sol.push_back({px - 1, py + 1});
	}
	else
	{
		if (can_attack(px + 1, py - 1, col, cb))
			sol.push_back({ px + 1, py - 1 });
		if (can_attack(px - 1, py - 1, col, cb))
			sol.push_back({px - 1, py - 1});
	}
	return sol;
}
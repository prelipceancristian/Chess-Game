#include "King.h"

bool can_add_pos(int x, int y, ChessBoard cb)
{
	if (x < 8 && y >= 0 && y < 8 && x >=0 && cb.is_empty(x, y))
		return true;
	return false;
}


vector<pair<int, int>> King::moves(ChessBoard cb)
{


	vector<pair<int, int>> sol;
	int x = this->get_position_x();
	int y = this->get_position_y();
	y++;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	x++;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	y--;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	y--;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	x--;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	x--;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	y++;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	y++;
	if (can_add_pos(x, y, cb))
		sol.push_back({ x, y });
	return sol;

}
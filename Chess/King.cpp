#include "King.h"

bool can_add_pos(int x, int y, ChessBoard cb)
{
	if (x < 8 && y >= 0 && y < 8 && x >=0 && cb.is_empty(x, y))
		return true;
	return false;
}

bool can_attack(int x, int y, int col, ChessBoard cb)
{
	if (x < 8 && y >= 0 && y < 8 && x >= 0 && cb.get_val_at_coord(x, y) * col == -1)
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

vector<pair<int, int>> King::attacks(ChessBoard cb)
{
	vector<pair<int, int>> sol;
	int x = this->get_position_x();
	int y = this->get_position_y();
	int col = this->color == Color::white ? 1 : -1;
	y++;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	x++;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	y--;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	y--;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	x--;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	x--;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	y++;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	y++;
	if (can_attack(x, y, col, cb))
		sol.push_back({ x, y });
	return sol;
}
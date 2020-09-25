#include "Knight.h"

bool can_add(int x, int y, ChessBoard cb)
{
	if (x < 8 && y >= 0 && x >= 0 && y < 8 && cb.is_empty(x, y))
		return true;
	return false;
}

bool can_attack(int x, int y, int col, ChessBoard cb)
{
	if (x < 8 && y >= 0 && y < 8 && x >= 0 && cb.get_val_at_coord(x, y) * col == -1)
		return true;
	return false;
}

vector<pair<int, int>> Knight::moves(ChessBoard cb)
{
	vector<pair<int, int>> sol;
	pair<int, int> pos = { this->get_position_x(), this->get_position_y() };
	//pos 1
	pos.first += 1;
	pos.second += 2;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	//pos 2
	pos.first += 1;
	pos.second -= 1;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	//pos 3
	pos.second -= 2;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	//pos 4
	pos.first -= 1;
	pos.second -= 1;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	//pos 5
	pos.first -= 2;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	//pos 6
	pos.first -= 1;
	pos.second += 1;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	//pos 7
	pos.second += 2;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	//pos 8
	pos.first += 1;
	pos.second += 1;
	if (can_add(pos.first, pos.second, cb))
		sol.push_back(pos);
	return sol;
}

vector<pair<int, int>> Knight::attacks(ChessBoard cb)
{
	vector<pair<int, int>> sol;
	pair<int, int> pos = { this->get_position_x(), this->get_position_y() };
	int col = this->get_color() == Color::white ? 1 : -1;
	//pos 1
	pos.first += 1;
	pos.second += 2;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	//pos 2
	pos.first += 1;
	pos.second -= 1;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	//pos 3
	pos.second -= 2;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	//pos 4
	pos.first -= 1;
	pos.second -= 1;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	//pos 5
	pos.first -= 2;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	//pos 6
	pos.first -= 1;
	pos.second += 1;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	//pos 7
	pos.second += 2;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	//pos 8
	pos.first += 1;
	pos.second += 1;
	if (can_attack(pos.first, pos.second, col, cb))
		sol.push_back(pos);
	return sol;
}
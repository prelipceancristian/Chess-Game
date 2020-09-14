#include "Rook.h"
vector<pair<int, int>> Rook::moves()
{
	int pos_x = this->get_position_x();
	int pos_y = this->get_position_y();
	vector<pair<int, int>> sol;
	for (int i = 0; i < 8; i++)
		sol.push_back({ pos_x, i });
	for (int i = 0; i < 8; i++)
		sol.push_back({ i, pos_y });
	sol.erase(sol.begin() + pos_y);
	sol.erase(sol.begin() + pos_x + 7);
	return sol;
}
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
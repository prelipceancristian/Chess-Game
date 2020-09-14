#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

vector<pair<int, int>> Queen::moves()
{
	Rook rook = Rook{ 1, this->get_position_x(), this->get_position_y(), Color::black };
	Bishop bishop = Bishop{ 1, this->get_position_x(), this->get_position_y(), Color::black };
	vector<pair<int, int>> sol1 = rook.moves();
	vector<pair<int, int>> sol2 = bishop.moves();
	for (int i = 0; i < sol2.size(); i++)
	{
		auto it = std::find(sol1.begin(), sol1.end(), sol2[i]);
		if (it == sol1.end())
			sol1.push_back(sol2[i]);
	}
	return sol1;
}
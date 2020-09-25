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
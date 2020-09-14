#include "Pawn.h"
vector<pair<int, int>> Pawn::moves()
{
	vector<pair<int, int>> sol;
	sol.push_back({this->get_position_x(), this->get_position_y() + 1}); // move up one place
	return sol;
}
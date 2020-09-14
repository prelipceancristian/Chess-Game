#include "Bishop.h"

vector<pair<int, int>> Bishop::moves() 
{
	//kinda retarded approach but should work just fine for an 8x8 chess board
	vector<pair<int, int>> sol;
	int x_coord = this->get_position_x();
	int y_coord = this->get_position_y();
	//right up
	while (x_coord < 7 && y_coord < 7)
		sol.push_back({ ++x_coord, ++y_coord });
	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	//right down
	while (x_coord < 7 && y_coord > 0)
		sol.push_back({ ++x_coord, --y_coord });
	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	//left up
	while (x_coord > 0 && y_coord < 7)
		sol.push_back({ --x_coord, ++y_coord });
	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	//left down
	while (x_coord > 0 && y_coord > 0)
		sol.push_back({ --x_coord, --y_coord });
	
	return sol;
}
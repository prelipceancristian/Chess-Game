#include "Bishop.h"

vector<pair<int, int>> Bishop::moves(ChessBoard cb) 
{
	//kinda retarded approach but should work just fine for an 8x8 chess board
	vector<pair<int, int>> sol;
	int x_coord = this->get_position_x();
	int y_coord = this->get_position_y();
	//right up
	while (x_coord < 7 && y_coord < 7)
		if (cb.is_empty(x_coord + 1, y_coord + 1))
			sol.push_back({ ++x_coord, ++y_coord });
		else
			break;
	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	//right down
	while (x_coord < 7 && y_coord > 0)
		if (cb.is_empty(x_coord + 1, y_coord - 1))
			sol.push_back({ ++x_coord, --y_coord });
		else
			break;
	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	//left up
	while (x_coord > 0 && y_coord < 7)
		if (cb.is_empty(x_coord - 1, y_coord + 1))
			sol.push_back({ --x_coord, ++y_coord });
		else
			break;
	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	//left down
	while (x_coord > 0 && y_coord > 0)
		if (cb.is_empty(x_coord + 1, y_coord + 1))
			sol.push_back({ --x_coord, --y_coord });
		else
			break;
	
	return sol;
}

bool check_coords_lim(int x, int y)
{
	return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

vector<pair<int, int>> Bishop::attacks(ChessBoard cb)
{
	vector<pair<int, int>> sol;
	int col = this->color == Color::white ? 1 : -1;

	//right up
	int x_coord = this->get_position_x();//set up the original location of the search
	int y_coord = this->get_position_y();
	x_coord++;
	y_coord++;//first position when going right up
	while (check_coords_lim(x_coord, y_coord) && cb.is_empty(x_coord, y_coord)) 
	{
		x_coord++;
		y_coord++; // move right up until we re out of bounds or until we find a piece
	}
	if (check_coords_lim(x_coord, y_coord)) // if we haven't stopped do to going out of bounds
		if (col * cb.get_val_at_coord(x_coord, y_coord) == -1) // if the pieces have different colors
			sol.push_back({ x_coord, y_coord }); // add the location of the piece that can be taken

	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	x_coord++;
	y_coord--;
	while (check_coords_lim(x_coord, y_coord) && cb.is_empty(x_coord, y_coord))
	{
		x_coord++;
		y_coord--;
	}
	if (check_coords_lim(x_coord, y_coord))
		if (col * cb.get_val_at_coord(x_coord, y_coord) == -1)
			sol.push_back({ x_coord, y_coord });

	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	x_coord--;
	y_coord--;
	while (check_coords_lim(x_coord, y_coord) && cb.is_empty(x_coord, y_coord))
	{
		x_coord--;
		y_coord--;
	}
	if (check_coords_lim(x_coord, y_coord))
		if (col * cb.get_val_at_coord(x_coord, y_coord) == -1)
			sol.push_back({ x_coord, y_coord });

	x_coord = this->get_position_x();
	y_coord = this->get_position_y();
	x_coord--;
	y_coord++;
	while (check_coords_lim(x_coord, y_coord) && cb.is_empty(x_coord, y_coord))
	{
		x_coord--;
		y_coord++;
	}
	if (check_coords_lim(x_coord, y_coord))
		if (col * cb.get_val_at_coord(x_coord, y_coord) == -1)
			sol.push_back({ x_coord, y_coord });

	return sol;
}
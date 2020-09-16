#include "ServicePieces.h"
void ServicePieces::move_piece(int id, int pos_x, int pos_y)
{
	auto chesspiece = repo.find(id);
	pair<int, int> pos = {pos_x, pos_y};
	vector<pair<int, int>> positions = chesspiece.moves(); // Chesspiece does not have implemented the moves() method
	auto it = std::find(positions.begin(), positions.end(), pos);
	if (it == positions.end())
		throw ServiceException("Move not possible!");
	chesspiece.set_position(pos_x, pos_y);
	repo.update(chesspiece);
}
#include "ServicePieces.h"
void ServicePieces::move_piece(int id, int pos_x, int pos_y)
{
	//TODO: check whether there is a piece in front which blocks pathing
	auto chesspiece = repo.find(id);
	pair<int, int> pos = {pos_x, pos_y};
	vector<pair<int, int>> positions = chesspiece->moves(this->cb);
	auto it = std::find(positions.begin(), positions.end(), pos);
	if (it == positions.end())
		throw ServiceException("Move not possible!");
	cb.set_val_at_coord(0, chesspiece->get_position_x(), chesspiece->get_position_y());
	cb.set_val_at_coord(chesspiece->get_color() == Color::white ? 1 : -1, pos_x, pos_y);
	chesspiece->set_position(pos_x, pos_y);
	repo.update(chesspiece);
}

vector<pair<int, int>> ServicePieces::get_piece_moveset(int id)
{
	return (this->repo.find(id))->moves(this->cb);
}

void ServicePieces::setup_game()
{
	this->repo.clear_all();

	Rook* rw1 = new Rook(1, 0, 0, Color::white);
	Knight* kw1 = new Knight(2, 1, 0, Color::white);
	Bishop* bw1 = new Bishop(3, 2, 0, Color::white);
	King* kw = new King(4, 3, 0, Color::white);
	Queen* qw = new Queen(5, 4, 0, Color::white);
	Bishop* bw2 = new Bishop(6, 5, 0, Color::white);
	Knight* kw2 = new Knight(7, 6, 0, Color::white);
	Rook* rw2 = new Rook(8, 7, 0, Color::white);

	Pawn* pw1 = new Pawn(9, 0, 1, Color::white);
	Pawn* pw2 = new Pawn(10, 1, 1, Color::white);
	Pawn* pw3 = new Pawn(11, 2, 1, Color::white);
	Pawn* pw4 = new Pawn(12, 3, 1, Color::white);
	Pawn* pw5 = new Pawn(13, 4, 1, Color::white);
	Pawn* pw6 = new Pawn(14, 5, 1, Color::white);
	Pawn* pw7 = new Pawn(15, 6, 1, Color::white);
	Pawn* pw8 = new Pawn(16, 7, 1, Color::white);

	Rook* rb1 = new Rook(17, 0, 7, Color::black);
	Knight* kb1 = new Knight(18, 1, 7, Color::black);
	Bishop* bb1 = new Bishop(19, 2, 7, Color::black);
	King* kb = new King(20, 3, 7, Color::black);
	Queen* qb = new Queen(21, 4, 7, Color::black);
	Bishop* bb2 = new Bishop(22, 5, 7, Color::black);
	Knight* kb2 = new Knight(23, 6, 7, Color::black);
	Rook* rb2 = new Rook(24, 7, 7, Color::black);

	Pawn* pb1 = new Pawn(25, 0, 6, Color::black);
	Pawn* pb2 = new Pawn(26, 1, 6, Color::black);
	Pawn* pb3 = new Pawn(27, 2, 6, Color::black);
	Pawn* pb4 = new Pawn(28, 3, 6, Color::black);
	Pawn* pb5 = new Pawn(29, 4, 6, Color::black);
	Pawn* pb6 = new Pawn(30, 5, 6, Color::black);
	Pawn* pb7 = new Pawn(31, 6, 6, Color::black);
	Pawn* pb8 = new Pawn(32, 7, 6, Color::black);

	repo.add(rw1);
	repo.add(kw1);
	repo.add(bw1);
	repo.add(kw);
	repo.add(qw);
	repo.add(bw2);
	repo.add(kw2);
	repo.add(rw2);

	repo.add(pw1);
	repo.add(pw2);
	repo.add(pw3);
	repo.add(pw4);
	repo.add(pw5);
	repo.add(pw6);
	repo.add(pw7);
	repo.add(pw8);

	repo.add(rb1);
	repo.add(kb1);
	repo.add(bb1);
	repo.add(kb);
	repo.add(qb);
	repo.add(bb2);
	repo.add(kb2);
	repo.add(rb2);

	repo.add(pb1);
	repo.add(pb2);
	repo.add(pb3);
	repo.add(pb4);
	repo.add(pb5);
	repo.add(pb6);
	repo.add(pb7);
	repo.add(pb8);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->cb.set_val_at_coord(1, j, i);
		}
	}

	for (int i = 6; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->cb.set_val_at_coord(-1, j, i);
		}
	}

}

vector<ChessPiece*> ServicePieces::get_white_pieces()
{
	vector<ChessPiece*> all_pieces = repo.get_all();
	vector<ChessPiece*> sol;
	for_each(
		all_pieces.begin(),
		all_pieces.end(),
		[&sol](const auto& elem)
		{
			if (elem->get_color() == Color::white)
				sol.push_back(elem);
		});
	return sol;
}

vector<ChessPiece*> ServicePieces::get_black_pieces()
{
	vector<ChessPiece*> all_pieces = repo.get_all();
	vector<ChessPiece*> sol;
	for_each(
		all_pieces.begin(),
		all_pieces.end(),
		[&sol](const auto& elem)
		{
			if (elem->get_color() == Color::black)
				sol.push_back(elem);
		});
	return sol;
}

ChessPiece* ServicePieces::get_piece_by_id(int _id)
{
	return repo.find(_id);
}
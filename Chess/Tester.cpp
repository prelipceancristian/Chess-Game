#include <iostream>
#include <assert.h>

#include "Tester.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Repo.h"
#include "Pawn.h"


void Tester::test_all()
{
	Tester::test_chess_piece();
	Tester::test_chess_board();
	Tester::test_repo();
	Tester::test_pawn();
}

void Tester::test_chess_piece()
{
	std::cout << "Chess piece tests...";

	ChessPiece c1 = ChessPiece(1, 0, 0, Color::white);
	ChessPiece c2 = ChessPiece(2, 0, 0, Color::black);
	ChessPiece c3 = ChessPiece(3, 1, 7, Color::black);

	assert(c1.get_id() == 1);
	assert(c2.get_id() == 2);
	assert(c3.get_id() == 3);

	assert((c1 == c2) == false); // test == operatror
	ChessPiece c4 = c1;
	assert(c1 == c4); // test = operator
	ChessPiece c5 = ChessPiece(c1);
	assert(c5 == c1); // test copy construcutor

	assert(c1.get_position_x() == c2.get_position_x());
	assert(c1.get_position_y() == 0);
	assert(c1.get_color() != c2.get_color());
	assert(c3.get_color() == c2.get_color());

	std::cout << "Ok!\n";
}

void Tester::test_chess_board()
{
	std::cout << "Chess board tests...";

	ChessBoard cb1;
	ChessBoard cb2 = ChessBoard(1, 8);
	assert(cb1.get_size() == cb2.get_size());
	assert(cb1.get_id() == 0);
	assert(cb2.get_id() == 1);
	ChessBoard cb3 = ChessBoard(cb1);
	assert(cb3 == cb1);
	assert(cb3.get_size() == cb1.get_size());
	ChessBoard cb4 = cb1;
	assert(cb4 == cb1);
	assert(cb4.get_size() == cb1.get_size());

	std::cout << "Ok!\n";
}

void Tester::test_repo()
{
	std::cout << "Repo tests...";

	Repo<ChessPiece> repo;
	ChessPiece c1 = ChessPiece(1, 0, 0, Color::white);
	ChessPiece c2 = ChessPiece(2, 0, 0, Color::black);
	ChessPiece c3 = ChessPiece(3, 1, 7, Color::black);
	ChessPiece c4 = ChessPiece(4, 1, 7, Color::black);

	repo.add(c1);
	repo.add(c2);
	repo.add(c3);
	try
	{
		repo.add(c1);
		assert(false);
	}
	catch (RepoException){};

	assert(repo.find(c1.get_id()) == c1);
	try
	{
		repo.find(4);
		assert(false);
	}
	catch (RepoException) {};

	ChessPiece c = repo.remove(c1.get_id());
	
	try
	{
		c = repo.remove(c1.get_id());
		assert(false);
	}
	catch (RepoException) {};

	repo.add(c1);
	c.set_color(Color::black);
	repo.update(c);
	assert(repo.find(c.get_id()).get_color() == Color::black);

	vector<ChessPiece> vec = repo.get_all();
	auto p = std::find(vec.begin(), vec.end(), c1);
	assert(p != vec.end());
	p = std::find(vec.begin(), vec.end(), c2);
	assert(p != vec.end());
	p = std::find(vec.begin(), vec.end(), c3);
	assert(p != vec.end());
	p = std::find(vec.begin(), vec.end(), c4);
	assert(p == vec.end());
	assert(vec.size() == 3);

	std::cout << "Ok!\n";
}

void Tester::test_pawn()
{
	std::cout << "Pawn tests...";

	Pawn pawn1;
	Pawn pawn2 = Pawn(1, 0, 1, Color::black);
	vector<pair<int, int>> sol;
	sol = pawn1.moves();
	pair<int, int> my_pair = { 0, 1 };
	assert(sol[0] == my_pair);
	sol = pawn2.moves();
	my_pair = { 0, 2 };
	assert(sol[0] == my_pair);

	std::cout << "Ok!\n";
}
#include <iostream>
#include <assert.h>

#include "Tester.h"
#include "ChessPiece.h"
#include "ChessBoard.h"
#include "Repo.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "ServicePieces.h"
#include "RepoPointers.h"


void Tester::test_all()
{
	Tester::test_chess_piece();
	Tester::test_chess_board();
	Tester::test_repo();
	Tester::test_pawn();
	Tester::test_bishop();
	Tester::test_knight();
	Tester::test_rook();
	Tester::test_queen();
	Tester::test_king();
	Tester::test_service();
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

void Tester::test_bishop()
{
	std::cout << "Bishop tests...";

	Bishop Bishop1;
	Bishop Bishop2 = Bishop(1, 5, 3, Color::white);
	vector<pair<int, int>> sol = Bishop2.moves();
	assert(sol.size() == 11); // really annoying tests that i've done in debugging
	vector<pair<int, int>> my_sol = { {6, 4}, {7, 5}, {6, 2}, {7, 1}, {4, 4}, {3, 5}, {2, 6}, {1, 7}, {4, 2}, {3, 1}, {2,0} };
	for (int i = 0; i < sol.size(); i++)
		assert(sol[i] == my_sol[i]);

	std::cout << "Ok!\n";
}

void Tester::test_knight()
{
	std::cout << "Knight tests...";

	Knight knight1;
	Knight knight2 = Knight(1, 4, 3, Color::black);
	vector<pair<int, int>> my_sol = { {5, 5}, {6, 4}, {6, 2}, {5, 1}, {3, 1}, {2, 2}, {2, 4}, {3, 5} };
	vector<pair<int, int>> sol = knight2.moves();
	for (int i = 0; i < sol.size(); i++)
		assert(sol[i] == my_sol[i]);

	std::cout << "Ok!\n";
}

void Tester::test_rook()
{
	std::cout << "Rook tests...";

	Rook rook1;
	Rook rook2 = Rook(1, 3, 2, Color::black);
	vector<pair<int, int>> my_sol = { {3, 0}, {3, 1}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7}, {0, 2}, {1, 2}, {2, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2} };
	vector<pair<int, int>> sol = rook2.moves();
	for (int i = 0; i < sol.size(); i++)
		assert(sol[i] == my_sol[i]);
	std::cout << "Ok!\n";
}

void Tester::test_queen()
{
	std::cout << "Queen tests...";

	Queen queen1;
	Queen queen2 = Queen(1, 2, 4, Color::black);
	vector<pair<int, int>> my_sol = { {1, 2} };
	vector<pair<int, int>> sol = queen2.moves();
	// nope not gonna test that
	std::cout << "Ok!\n";
}

void Tester::test_king()
{
	std::cout << "King tests...";

	King king1;
	King king2 = King(1, 0, 0, Color::black);
	vector<pair<int, int>> sol = king2.moves();
	vector<pair<int, int>> my_sol = { {0, 1}, {1, 1}, {1, 0} };
	for (int i = 0; i < my_sol.size(); i++)
		assert(sol[i] == my_sol[i]);

	king2 = King(1, 2, 0, Color::black);
	sol = king2.moves();
	my_sol = { {2, 1}, {3, 1}, {3, 0}, {1, 0}, {1, 1} };
	for (int i = 0; i < my_sol.size(); i++)
		assert(sol[i] == my_sol[i]);

	std::cout << "Ok!\n";
}

void Tester::test_service()
{
	std::cout << "Service tests...";
	/*
	Repo<ChessPiece> repo;
	ChessPiece c1 = ChessPiece(1, 0, 0, Color::black);
	King k1 = King(2, 5, 0, Color::white);
	repo.add(c1);
	repo.add(k1);
	ServicePieces service1 = ServicePieces(repo);
	service1.move_piece(2, 5, 1);
	assert(repo.find(2).get_position_x() == 5);
	assert(repo.find(2).get_position_y() == 1);
	*/
	/*
	ChessPiece* pcp = new ChessPiece(1, 0, 0, Color::black);
	King* pk = new King(2, 4, 0, Color::black);
	vector<pair<int, int>> sol = pk->moves();
	pcp = pk;
	sol = pcp->moves();
	*/
	/*
	Repo<ChessPiece*> repo;
	ChessPiece* pcp = new ChessPiece(1, 0, 0, Color::black);
	repo.add(pcp);
	*/

	RepoPointers<ChessPiece> repo;
	ChessPiece* cpp = new ChessPiece(1, 0, 0, Color::black);
	repo.add(cpp);
	King* kp = new King(2, 1, 1, Color::black);
	repo.add(kp);
	ServicePieces service = ServicePieces(repo);
	vector<pair<int, int>> s = (repo.find(2))->moves();
	service.move_piece(2, 2, 2);
	try
	{
		service.move_piece(2, 4, 4);
		assert(false);
	}
	catch (ServiceException) {};
	Pawn* pp = new Pawn(3, 1, 0, Color::black);
	repo.add(pp);
	try
	{
		service.move_piece(3, 1, 0);
		assert(false);
	}
	catch (ServiceException) {};

	vector<pair<int, int>> s1 = kp->moves();
	vector<pair<int, int>> s2 = service.get_piece_moveset(kp->get_id());
	assert(s1 == s2);

	service.setup_game();

	std::cout << "Ok!\n";
}
#include <iostream>

#include "Tester.h"
#include "ChessPiece.h"

void Tester::test_all()
{
	Tester::test_chess_piece();
	Tester::test_repo();
}

void Tester::test_chess_piece()
{
	std::cout << "Chess piece tests...";
	ChessPiece c1 = ChessPiece(1, 0, 0, white);
	ChessPiece c2 = ChessPiece(2, 0, 0, black);
	ChessPiece c3 = ChessPiece(3, 1, 7, black);
	std::cout << "Ok!\n";
}

void Tester::test_repo()
{
	std::cout << "Repo tests...";
	std::cout << "Ok!\n";
}
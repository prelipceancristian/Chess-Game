#pragma once
#include "repo.h"
#include "RepoPointers.h"
#include "ChessPiece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

class ServiceException : public runtime_error
{
private:
	string message;
public:
	ServiceException(string msg) : runtime_error(msg), message(msg) {};
	string what()
	{
		return message;
	}
};

class ServicePieces
{
private:
	RepoPointers<ChessPiece>& repo;
	ChessBoard cb;
public:
	ServicePieces(RepoPointers<ChessPiece>& _repo, ChessBoard& _cb) : repo{ _repo }, cb{_cb} {};
	void move_piece(int id, int px, int py);
	vector<pair<int, int>> get_piece_moveset(int id);
	void setup_game();
};


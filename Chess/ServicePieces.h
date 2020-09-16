#pragma once
#include "repo.h"
#include "ChessPiece.h"

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
	Repo<ChessPiece>& repo;
public:
	ServicePieces(Repo<ChessPiece>& _repo) : repo{ _repo } {};
	void move_piece(int id, int px, int py);
	void get_piece_moveset(int id);
	void setup_game();
};


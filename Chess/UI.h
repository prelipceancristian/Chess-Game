#pragma once
#include "ServicePieces.h"

class UI
{
private:
	ServicePieces service;
public:
	UI(ServicePieces& _service) : service{ _service } {};
	void run_ui();
	void show_menu();
	void greeting();
	void start_game();
	void show_menu_game();
	void show_all_pieces(bool);
};


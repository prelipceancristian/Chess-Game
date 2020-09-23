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
};


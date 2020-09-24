#include <iostream>

using std::cout;
using std::cin;

#include "UI.h"
void UI::run_ui()
{
	bool run = true;
	bool show_greeting = true;
	while (run)
	{
		char choice;
		if (show_greeting)
		{
			greeting();
			show_greeting = false;
		}
		show_menu();
		cout << "Your choice:";
		cin >> choice;
		switch (choice)
		{
		case 'x':
		{
			cout << "Goodbye!\n";
			run = false;
			break;
		}
		case '1':
		{
			start_game();
			break;
		}
		default:
		{
			cout << "Invalid choice! Please introduce a valid character.\n";
			break;
		}
		}
	}
}

void UI::greeting()
{
	cout << "Hello!\n";
	cout << "This is a very basic chess game done to review my oop skills because I got bored one day.\n";
	cout << "Hope you'll enjoy this little project!\n";
}

void UI::show_menu()
{
	cout << "________________________________________________\n";
	cout << "                     -Menu-\n";
	cout << "1. Start game\n";
	cout << "x. Exit\n";
}

void UI::show_all_pieces(bool color_white)
{
	vector<ChessPiece*> pieces;
	if (color_white)
		pieces = service.get_white_pieces();
	else
		pieces = service.get_black_pieces();
	for_each(pieces.begin(), pieces.end(), [&pieces](const auto& elem)
		{
			cout << *elem << "\n";
		});

}

void UI::show_menu_game()
{
	cout << "1. Show all pieces\n";
}

void UI::start_game()
{
	cout << "Starting game..\n\n";
	service.setup_game();
	bool white_turn = true;
	bool done = false;
	while (!done)
	{
		if (white_turn)
		{
			cout << "White's turn!\n";
			bool end_turn = false;
			while (!end_turn)
			{
				show_menu_game();
				char op;
				cout << "Your option: ";
				cin >> op;
				switch (op)
				{
				case '1':
				{
					show_all_pieces(true);
					break;
				}
				default:
				{
					cout << "Invalid character!\n";
					break;
				}
				}
			}

		}
		else
		{
			cout << "Black's turn!\n";
			bool end_turn = false;
			while (!end_turn)
			{
				show_menu_game();
				char op;
				cout << "Your option: ";
				cin >> op;
				switch (op)
				{
				case '1':
				{
					show_all_pieces(false);
					break;
				}
				default:
				{
					cout << "Invalid character!\n";
					break;
				}
				}
			}

		}
		white_turn = !white_turn;
	}
}

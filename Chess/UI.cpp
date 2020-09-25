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
	cout << "2. See piece moveset\n";
	cout << "3. Move a piece\n";
}

void UI::turn(bool is_white)
{
	cout << (is_white ? "White's turn!\n" : "Black's turn!\n");
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
			show_all_pieces(is_white);
			break;
		}
		case '2':
		{
			handle_moveset();
			break;
		}
		case '3':
		{
			handle_move(is_white, end_turn);
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

void UI::start_game()
{
	cout << "Starting game..\n\n";
	service.setup_game();
	bool white_turn = true;
	bool done = false;
	while (!done)
	{
		turn(white_turn);
		white_turn = !white_turn;
	}
}

void UI::handle_move(bool is_white_turn, bool& ended_turn)
{
	try
	{
		int id;
		cout << "Select the chess piece id: ";
		cin >> id;
		ChessPiece* piece = service.get_piece_by_id(id);
		if (is_white_turn == ((*piece).get_color() == Color::white))
		{
			//show_list_of_coords(service.get_piece_moveset(id));
			char x;
			int y, xx;
			cout << "Enter the x coordonate(A-H): ";
			cin >> x;
			cout << "Enter the y coordonate(1-8): ";
			cin >> y;
			xx = int(x) - 65;
			y--;
			service.move_piece(id, xx, y);
			cout << "Done!\n";
			ended_turn = true;
		}
		else
		{
			cout << "This piece is not yours, as your color is " << (is_white_turn ? "white" : "black") << " and the piece color is "
				<< (is_white_turn ? "black." : "white.") << "\n";
		}
	}
	catch (RepoException re)
	{
		cout << "ERROR! " << re.what() << "\n";
	}
	catch (ServiceException se) {
		cout << "ERROR! " << se.what() << "\n";
	};
}

void UI::show_list_of_coords(vector<pair<int, int>> list)
{
	if (list.size() == 0)
		cout << "Can't act with this piece!\n";
	else
	{
		for_each(list.begin(), list.end(), [](const auto& elem) {
			cout << char(elem.first + 65) << elem.second + 1 << "\n";
		});
	}
}

void UI::handle_moveset()
{
	try
	{
		int id;
		cout << "Enter the piece id: ";
		cin >> id;
		vector<pair<int, int>> mov = service.get_piece_moveset(id);
		if (mov.size() != 0)
			cout << "Here are your possible moves:\n";
		show_list_of_coords(mov);
	}
	catch (RepoException re)
	{
		cout << "ERROR! " << re.what() << "\n";
	}
	catch (ServiceException se) {
		cout << "ERROR! " << se.what() << "\n";
	};
}
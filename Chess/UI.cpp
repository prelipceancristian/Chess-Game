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
	cout << "x. Exit\n";
}

#include "Home.h"

//Prints the contents of the webpage
void Home::print()
{
	system("CLS");
	std::cout << "Welcome to the Homepage.";
	std::cout << "\n\n1. Browse rooms.";
	std::cout << "\n2. Log out";
	std::cout << "\n\nPlease make your selection: ";
}

// Handles the users inputs on the site.
void Home::input(int input, AbstractPage** page)
{
	AbstractPage* p = *page;
	switch (input)
	{
	case 1:
		system("CLS");
		*page = new mainPage(user);
		delete p;
		break;
	case 2:
		system("CLS");
		delete user;
		*page = new Access();
		delete p;
		break;
	default:
		system("CLS");
		std::cout << "Please select a valid option \n\n";
		system("Pause");
		system("CLS");
		break;
	}
}
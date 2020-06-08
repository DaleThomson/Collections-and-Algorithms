#include "Login.h"

void Login::print()
{
	system("CLS");
	std::cout << "Are you logging in as a user or an employee?\n\n";
	std::cout << "1. User\n";
	std::cout << "2. Employee";
	std::cout << "\n\nPlease enter your selection: ";
}

void Login::input(int input, AbstractPage** page)
{
	AbstractPage* p = *page;
	switch (input)
	{
	case 1:
		system("CLS");
		std::cout << "Welcome User";
		std::cout << "\n\nPlease enter your username";
		std::cout << "\n\nEnter here: ";
		std::cin >> username;
		std::cout << "\nPlease enter your password";
		std::cout << "\n\nEnter here: ";
		std::cin >> password;
		user = new User();
		user->login(username, password);
		*page = new Home(user);
		break;
	case 2:
		system("CLS");
		std::cout << "Welcome Employee";
		std::cout << "\n\nPlease enter your username";
		std::cout << "\n\nEnter here: ";
		std::cin >> username;
		std::cout << "\nPlease enter your password";
		std::cout << "\n\nEnter here: ";
		std::cin >> password;
		employee = new Employee();
		employee->login(username, password);
		break;
	default:
		system("CLS");
		std::cout << "Please select a valid option \n\n";
		system("Pause");
		system("CLS");
		break;
	}
	delete p;
}
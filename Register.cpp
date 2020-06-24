#include "Register.h"

void Register::print()
{
	system("CLS");
	std::cout << "Are you registering a user or an employee?\n\n";
	std::cout << "1. User\n";
	std::cout << "2. Employee";
	std::cout << "\n\nPlease enter your selection: ";
}

void Register::input(int input, AbstractPage** page)
{
	AbstractPage* p = *page;
	switch (input)
	{
	case 1:
		system("CLS");
		std::cout << "Please enter your desired username";
		std::cout << "\n\nEnter here: ";
		std::cin >> username;
		std::cout << "\nPlease enter your desired password";
		std::cout << "\n\nEnter here: ";
		std::cin >> password;
		user = new User();
		user->registerUser(username, password);
		*page = new Home(user);
		delete p;
		break;
	case 2:
		system("CLS");
		std::cout << "Please enter your desired username";
		std::cout << "\n\nEnter here: ";
		std::cin >> username;
		std::cout << "\nPlease enter your desired password";
		std::cin >> password;
		employee = new Employee();
		employee->registerEmployee(username, password);
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
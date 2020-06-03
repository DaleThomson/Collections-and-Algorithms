#include <iostream>
#include <fstream>
#include "User.h"
#include "Employee.h"
int main()
{
	User* user = new User;
	Employee* employee = new Employee;
	std::string userName, password;
	int input;
	bool run = true;
	
	while (run)
	{
		std::cout << "Please select a valid option: \n\n";
		std::cout << "1. Register Account\n";
		std::cout << "2. Login";
		std::cout << "\n\nYour selection: ";
		std::cin >> input;
		system("CLS");
		switch (input)
		{
		case 1:
			std::cout << "Are you registering a user or an employee?\n\n";
			std::cout << "1. User\n";
			std::cout << "2. Employee";
			std::cout << "\n\nPlease enter your selection: ";
			std::cin >> input;
			system("CLS");
			switch (input)
			{
			case 1:
				std::cout << "Please enter your desired username";
				std::cout << "\n\nEnter here: ";
				std::cin >> userName;
				std::cout << "\nPlease enter your desired password";
				std::cout << "\n\nEnter here: ";
				std::cin >> password;
				user->registerUser(userName, password);
				break;
			case 2:
				std::cout << "Please enter your desired username";
				std::cout << "\n\nEnter here: ";
				std::cin >> userName;
				std::cout << "\nPlease enter your desired password";
				std::cin >> password;
				employee->registerEmployee(userName, password);
				break;
			}
			break;
		case 2:
			std::cout << "Are you logging in as a user or an employee?\n\n";
			std::cout << "1. User\n";
			std::cout << "2. Employee";
			std::cout << "\n\nPlease enter your selection: ";
			std::cin >> input;
			system("CLS");
			switch (input)
			{
			case 1:
				std::cout << "Welcome User";
				std::cout << "\n\nPlease enter your username";
				std::cout << "\n\nEnter here: ";
				std::cin >> userName;
				std::cout << "\nPlease enter your password";
				std::cout << "\n\nEnter here: ";
				std::cin >> password;
				user->login(userName, password);
				break;
			case 2:
				std::cout << "Welcome Employee";
				std::cout << "\n\nPlease enter your username";
				std::cout << "\n\nEnter here: ";
				std::cin >> userName;
				std::cout << "\nPlease enter your password";
				std::cout << "\n\nEnter here: ";
				std::cin >> password;
				employee->login(userName, password);
				break;
			}
			break;
		default:
			system("CLS");
			std::cout << "Please select a valid option \n\n";
			system("Pause");
			system("CLS");
			break;
		}
	}
	return 0;
}
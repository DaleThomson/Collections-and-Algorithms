#include <iostream>
#include <fstream>
#include "User.h"
int main()
{
	User* user = new User;
	std::string userName, password;
	int input;
	bool run = true;
	while (run)
	{
		std::cout << "Please select a valid option: \n\n";
		std::cout << "1. Register User";
		std::cout << "\n\nYour selection: ";
		std::cin >> input;
		switch (input)
		{
		case 1:
			std::cout << "Please enter your desired username: \n";
			std::cin >> userName;
			std::cout << "\nPlease enter your desired password: \n";
			std::cin >> password;
			user->registerUser(userName, password);
			system("CLS");
			std::cout << "User successfully registered \n\n";
			system("Pause");
			system("CLS");
			break;
		default:
			system("CLS");
			break;
		}
	}
	return 0;
}
#include "Employee.h"

//This method registers an Employee account by saving the details to a txt file.
void Employee::registerAccount(std::string inUsername, std::string inPassword)
{
	authenticate.open("employeeList.txt");
	int verify = 0;
	if (authenticate)
	{
		while (std::getline(authenticate, username, ' '))
		{
			if (username == inUsername)
			{
				system("CLS");
				std::cout << "This username is already taken \n\n";
				system("PAUSE");
				system("CLS");
				std::cout << "Please re-enter your details.";
				std::cout << "\n\nPlease enter your username: ";
				std::cin >> inUsername;
				std::cout << "\nPlease enter your password: ";
				std::cin >> inPassword;
				authenticate.close();
				registerAccount(inUsername, inPassword);
				break;
			}
			else if (username != inUsername)
			{
				system("CLS");
				authenticate.close();
				employeeList.open("employeeList.txt", std::fstream::out | std::fstream::app);
				employeeList << inUsername << " ";
				employeeList << inPassword;
				employeeList << "\n";
				employeeList.close();
				username = inUsername;
				password = inPassword;
				break;
			}
		}
	}
}
//This method allows the user to login to a pre-existing employee account by parsing the txt file.
void Employee::login(std::string inUserName, std::string inPassword)
{
	authenticate.open("employeeList.txt");

	if (authenticate)
	{
		while (std::getline(authenticate, username, ' ') && (std::getline(authenticate, password)))
		{
			if (username == inUserName && password == inPassword)
			{
				system("CLS");
				std::cout << "Employee found\n\n";
				system("PAUSE");
				system("CLS");
				username = inUserName;
				password = inPassword;
				break;
			}
		}
		if (username != inUserName || password != inPassword)
		{
			system("CLS");
			std::cout << "Login failed\n\n";
			system("PAUSE");
			system("CLS");
			std::cout << "Please re-enter your details.";
			std::cout << "\n\nPlease enter your username: ";
			std::cin >> inUserName;
			std::cout << "\nPlease enter your password: ";
			std::cin >> inPassword;
			authenticate.close();
			login(inUserName, inPassword);
		}
	}
}
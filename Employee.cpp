#include "Employee.h"

//This method registers an Employee account by saving the details to a txt file.
void Employee::registerAccount(std::string username, std::string password)
{
	employeeList.open("employeeList.txt", std::fstream::out | std::fstream::app);
	employeeList << username << " ";
	employeeList << password;
	employeeList << "\n";
	employeeList.close();
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
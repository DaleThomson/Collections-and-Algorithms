#include "Employee.h"


void Employee::registerEmployee(std::string username, std::string password)
{
	employeeList.open("employeeList.txt", std::fstream::out | std::fstream::app);
	employeeList << username << " ";
	employeeList << password;
	employeeList << "\n";
	employeeList.close();
}

void Employee::login(std::string inUserName, std::string inPassword)
{
	authenticate.open("employeeList.txt");

	if (authenticate)
	{
		while (std::getline(authenticate, username, ' ') && (std::getline(authenticate, password)))
		{
			if (username == inUserName && password == inPassword)
			{
				std::cout << "\n\Employee found\n\n";
				system("PAUSE");
				system("CLS");
				break;
			}
		}
		if (username != inUserName || password != inPassword)
		{
			std::cout << "\nLogin failed\n\n";
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
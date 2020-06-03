#include "Employee.h"


void Employee::registerEmployee(std::string userName, std::string password)
{
	employeeList.open("employeeList.txt", std::fstream::out | std::fstream::app);
	employeeList << userName << " ";
	employeeList << password;
	employeeList << "\n";
	employeeList.close();
}

void Employee::login(std::string inUserName, std::string inPassword)
{
	authenticate.open("employeeList.txt");

	if (authenticate)
	{
		while (std::getline(authenticate, userName, ' ') && (std::getline(authenticate, password)))
		{
			if (userName == inUserName && password == inPassword)
			{
				std::cout << "\n\Employee found\n\n";
				system("PAUSE");
				system("CLS");
				break;
			}
		}
		if (userName != inUserName || password != inPassword)
		{
			std::cout << "\nLogin failed\n\n";
			system("PAUSE");
			system("CLS");
		}
	}
}
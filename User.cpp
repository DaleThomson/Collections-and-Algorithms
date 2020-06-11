#include "User.h" 

void User::registerUser(std::string inUserName, std::string inPassword)
{
	userList.open("userList.txt", std::fstream::out | std::fstream::app);
	userList << inUserName << " ";
	userList << inPassword;
	userList << "\n";
	userList.close();
	username = inUserName;
	password = inPassword;
}

void User::login(std::string inUserName, std::string inPassword)
{
	authenticate.open("userList.txt");

	if (authenticate)
	{
		while (std::getline(authenticate, username, ' ') && (std::getline(authenticate, password)))
		{
			if (username == inUserName && password == inPassword)
			{
				std::cout << "\n\nUser found\n\n";
				system("PAUSE");
				system("CLS");
				username = inUserName;
				password = inPassword;
				break;
			}
			else
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
				break;
			}
		}
	}
}
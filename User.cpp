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
		}
		if (username != inUserName || password != inPassword)
		{
			std::cout << "\nLogin failed\n\n";
			system("PAUSE");
			system("CLS");
		}
	}
}

void User::wee()
{
	std::cout << username << std::endl;
	std::cout << password << std::endl;
}
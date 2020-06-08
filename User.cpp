#include "User.h" 

void User::registerUser(std::string username, std::string password)
{
	userList.open("userList.txt", std::fstream::out | std::fstream::app);
	userList << username << " ";
	userList << password;
	userList << "\n";
	userList.close();
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
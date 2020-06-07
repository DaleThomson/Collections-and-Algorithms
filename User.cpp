#include "User.h" 

 User::User(std::string userName, std::string password)
{
	userList.open("userList.txt", std::fstream::out | std::fstream::app);
	userList << userName << " ";
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
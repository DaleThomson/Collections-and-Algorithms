#include "User.h" 

//Registers a new user account by storing the input data into a txt file.
void User::registerAccount(std::string inUserName, std::string inPassword)
{
	userList.open("userList.txt", std::fstream::out | std::fstream::app);
	userList << inUserName << " ";
	userList << inPassword;
	userList << "\n";
	userList.close();
	username = inUserName;
	password = inPassword;
}

//Allows the user to login to a pre-existing user account by checking the details against the txt tile.
void User::login(std::string inUserName, std::string inPassword)
{
	authenticate.open("userList.txt");

	if (authenticate)
	{
		while (std::getline(authenticate, username, ' ') && (std::getline(authenticate, password)))
		{
			if (username == inUserName && password == inPassword)
			{
				system("CLS");
				std::cout << "User found\n\n";
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
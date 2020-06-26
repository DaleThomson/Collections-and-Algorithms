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
//Prompts the user to accept the GDPR agreement. Sourced from this website : https://www.gdprprivacynotice.com/
void User::GDPR()
{
	char confirm;
	int check = 0;
	std::cout << "Please read and agree to our GDPR: https://www.gdprprivacynotice.com/live.php?token=wsrxYx4EICu2yJxHgADyC3mvTHaiOiyp";
	std::cout << "Please enter your decision: Y/N: ";
	std::cin >> confirm;
	while (check != 1)
	{
		switch (confirm)
		{
		case 'Y': case 'y':
			check = 1;
			break;
		case 'N': case 'n':
			system("CLS");
			std::cout << "Unfortunately agreeing to the GDPR is mandatory\n\n";
			system("PAUSE");
			exit (EXIT_FAILURE);
			break;
		default:
			system("CLS");
			std::cout << "Please select a valid option \n\n";
			system("Pause");
			system("CLS");
		}
	}
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
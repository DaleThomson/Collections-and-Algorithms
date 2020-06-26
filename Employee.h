#pragma once
#include "AbstractAccount.h"
class Employee : public AbstractAccount
{
private:
	std::string username, password; // Strings for storing the username and password.
	std::ofstream employeeList; // Used to take the strings and store them in a txt file.
	std::fstream authenticate; // Used to check the usernames and passwords of users to ensure they are correct.
public:
	Employee() {}

	void registerAccount(std::string username, std::string password); // This method stores the details for a new account in a text file.
	void login(std::string username, std::string password); // This method allows the user to log in to a pre-existing employee account stored in the text file.
};
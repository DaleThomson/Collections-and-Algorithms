#pragma once
#include "AbstractAccount.h"
class User : public AbstractAccount
{
private:
	std::string username, password; //Strings to store the username and password.
	std::ofstream userList; // Used to write the username and password to a txt file.
	std::fstream authenticate; // Parses the txt file to verify the username and password.
public:
	User() {} // Constructor
	void GDPR();
	void registerAccount(std::string username, std::string password); // A method used to register a users account
	void login(std::string username, std::string password); // A method used for logging into pre=existing accounts
};
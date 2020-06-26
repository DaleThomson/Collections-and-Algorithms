#pragma once
#include <iostream>
#include <string>
#include <fstream>
class AbstractAccount
{
public:
	virtual ~AbstractAccount(){} // Deconstructor

	virtual void registerAccount(std::string userName, std::string password) = 0; //A virtual void for creating accounts
	virtual void login(std::string username, std::string password) = 0; //A virtual void for logging into accounts.
};
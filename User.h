#pragma once
#include <iostream>
#include <string>
#include <fstream>


class User
{
private:
	std::string username, password;
	int currency = 0;
	std::ofstream userList;
	std::fstream authenticate;
public:
	User() {}
	void registerUser(std::string username, std::string password);
	void login(std::string username, std::string password);
	void depositCurrency(int addCurrency)
	{
		currency += addCurrency;
	}
};
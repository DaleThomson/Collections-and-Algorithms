#pragma once
#include <iostream>
#include <string>
#include <fstream>
class User
{
private:
	std::string userName, password;
	int currency;
	std::ofstream userList;
	std::fstream authenticate;
public:
	User() {}

	void registerUser(std::string userName, std::string password);
	void login(std::string userName, std::string password);
};

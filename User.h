#ifndef USER_H
#define USER_H
#pragma once
#include <iostream>
#include <string>
#include <fstream>


class User
{
private:
	std::string username, password;
	int currency;
	std::ofstream userList;
	std::fstream authenticate;
public:
	User(std::string username, std::string password);
	void login(std::string username, std::string password);
};

#endif

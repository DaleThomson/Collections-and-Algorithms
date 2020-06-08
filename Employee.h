#pragma once
#include <fstream>
#include <string>
#include <iostream>
class Employee
{
private:
	std::string username, password;
	std::ofstream employeeList;
	std::fstream authenticate;
public:
	Employee() {}

	void registerEmployee(std::string username, std::string password);
	void login(std::string username, std::string password);
};
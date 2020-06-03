#pragma once
#include <fstream>
#include <string>
#include <iostream>
class Employee
{
private:
	std::string userName, password;
	std::ofstream employeeList;
	std::fstream authenticate;
public:
	Employee() {}

	void registerEmployee(std::string userName, std::string password);
	void login(std::string userName, std::string password);
};
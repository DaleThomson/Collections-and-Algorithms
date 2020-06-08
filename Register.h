#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
#include "Home.h"
class Register : public AbstractPage
{
public:

	Register() {}

	virtual ~Register() {}

	void print();
	void input(int input, AbstractPage** page);
private:
	User* user;
	Employee* employee;
	Home* home;
	std::string username, password;
};
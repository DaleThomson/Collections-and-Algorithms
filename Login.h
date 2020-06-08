#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
#include "Home.h"
class Login : public AbstractPage
{
public:
	Login() {}

	virtual ~Login() {}

	void print();
	void input(int input, AbstractPage** page);
private:
	User* user;
	Employee* employee;
	Home* home;
	std::string username, password;
};
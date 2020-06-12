#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
#include "Home.h"
#include "EmployeeDash.h"
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
	std::string username, password;
};
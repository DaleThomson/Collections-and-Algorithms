#pragma once
#include "AbstractPage.h"
#include "User.h"
#include "Employee.h"
class Home : public AbstractPage
{
	Home(User* user) {}

	Home(Employee* employee) {}

	virtual ~Home() {}

	void print();
	void input(int input, AbstractPage** page);
};
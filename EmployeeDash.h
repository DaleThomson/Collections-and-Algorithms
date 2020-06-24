#pragma once
#include "AbstractPage.h"
#include "Employee.h"
#include "MainPage.h"
class EmployeeDash : public AbstractPage
{
private:
	Employee* employee;
public:
	EmployeeDash(Employee* employee) : employee(employee) {}

	virtual ~EmployeeDash() {}

	void print();
	void input(int input, AbstractPage** page);
};
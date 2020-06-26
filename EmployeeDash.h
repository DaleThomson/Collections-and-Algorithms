#pragma once
#include "AbstractPage.h"
#include "Employee.h"
#include "MainPage.h"
#include "Access.h";
class EmployeeDash : public AbstractPage
{
private:
	Employee* employee; //Pointer to th employee class
public:
	EmployeeDash(Employee* employee) : employee(employee) {} // Constructor

	virtual ~EmployeeDash() {} // Deconstructor

	void print(); // Prints the contents of the webpage
	void input(int input, AbstractPage** page); // Handles the inputs for this webpage
};